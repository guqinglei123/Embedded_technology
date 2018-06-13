Linux常用操作：
备份 (操作目录为接入的备份磁盘)
	sudo tar cvpzf  Ubuntu.tgz --exclude=/proc --exclude=/lost+found --exclude=/mnt --exclude=/sys  --exclude=/media --exclude=/home/Ubuntu.tgz/  /
	sudo tar -xvpzf  Ubuntu.tgz  -C  /
优化：
	sudo apt remove thunderbird totem rhythmbox empathy brasero simple-scan gnome-mahjongg aisleriot gnome-mines cheese transmission-common gnome-orca webbrowser-app gnome-sudoku landscape-client-ui-install onboard deja-dup
	sudo apt-get remove unity-webapps-common  
	sudo apt-get remove libreoffice-common  
主题推荐：
	United GNOME：非常漂亮且极具Ubuntu特色的主题，基于一位设计师的Ubuntu 18.04概念设计图创作
	Arc及变种OSX-Arc：另一套极具特色的主题，文件管理器侧边栏为黑色Material Design：Paper、Adapta及其变种、Materia(前Flat-Plat)及其变种Flat-Plat Blue, 
图标推荐：
	Vimix仿macOS：Elementary、Gnome-OSX、OSX White、macOS Sierra图标Material design：Flat Remix(个人最爱)、Paper(原生Android风)、Papirus仿macOS：Elementary(经典的蓝色文件夹)、La Capitaine(非常漂亮，只是模仿的痕迹较重)
软件推荐：
	有道，sublime，VS code ，QT，WPS，electrronic wechat，gnome-tweal-tool，google，nixnote，搜狗输入法，福昕阅读器，网易云音乐，Docky，teamview，坚果云，VLC播放器，git，Shutter，VLC