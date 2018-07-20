"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const vscode = require("vscode");
const converterplus_1 = require("./converterplus");
const _ = require("lodash");
const open = require("opener");
const util = require("util");
const path = require("path");
const myutil_1 = require("./myutil");
const file_1 = require("./file");
const everapi_1 = require("./everapi");
const config = vscode.workspace.getConfiguration("evermonkey");
const ATTACHMENT_FOLDER_PATH = config.attachmentsFolder || path.join(__dirname, "../../attachments");
const ATTACHMENT_SOURCE_LOCAL = 0;
const ATTACHMENT_SOURCE_SERVER = 1;
const TIP_BACK = "back...";
const METADATA_PATTERN = /^---[ \t]*\n((?:[ \t]*[^ \t:]+[ \t]*:[^\n]*\n)+)---[ \t]*\n/;
const METADATA_HEADER = `\
---
title: %s
tags: %s
notebook: %s
---

`;
// notesMap -- [notebookguid:[notes]].
let notebooks, notesMap, selectedNotebook;
const localNote = {};
let showTips;
let client;
const serverResourcesCache = {};
const tagCache = {};
const converter = new converterplus_1.default({});
// doc -> [{filepath: attachment}]
const attachmentsCache = {};
//  exact text Metadata by convention
function exactMetadata(text) {
    let metadata = {};
    let content = text;
    if (_.startsWith(text, "---")) {
        let match = METADATA_PATTERN.exec(text);
        if (match) {
            content = text.substring(match[0].trim().length).replace(/^\s+/, "");
            let metadataStr = match[1].trim();
            let metaArray = metadataStr.split("\n");
            metaArray.forEach(value => {
                let sep = value.indexOf(":");
                metadata[value.substring(0, sep).trim()] = value.substring(sep + 1).trim();
            });
            if (metadata["tags"]) {
                let tagStr = metadata["tags"];
                metadata["tags"] = tagStr.split(",").map(value => value.trim());
            }
        }
    }
    return {
        "metadata": metadata,
        "content": content
    };
}
function genMetaHeader(title, tags, notebook) {
    return util.format(METADATA_HEADER, title, tags.join(","), notebook);
}
// nav to one Note
function navToNote() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const notebooksName = yield listNotebooks();
            const selectedNotebook = yield vscode.window.showQuickPick(notebooksName);
            if (!selectedNotebook) {
                throw ""; // user dismisss
            }
            const noteLists = yield listNotes(selectedNotebook);
            if (!noteLists) {
                yield vscode.window.showInformationMessage("Can not open an empty notebook.");
                return navToNote();
            }
            else {
                let noteTitles = noteLists.map(note => note.title);
                const selectedNote = yield vscode.window.showQuickPick(noteTitles.concat(TIP_BACK));
                if (!selectedNote) {
                    throw "";
                }
                return openNote(selectedNote);
            }
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// Synchronize evernote account. For metadata.
function syncAccount() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            // lazy initilation.
            // TODO: configuration update event should be awared, so that a token can be reconfigured.
            const config = vscode.workspace.getConfiguration("evermonkey");
            yield vscode.window.setStatusBarMessage("Synchronizing your account...", 1000);
            client = new everapi_1.EvernoteClient(config.token, config.noteStoreUrl);
            const tags = yield client.listTags();
            tags.forEach(tag => tagCache[tag.guid] = tag.name);
            notebooks = yield client.listNotebooks();
            let promises = notebooks.map(notebook => client.listAllNoteMetadatas(notebook.guid));
            const allMetas = yield Promise.all(promises);
            const notes = _.flattenDeep(allMetas.map((meta) => meta.notes));
            notesMap = _.groupBy(notes, "notebookGuid");
            vscode.window.setStatusBarMessage("Synchronizing succeeded!", 1000);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// add attachtment to note.
