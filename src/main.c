
#include "config.h"
#include "STC8G_H_NVIC.h"

/***************	功能说明	****************
基于STC8H8K64U为主控芯片的实验箱8进行编写测试，STC8G、STC8H系列芯片可通用参考.
下载时, 选择时钟 24MHz (可以在配置文件"config.h"中修改).
******************************************/
/*************	本地常量声明	**************/
u8 code ledNum[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
/*************	本地变量声明	**************/
u8 ledIndex;
extern bit sleep_flag; // 休眠状态标志

/*************	本地函数声明	**************/

void setupInterrupt()
{
    IT0 = 1; // 设置外部中断0为下降沿触发
    EX0 = 1; // 使能外部中断0
    EA  = 1; // 使能全局中断
}
void Exti_config(void)
{
    // EXTI_InitTypeDef	Exti_InitStructure;							//结构定义

    // Exti_InitStructure.EXTI_Mode      = EXT_MODE_Fall;//中断模式,   EXT_MODE_RiseFall,EXT_MODE_Fall
    // Ext_Inilize(EXT_INT2,&Exti_InitStructure);				//初始化
    NVIC_INT2_Init(ENABLE, Priority_0); // 中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3

    // Exti_InitStructure.EXTI_Mode      = EXT_MODE_Fall;//中断模式,   EXT_MODE_RiseFall,EXT_MODE_Fall
    // Ext_Inilize(EXT_INT1,&Exti_InitStructure);				//初始化
    // NVIC_INT1_Init(ENABLE,Priority_0);		//中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3

    // NVIC_INT2_Init(ENABLE,NULL);		//中断使能, ENABLE/DISABLE; 无优先级
    // NVIC_INT3_Init(ENABLE,NULL);		//中断使能, ENABLE/DISABLE; 无优先级
    // NVIC_INT4_Init(ENABLE,NULL);		//中断使能, ENABLE/DISABLE; 无优先级
}
/*************  外部函数和变量声明 *****************/

/******************** IO配置函数 **************************/

/******************** 主函数 **************************/
void main(void)
{ // setupInterrupt();

    EAXSFR(); /* 扩展寄存器访问使能 */
    GPIO_config();
    Exti_config();
    setupInterrupt();
    // setRegisterBit(INTCLKO, INT2_INTCLKO_EX2);
    P35      = 0; // LED Power On
    P34      = 1; // LED Power On
    ledIndex = 0;

    while (1) {
        //		P6 = ~ledNum[ledIndex];	//输出低驱动
        //		ledIndex++;
        //		if(ledIndex > 7)
        //		{
        //			ledIndex = 0;
        //		}

        // delay_ms(250);
        P34 ^= 1; // LED Power On

        // P34 = 0;		//LED Power On
        // delay_ms(250);
        //    if (isLongPress()) {
        //      enterLowPowerMode();  // 进入低功耗模式
        //  }
        if (sleep_flag != 0) {
            delay_ms(50);
        } else {
            delay_ms(5);
        }
    }
}
