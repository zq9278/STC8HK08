#include	"config.h"

void GPIO_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;        // 结构定义
    GPIO_InitStructure.Pin  = GPIO_Pin_5;       // 指定要初始化的IO,
    GPIO_InitStructure.Mode = GPIO_PullUp;      // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure); // 初始化

    GPIO_InitStructure.Pin  = GPIO_Pin_4;       // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_InitStructure.Mode = GPIO_PullUp;      // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure); // 初始化

      GPIO_InitStructure.Pin  = GPIO_Pin_6;       // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_InitStructure.Mode = GPIO_PullUp;      // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure); // 初始化
    //P3_PULL_UP_ENABLE(6);
    P36=1;
}
bool isLongPress() {
    unsigned int count = 0;
    if (READ_KEY_PIN==0) {  // 检测按键初次按下
        delay_ms(50);  // 消抖
        while (READ_KEY_PIN==0) {  // 确认按键持续被按下
            delay_ms(100);
            count++;
            if (count >= 20) {  // 持续时间超过2秒
                return true;
            }
        }
    }
    return false;
}
void enterLowPowerMode() {
    PCON |= 0x02;  // 设置PCON寄存器的PD位进入电源下降模式
    _nop_();
    _nop_();
}