function attachToNote() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (!notebooks || !notesMap) {
                yield syncAccount();
            }
            const editor = yield vscode.window.activeTextEditor;
            let doc = editor.document;
            let filepath = yield vscode.window.showInputBox({
                placeHolder: "Full path of your attachtment:",
                ignoreFocusOut: true
            });
            if (!filepath) {
                throw "";
            }
            const extConfig = vscode.workspace.getConfiguration("evermonkey");
            if (extConfig.uploadFolder) {
                const folderExsit = yield file_1.default.exsit(extConfig.uploadFolder);
                if (folderExsit) {
                    filepath = path.join(extConfig.uploadFolder, filepath);
                }
            }
            else {
                vscode.window.showWarningMessage("Attachments upload folder not set, you may have to use absolute file path.");
            }
            const fileName = path.basename(filepath);
            const mime = myutil_1.guessMime(fileName);
            const data = yield file_1.default.readFileAsync(filepath);
            const md5 = myutil_1.hash(data);
            const attachment = {
                "mime": mime,
                "data": {
                    "body": data,
                    "size": data.length,
                    "bodyHash": md5
                },
                "attributes": {
                    "fileName": fileName,
                    "attachment": true,
                    "timestamp": Date.now()
                }
            };
            const cache = {};
            cache[filepath] = attachment;
            attachmentsCache[doc.fileName].push(cache);
            // insert attachment to current position.
            const position = editor.selection.active;
            editor.edit(edit => {
                edit.insert(position, util.format('<en-media type="%s" hash="%s"></en-media>', attachment.mime, Buffer.from(attachment.data.bodyHash).toString("hex")));
            });
            vscode.window.showInformationMessage(util.format("%s has been attched to current note.", fileName));
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// remove a local attachment.
function removeAttachment() {
    return __awaiter(this, void 0, void 0, function* () {
        const editor = yield vscode.window.activeTextEditor;
        let doc = editor.document;
        // Can only remove an attachment from a cache file
        if (attachmentsCache[doc.fileName]) {
            let localAttachments = attachmentsCache[doc.fileName].map(cache => _.values(cache)[0]);
            const selectedAttachment = yield vscode.window.showQuickPick(localAttachments.map(attachment => attachment.attributes.fileName));
            if (!selectedAttachment) {
                throw "";
            }
            let attachmentToRemove = localAttachments.find(attachment => attachment.attributes.fileName === selectedAttachment);
            _.remove(attachmentsCache[doc.fileName], cache => _.values(cache)[0].attributes.fileName === selectedAttachment);
            vscode.window.showInformationMessage(util.format("%s has been removed from current note.", selectedAttachment));
        }
    });
}
// list current file attachment.
function listResources() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const editor = yield vscode.window.activeTextEditor;
            let doc = editor.document;
            let localResources;
            let serverResources = serverResourcesCache[doc.fileName];
            // open a note from server ,may have resouces
            if (localNote[doc.fileName]) {
                const result = yield client.getNoteResources(localNote[doc.fileName].guid);
                serverResources = result.resources;
                serverResourcesCache[doc.fileName] = serverResources;
            }
            // show local cache only.
            localResources = attachmentsCache[doc.fileName].map(cache => _.values(cache)[0]);
            let serverResourcesName = [];
            let localResourcesName = [];
            if (serverResources) {
                serverResourcesName = serverResources.map(attachment => "(server) " + attachment.attributes.fileName + " -- At " + new Date(attachment.attributes.timestamp).toLocaleString());
            }
            if (localResources) {
                localResourcesName = localResources.map(attachment => "(local) " + attachment.attributes.fileName + " -- At " + new Date(attachment.attributes.timestamp).toLocaleString());
            }
            if (serverResourcesName || localResourcesName) {
                const selected = yield vscode.window.showQuickPick(serverResourcesName.concat(localResourcesName));
                // do not handle now.
                if (!selected) {
                    throw "";
                }
                let selectedAttachment;
                let selectedFileName;
                let source;
                let uri;
                if (selected.startsWith("(server) ")) {
                    selectedFileName = selected.substr(9);
                    selectedAttachment = serverResources.find(resource => resource.attributes.fileName === selectedFileName);
                    source = ATTACHMENT_SOURCE_SERVER;
                }
                else {
                    selectedFileName = selected.substr(8);
                    selectedAttachment = localResources.find(resource => resource.attributes.fileName === selectedFileName);
                    source = ATTACHMENT_SOURCE_LOCAL;
                    let selectedCache = attachmentsCache[doc.fileName].find(cache => _.values(cache)[0].attributes.fileName === selectedFileName);
                    uri = _.keys(selectedCache)[0];
                }
                openAttachment(selectedAttachment, source, uri);
            }
            else {
                vscode.window.showInformationMessage("No resouce to show.");
            }
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// open an attachment, use default app.
function openAttachment(attachment, source, uri) {
    return __awaiter(this, void 0, void 0, function* () {
        switch (source) {
            case ATTACHMENT_SOURCE_LOCAL:
                try {
                    open(uri);
                }
                catch (err) {
                    wrapError(err);
                }
                break;
            case ATTACHMENT_SOURCE_SERVER:
                const resource = yield client.getResource(attachment.guid);
                const fileName = resource.attributes.fileName;
                const data = resource.data.body;
                try {
                    const isExist = yield file_1.default.exsit(ATTACHMENT_FOLDER_PATH);
                    if (!isExist) {
                        yield file_1.default.mkdirAsync(ATTACHMENT_FOLDER_PATH);
                    }
                    const tmpDir = yield file_1.default.mkdtempAsync(path.join(ATTACHMENT_FOLDER_PATH, "./evermonkey-"));
                    const filepath = path.join(tmpDir, fileName);
                    yield file_1.default.writeFileAsync(filepath, data);
                    open(filepath);
                }
                catch (error) {
                    wrapError(error);
                }
                break;
        }
    });
}
// Publish note to Evernote Server. with resources.
function publishNote() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (!notebooks || !notesMap) {
                yield syncAccount();
            }
            const editor = yield vscode.window.activeTextEditor;
            let doc = editor.document;
            let result = exactMetadata(doc.getText());
            let content = yield converter.toEnml(result.content);
            let meta = result.metadata;
            let title = meta["title"];
            let resources;
            if (attachmentsCache[doc.fileName]) {
                resources = attachmentsCache[doc.fileName].map(cache => _.values(cache)[0]);
            }
            if (localNote[doc.fileName]) {
                // update the note.
                vscode.window.setStatusBarMessage("Updaing the note.", 2000);
                let updatedNote;
                let noteGuid = localNote[doc.fileName].guid;
                const noteResources = yield client.getNoteResources(noteGuid);
                if (noteResources.resources || resources) {
                    if (noteResources.resources) {
                        resources = resources.concat(noteResources.resources);
                    }
                    updatedNote = yield updateNoteResources(meta, content, noteGuid, resources);
                    updatedNote.resources = resources;
                    serverResourcesCache[doc.fileName] = null;
                }
                else {
                    updatedNote = yield updateNoteContent(meta, content, noteGuid);
                }
                localNote[doc.fileName] = updatedNote;
                let notebookName = notebooks.find(notebook => notebook.guid === updatedNote.notebookGuid).name;
                // attachments cache should be removed.
                attachmentsCache[doc.fileName] = [];
                return vscode.window.showInformationMessage(`${notebookName}>>${title} updated successfully.`);
            }
            else {
                const nguid = yield getNoteGuid(meta);
                if (nguid) {
                    vscode.window.setStatusBarMessage("Updating to server.", 2000);
                    const updateNote = yield updateNoteOnServer(meta, content, resources, nguid);
                    updateNote.resources = resources;
                    if (!notesMap[updateNote.notebookGuid]) {
                        notesMap[updateNote.notebookGuid] = [updateNote];
                    }
                    else {
                        notesMap[updateNote.notebookGuid].push(updateNote);
                    }
                    localNote[doc.fileName] = updateNote;
                    let notebookName = notebooks.find(notebook => notebook.guid === updateNote.notebookGuid).name;
                    attachmentsCache[doc.fileName] = [];
                    return vscode.window.showInformationMessage(`${notebookName}>>${title} update to server successfully.`);
                }
                else {
                    vscode.window.setStatusBarMessage("Creating the note.", 2000);
                    const createdNote = yield createNote(meta, content, resources);
                    createdNote.resources = resources;
                    if (!notesMap[createdNote.notebookGuid]) {
                        notesMap[createdNote.notebookGuid] = [createdNote];
                    }
                    else {
                        notesMap[createdNote.notebookGuid].push(createdNote);
                    }
                    localNote[doc.fileName] = createdNote;
                    let notebookName = notebooks.find(notebook => notebook.guid === createdNote.notebookGuid).name;
                    attachmentsCache[doc.fileName] = [];
                    return vscode.window.showInformationMessage(`${notebookName}>>${title} created successfully.`);
                }
            }
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// add resource data to note content. -- Note: server body hash is
function appendResourceContent(resources, content) {
    if (resources) {
        content = content.slice(0, -10);
        resources.forEach(attachment => {
            content = content + util.format('<en-media type="%s" hash="%s"/>', attachment.mime, Buffer.from(attachment.data.bodyHash).toString("hex"));
        });
        content = content + "</en-note>";
    }
    return content;
}
// Update an exsiting note.
function updateNoteResources(meta, content, noteGuid, resources) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let tagNames = meta["tags"];
            let title = meta["title"];
            let notebook = meta["notebook"];
            const notebookGuid = yield getNotebookGuid(notebook);
            return client.updateNoteResources(noteGuid, title, content, tagNames, notebookGuid, resources || void 0);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
