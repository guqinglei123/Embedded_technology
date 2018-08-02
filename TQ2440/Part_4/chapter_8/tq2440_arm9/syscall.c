void pk()
{
	/*
	2.6.39
	1.将系统调用编号(arch\arm\include\asm\unistd.h)放在r7,为什么使用ldr而不是mov，363长度超过了8位
	2.通过swi通过软中断切换到内核态

	3.调用sys_call_table(定义在\arch\arm\....entry-common.S)其中就是calls.s
	4.calls.s文件\arch\arm\kernel\calls.S
	
	*/
    __asm__ (
    "ldr r7,=363 \n"
    "swi \n"
    :
    :
    :"memory");
}

void main()
{
    pk();	
}