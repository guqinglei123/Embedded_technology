常用命令和快捷键：
命名习惯：
行为		 		windows习惯				Linux-C习惯		
宏定义  		   全部大写		 				全部大写
变量名   	   第一单词全部小写，其他单词第一个字母大写		小写，下划线连接
函数名		   全部单词第一字母大写，其他小写			小写，下划线连接
类名		   全部单词第一字母大写，其他小写	
其他：对于结构体，if/for/while/switch {不另起一行；对函数则另起一行

Linux常用命令：	 	 								
	ls 	touch	more	less	cat 	cp 	mv	find	whitch	rm
	mkdir	pwd	cd 	tar 	fdisk	ntfsfix	du	df 	chmod	free	
	sudo	lsusb	lsmod	lshw 	grep	uname	route	xarg	env	ps
	kill 	reboot	history	date	mount/umount	passwd	useradd/groupadd
	ifconfig/ifdown/ifup	apt-get install/remove和dpkg	/etc/init.d/服务名 restart 

Ubuntu和终端下常用命令：
	ctrl+atl+T 新建 
	atl+tab 切换查看  
	Ctrl + Shift + C  复制命令
	Ctrl + Shift + V  粘贴命令
	Tab 自动补全 
	Ctrl+a 光标移动到开始位置 
	Ctrl+e 光标移动到最末尾 
	Ctrl+k 删除此处至末尾的所有内容 
	Ctrl+u 删除此处至开始的所有内容 
	Ctrl+d 删除当前字符 
	Ctrl+h 删除当前字符前一个字符 
	Ctrl+w 删除此处到左边的单词 
	Ctrl+y 粘贴由 Ctrl+u ， Ctrl+d ， Ctrl+w 删除的单词 
	Ctrl+l 相当于clear，即清屏 
	Ctrl+r 查找历史命令 
	Ctrl+b 向回移动光标 
	Ctrl+f 向前移动光标 
	Ctrl+t 将光标位置的字符和前一个字符进行位置交换 
	Ctrl+& 恢复 ctrl+h 或者 ctrl+d 或者 ctrl+w 删除的内容 
	Ctrl+S 暂停屏幕输出 
	Ctrl+Q 继续屏幕输出 
	Ctrl+Left-Arrow 光标移动到上一个单词的词首 
	Ctrl+Right-Arrow 光标移动到下一个单词的词尾 
	Ctrl+p 向上显示缓存命令 
	Ctrl+n 向下显示缓存命令 
	Ctrl+d 关闭终端 
	Ctrl+xx 在EOL和当前光标位置移动 
	Ctrl+x@ 显示可能hostname补全 
	Ctrl+c 终止进程/命令 
	Shift +上或下 终端上下滚动 
	Shift+PgUp/PgDn 终端上下翻页滚动 
	Ctrl+Shift+n 新终端 
	alt+F2 输入gnome-terminal打开终端 
	Shift+Ctrl+T 打开新的标签页 
	Shift+Ctrl+W 关闭标签页 
	Shift+Ctrl+C 复制 
	Shift+Ctrl+V 粘贴 
	Alt+数字 切换至对应的标签页 
	Shift+Ctrl+N 打开新的终端窗口 
	Shift+Ctrl+Q 管壁终端窗口 
	Shift+Ctrl+PgUp/PgDn 左移右移标签页 
	Ctrl+PgUp/PgDn 切换标签页 
	F1 打开帮助指南 
	F10 激活菜单栏 
	F11 全屏切换 
	Alt+F 打开 “文件” 菜单（file） 
	Alt+E 打开 “编辑” 菜单（edit） 
	Alt+V 打开 “查看” 菜单（view） 
	Alt+S 打开 “搜索” 菜单（search） 
	Alt+T 打开 “终端” 菜单（terminal） 
	Alt+H 打开 “帮助” 菜单（help） 



 sublime QT Creator 和VS code 中的快捷键与配置：
	ALT+左/右  前进/后退
	ctrl+P 在vscode为搜索文件名
	ctrl+F 本地文件搜索
	ctrl+shift+F 在vscode为全文件搜索
	ctrl+shift+O 在vscode为搜索函数
	ctrl+/   注释
	ctrl+i  格式化
	atl+n/o/p/r/s  印象笔记相关
	ctrl+o 打开  vscode中打开文件夹 ctrl+k ctrl+o
	ctrl+n  新建
	ctrl+s  保存
	ctrl+shift+s 另存
	ctrl+w 关闭  关闭窗口 ctrl+shilf+w
	ctrl+q 退出
	ctrl+shilft+p 命令面板
	ctrl+J  在vscode为切换面板
	ctrl+B 在vscode为切换面板侧边
	F12  goto定义
	ctrl+F12  goto申明
	Ctrl+tab 切换文件  atl+数字  切换到具体文件

vim中常用快捷键：
	一、移动光标
		h,j,k,l 上，下，左，右
		ctrl-e 移动页面
		ctrl-f 上翻一页
		ctrl-b 下翻一页
		ctrl-u 上翻半页
		ctrl-d 下翻半页
		w 跳到下一个字首，按标点或单词分割
		W 跳到下一个字首，长跳，如end-of-line被认为是一个字
		e 跳到下一个字尾
		E 跳到下一个字尾，长跳
		b 跳到上一个字
		B 跳到上一个字，长跳
		0 跳至行首，不管有无缩进，就是跳到第0个字符
		^ 跳至行首的第一个字符
		$ 跳至行尾
		gg 跳至文首
		G 调至文尾
		5gg/5G 调至第5行
		gd 跳至当前光标所在的变量的声明处
		fx 在当前行中找x字符，找到了就跳转至
		; 重复上一个f命令，而不用重复的输入fx
		* 查找光标所在处的单词，向下查找
		# 查找光标所在处的单词，向上查找

	二、删除复制
		dd 删除光标所在行
		dw 删除一个字(word)
		d/D删除到行末x删除当前字符X删除前一个字符yy复制一行yw复制一个字y/D删除到行末x删除当前字符X删除前一个字符yy复制一行yw复制一个字y/Y 复制到行末
		p 粘贴粘贴板的内容到当前行的下面
		P 粘贴粘贴板的内容到当前行的上面

	三、插入模式
		i 从当前光标处进入插入模式
		I 进入插入模式，并置光标于行首
		a 追加模式，置光标于当前光标之后
		A 追加模式，置光标于行末
		o 在当前行之下新加一行，并进入插入模式
		O 在当前行之上新加一行，并进入插入模式
		Esc 退出插入模式

	四、编辑
		J 将下一行和当前行连接为一行
		cc 删除当前行并进入编辑模式
		cw 删除当前字，并进入编辑模式
		c$ 擦除从当前位置至行末的内容，并进入编辑模式
		s 删除当前字符并进入编辑模式
		S 删除光标所在行并进入编辑模式
		xp 交换当前字符和下一个字符
		u 撤销
		ctrl+r 重做
		~ 切换大小写，当前字符
		>> 将当前行右移一个单位
		<< 将当前行左移一个单位(一个tab符)
		== 自动缩进当前行

	五、查找替换
		/pattern 向后搜索字符串pattern
		?pattern 向前搜索字符串pattern
		"\c" 忽略大小写
		"\C" 大小写敏感
		n 下一个匹配(如果是/搜索，则是向下的下一个，?搜索则是向上的下一个)
		N 上一个匹配(同上)
		:%s/old/new/g 搜索整个文件，将所有的old替换为new
		:%s/old/new/gc 搜索整个文件，将所有的old替换为new，每次都要你确认是否替换

	六、退出编辑器
		:w 将缓冲区写入文件，即保存修改
		:wq 保存修改并退出
		:x 保存修改并退出
		:q 退出，如果对缓冲区进行过修改，则会提示
		:q! 强制退出，放弃修改