function updateNoteContent(meta, content, noteGuid) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let tagNames = meta["tags"];
            let title = meta["title"];
            let notebook = meta["notebook"];
            const notebookGuid = yield getNotebookGuid(notebook);
            return client.updateNoteContent(noteGuid, title, content, tagNames, notebookGuid);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// Choose notebook. Used for publish.
function getNotebookGuid(notebook) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let notebookGuid;
            if (notebook) {
                let notebookLocal = notebooks.find(nb => nb.name === notebook);
                if (notebookLocal) {
                    notebookGuid = notebookLocal.guid;
                }
                else {
                    const createdNotebook = yield client.createNotebook(notebook);
                    notebooks.push(createdNotebook);
                    notebookGuid = createdNotebook.guid;
                }
            }
            else {
                const defaultNotebook = yield client.getDefaultNotebook();
                notebookGuid = defaultNotebook.guid;
            }
            return notebookGuid;
        }
        catch (err) {
            wrapError(err);
        }
    });
}
function getNoteGuid(meta) {
    return __awaiter(this, void 0, void 0, function* () {
        let title = meta["title"];
        let intitle = 'intitle:' + '"' + title + '"';
        let nguid = null;
        let re = yield client.listMyNotes(intitle);
        let resul = re.notes;
        let arrayLength = resul.length;
        let i;
        for (i = 0; i < arrayLength; i++) {
            if (resul[i].title == title)
                nguid = resul[i].guid;
        }
        return nguid;
    });
}
function updateNoteOnServer(meta, content, resources, nguid) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let title = meta["title"];
            let tagNames = meta["tags"];
            let notebook = meta["notebook"];
            const notebookGuid = yield getNotebookGuid(notebook);
            return client.updateNoteResources(nguid, title, content, tagNames, notebookGuid, resources || void 0);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// Create an new note.
