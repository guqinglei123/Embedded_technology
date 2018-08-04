
#ifndef _LED_H
#define _LED_H
//点亮 熄灭 这里定义两个 而且都不需要传参 具体可以结和前一课
 
#define LED_MAGIC  'L'
#define LED_ON     _IO(LED_MAGIC, 0)
#define LED_OFF    _IO(LED_MAGIC, 1)

#endif
