
#include "config.h"
#include "STC8G_H_NVIC.h"

/***************	����˵��	****************
����STC8H8K64UΪ����оƬ��ʵ����8���б�д���ԣ�STC8G��STC8Hϵ��оƬ��ͨ�òο�.
����ʱ, ѡ��ʱ�� 24MHz (�����������ļ�"config.h"���޸�).
******************************************/
/*************	���س�������	**************/
u8 code ledNum[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
/*************	���ر�������	**************/
u8 ledIndex;
extern bit sleep_flag; // ����״̬��־

/*************	���غ�������	**************/

void setupInterrupt()
{
    IT0 = 1; // �����ⲿ�ж�0Ϊ�½��ش���
    EX0 = 1; // ʹ���ⲿ�ж�0
    EA  = 1; // ʹ��ȫ���ж�
}
void Exti_config(void)
{
    // EXTI_InitTypeDef	Exti_InitStructure;							//�ṹ����

    // Exti_InitStructure.EXTI_Mode      = EXT_MODE_Fall;//�ж�ģʽ,   EXT_MODE_RiseFall,EXT_MODE_Fall
    // Ext_Inilize(EXT_INT2,&Exti_InitStructure);				//��ʼ��
    NVIC_INT2_Init(ENABLE, Priority_0); // �ж�ʹ��, ENABLE/DISABLE; ���ȼ�(�͵���) Priority_0,Priority_1,Priority_2,Priority_3

    // Exti_InitStructure.EXTI_Mode      = EXT_MODE_Fall;//�ж�ģʽ,   EXT_MODE_RiseFall,EXT_MODE_Fall
    // Ext_Inilize(EXT_INT1,&Exti_InitStructure);				//��ʼ��
    // NVIC_INT1_Init(ENABLE,Priority_0);		//�ж�ʹ��, ENABLE/DISABLE; ���ȼ�(�͵���) Priority_0,Priority_1,Priority_2,Priority_3

    // NVIC_INT2_Init(ENABLE,NULL);		//�ж�ʹ��, ENABLE/DISABLE; �����ȼ�
    // NVIC_INT3_Init(ENABLE,NULL);		//�ж�ʹ��, ENABLE/DISABLE; �����ȼ�
    // NVIC_INT4_Init(ENABLE,NULL);		//�ж�ʹ��, ENABLE/DISABLE; �����ȼ�
}
/*************  �ⲿ�����ͱ������� *****************/

/******************** IO���ú��� **************************/

/******************** ������ **************************/
void main(void)
{ // setupInterrupt();

    EAXSFR(); /* ��չ�Ĵ�������ʹ�� */
    GPIO_config();
    Exti_config();
    setupInterrupt();
    // setRegisterBit(INTCLKO, INT2_INTCLKO_EX2);
    P35      = 0; // LED Power On
    P34      = 1; // LED Power On
    ledIndex = 0;

    while (1) {
        //		P6 = ~ledNum[ledIndex];	//���������
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
        //      enterLowPowerMode();  // ����͹���ģʽ
        //  }
        if (sleep_flag != 0) {
            delay_ms(50);
        } else {
            delay_ms(5);
        }
    }
}