function createNote(meta, content, resources) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let tagNames = meta["tags"];
            let title = meta["title"];
            let notebook = meta["notebook"];
            const notebookGuid = yield getNotebookGuid(notebook);
            return client.createNote(title, notebookGuid, content, tagNames, resources);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// List all notebooks name.
function listNotebooks() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (!notebooks || !notesMap) {
                yield syncAccount();
            }
            return notebooks.map(notebook => notebook.name);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// List notes in the notebook. (200 limits.)
function listNotes(notebook) {
    selectedNotebook = notebooks.find(nb => nb.name === notebook);
    let noteLists = notesMap[selectedNotebook.guid];
    return noteLists;
}
// Create an empty note with metadata and markdown support in vscode.
function newNote() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (!notebooks) {
                yield syncAccount();
            }
            const doc = yield vscode.workspace.openTextDocument({
                language: "markdown"
            });
            // init attachment cache
            attachmentsCache[doc.fileName] = [];
            const editor = yield vscode.window.showTextDocument(doc);
            let startPos = new vscode.Position(1, 0);
            editor.edit(edit => {
                let metaHeader = util.format(METADATA_HEADER, "", "", "");
                edit.insert(startPos, metaHeader);
            });
            // start at the title.
            const titlePosition = startPos.with(1, 8);
            editor.selection = new vscode.Selection(titlePosition, titlePosition);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// Search note.
function searchNote() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (!notesMap || !notebooks) {
                yield syncAccount();
            }
            const query = yield vscode.window.showInputBox({
                placeHolder: "Use Evernote Search Grammar to search notes."
            });
            const searchResult = yield client.searchNote(query);
            const noteWithbook = searchResult.notes.map(note => {
                let title = note["title"];
                selectedNotebook = notebooks.find(notebook => notebook.guid === note.notebookGuid);
                return selectedNotebook.name + ">>" + title;
            });
            const selectedNote = yield vscode.window.showQuickPick(noteWithbook);
            if (!selectedNote) {
                throw ""; // user dismiss
            }
            yield openSearchResult(selectedNote, searchResult.notes);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
function openRecentNotes() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (!notebooks || !notesMap) {
                yield syncAccount();
            }
            const recentResults = yield client.listRecentNotes();
            const recentNotes = recentResults.notes;
            const selectedNoteTitle = yield vscode.window.showQuickPick(recentNotes.map(note => note.title));
            if (!selectedNoteTitle) {
                throw "";
            }
            let selectedNote = recentNotes.find(note => note.title === selectedNoteTitle);
            selectedNotebook = notebooks.find(notebook => notebook.guid === selectedNote.notebookGuid);
            return openNote(selectedNoteTitle);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// Open search result note. (notebook >> note)
function openSearchResult(noteWithbook, notes) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let index = noteWithbook.indexOf(">>");
            let searchNoteResult = noteWithbook.substring(index + 2);
            let chooseNote = notes.find(note => note.title === searchNoteResult);
            const note = yield client.getNoteContent(chooseNote.guid);
            const content = note.content;
            const doc = yield vscode.workspace.openTextDocument({
                language: "markdown"
            });
            yield cacheAndOpenNote(note, doc, content);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// Open note by title in vscode
function openNote(noteTitle) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            if (noteTitle === TIP_BACK) {
                return navToNote();
            }
            let selectedNote = notesMap[selectedNotebook.guid].find(note => note.title === noteTitle);
            const note = yield client.getNoteContent(selectedNote.guid);
            const content = note.content;
            const doc = yield vscode.workspace.openTextDocument({
                language: "markdown"
            });
            yield cacheAndOpenNote(note, doc, content);
        }
        catch (err) {
            wrapError(err);
        }
    });
}
function openNoteInClient() {
    return __awaiter(this, void 0, void 0, function* () {
        const editor = yield vscode.window.activeTextEditor;
        let doc = editor.document;
        if (localNote[doc.fileName]) {
            let noteGuid = localNote[doc.fileName].guid;
            if (noteGuid) {
                open(getNoteLink(noteGuid));
            }
        }
        else {
            vscode.window.showWarningMessage("Can not open the note, maybe not on the server");
        }
    });
}
function getNoteLink(noteGuid) {
    const token = config.token;
    if (token && noteGuid) {
        let userInfo = token.split(":");
        let shardId = userInfo[0].substring(2);
        let userId = parseInt(userInfo[1].substring(2), 16);
        return `evernote:///view/${userId}/${shardId}/${noteGuid}/${noteGuid}/`;
    }
    return "";
}
function openNoteInBrowser() {
    return __awaiter(this, void 0, void 0, function* () {
        const config = vscode.workspace.getConfiguration("evermonkey");
        const editor = yield vscode.window.activeTextEditor;
        let doc = editor.document;
        if (localNote[doc.fileName]) {
            let noteGuid = localNote[doc.fileName].guid;
            if (noteGuid) {
                const domain = config.noteStoreUrl.slice(0, -9);
                const url = util.format(domain + "view/%s", noteGuid);
                open(url);
            }
        }
        else {
            vscode.window.showWarningMessage("Can not open the note, maybe not on the server");
        }
    });
}
// Open note in vscode and cache to memory.
function cacheAndOpenNote(note, doc, content) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const editor = yield vscode.window.showTextDocument(doc);
            localNote[doc.fileName] = note;
            // attachtment cache init.
            attachmentsCache[doc.fileName] = [];
            let startPos = new vscode.Position(1, 0);
            let tagGuids = note.tagGuids;
            let tags;
            if (tagGuids) {
                let newTags = _.filter(tagGuids, guid => !tagCache[guid]);
                let promises = newTags.map(guid => {
                    if (guid) {
                        return client.getTag(guid);
                    }
                });
                const newTagObj = yield Promise.all(promises);
                // update tag cache.
                newTagObj.forEach((tag) => tagCache[tag.guid] = tag.name);
                tags = tagGuids.map(guid => tagCache[guid]);
            }
            else {
                tags = [];
            }
            editor.edit(edit => {
                let mdContent = converter.toMd(content);
                let metaHeader = genMetaHeader(note.title, tags, notebooks.find(notebook => notebook.guid === note.notebookGuid).name);
                edit.insert(startPos, metaHeader + mdContent);
            });
        }
        catch (err) {
            wrapError(err);
        }
    });
}
// open evernote dev page to help you configure.
function openDevPage() {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            const choice = yield vscode.window.showQuickPick(["China", "International"]);
            if (!choice) {
                return;
            }
            if (choice === "China") {
                open("https://app.yinxiang.com/api/DeveloperToken.action");
            }
            else {
                open("https://www.evernote.com/api/DeveloperToken.action");
            }
            // input help configure.
            const token = yield vscode.window.showInputBox({
                placeHolder: "Copy & paste your token here.",
                ignoreFocusOut: true
            });
            if (!token) {
                return;
            }
            const noteStoreUrl = yield vscode.window.showInputBox({
                placeHolder: "Copy & paste your noteStoreUrl here.",
                ignoreFocusOut: true
            });
            if (!noteStoreUrl) {
                return;
            }
            config.update("token", token, true);
            config.update("noteStoreUrl", noteStoreUrl, true);
            if (config.token && config.noteStoreUrl) {
                vscode.window.showInformationMessage("Monkey is ready to work. Get the full documents here http://monkey.yoryor.me." +
                    "If you get an error, just check the configuration and restart the vscode. Enjoy it and give me star on the github!");
            }
            else {
                if (!config.token) {
                    vscode.window.showWarningMessage("It seems like no token has been entered, try again: ever token");
                }
                if (!config.noteStoreUrl) {
                    vscode.window.showWarningMessage("It seems like no noteStoreUrl has been entered, try again: ever token");
                }
            }
        }
        catch (err) {
            wrapError(err);
        }
    });
}
function wrapError(error) {
    if (!error) {
        return;
    }
    console.log(error);
    let errMsg;
    if (error.statusCode && error.statusMessage) {
        errMsg = `Http Error: ${error.statusCode}- ${error.statusMessage}, Check your ever config please.`;
    }
    else if (error.errorCode && error.parameter) {
        errMsg = `Evernote Error: ${error.errorCode} - ${error.parameter}`;
    }
    else {
        errMsg = "Unexpected Error: " + JSON.stringify(error);
    }
    vscode.window.showErrorMessage(errMsg);
}
function activate(context) {
    const filesSettings = vscode.workspace.getConfiguration("files");
    filesSettings.update("eol", "\n", true);
    const markdownSettings = vscode.workspace.getConfiguration();
    markdownSettings.update("[markdown]", { "editor.quickSuggestions": true }, true);
    if (!config.token || !config.noteStoreUrl) {
        vscode.window.showInformationMessage("Evernote token not set, please enter ever token command to help you configure.");
    }
    // quick match for monkey.
    let action = vscode.languages.registerCompletionItemProvider(["plaintext", {
            "scheme": "untitled",
            "language": "markdown"
        }], {
        provideCompletionItems(doc, position) {
            // simple but enough validation for title, tags, notebook
            // title dont show tips.
            if (position.line === 1) {
                return [];
            }
            else if (position.line === 2) {
                // tags
                if (tagCache) {
                    return _.values(tagCache).map(tag => new vscode.CompletionItem(tag));
                }
            }
            else if (position.line === 3) {
                if (notebooks) {
                    return notebooks.map(notebook => new vscode.CompletionItem(notebook.name));
                }
            }
        }
    });
    vscode.workspace.onDidCloseTextDocument(removeLocal);
    vscode.workspace.onDidSaveTextDocument(alertToUpdate);
    let listAllNotebooksCmd = vscode.commands.registerCommand("extension.navToNote", navToNote);
    let publishNoteCmd = vscode.commands.registerCommand("extension.publishNote", publishNote);
    let openDevPageCmd = vscode.commands.registerCommand("extension.openDevPage", openDevPage);
    let syncCmd = vscode.commands.registerCommand("extension.sync", syncAccount);
    let newNoteCmd = vscode.commands.registerCommand("extension.newNote", newNote);
    let searchNoteCmd = vscode.commands.registerCommand("extension.searchNote", searchNote);
    let openRecentNotesCmd = vscode.commands.registerCommand("extension.openRecentNotes", openRecentNotes);
    let attachToNoteCmd = vscode.commands.registerCommand("extension.attachToNote", attachToNote);
    let listResourcesCmd = vscode.commands.registerCommand("extension.listResources", listResources);
    let openNoteInBrowserCmd = vscode.commands.registerCommand("extension.openNoteInBrowser", openNoteInBrowser);
    let removeAttachmentCmd = vscode.commands.registerCommand("extension.removeAttachment", removeAttachment);
    let openNoteInClientCmd = vscode.commands.registerCommand("extension.viewInEverClient", openNoteInClient);
    context.subscriptions.push(listAllNotebooksCmd);
    context.subscriptions.push(publishNoteCmd);
    context.subscriptions.push(openDevPageCmd);
    context.subscriptions.push(syncCmd);
    context.subscriptions.push(newNoteCmd);
    context.subscriptions.push(action);
    context.subscriptions.push(searchNoteCmd);
    context.subscriptions.push(openRecentNotesCmd);
    context.subscriptions.push(attachToNoteCmd);
    context.subscriptions.push(listResourcesCmd);
    context.subscriptions.push(openNoteInBrowserCmd);
    context.subscriptions.push(removeAttachmentCmd);
    context.subscriptions.push(openNoteInClientCmd);
}
exports.activate = activate;
// remove local cache when closed the editor.
function removeLocal(event) {
    localNote[event.fileName] = null;
    serverResourcesCache[event.fileName] = null;
}
function alertToUpdate() {
    if (!showTips) {
        return;
    }
    let msg = "Saving to local won't sync the remote. Try ever publish";
    let option = "Ignore";
    vscode.window.showWarningMessage(msg, option).then(result => {
        if (result === option) {
            showTips = false;
        }
    });
}
// this method is called when your extension is deactivated
function deactivate() { }
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map