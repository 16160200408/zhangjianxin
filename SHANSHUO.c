#include "LPC11XX.H"

#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0))     
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0))     

#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1))
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1))

#define KEY1_DOWN() ((LPC_GPIO3->DATA & (1<<0)) != (1<<0))
#define KEY2_DOWN() ((LPC_GPIO3->DATA & (1<<1)) != (1<<1))

unsigned int status;

void LEDInit()
{
	
		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); 			//��IOCON����ʱ��
    LPC_IOCON->PIO2_0 &= ~0x07;    
    LPC_IOCON->PIO2_0 |= 0x00; 								//���� P2.0 GPIO 
		LPC_IOCON->PIO2_1 &= ~0x07;    
    LPC_IOCON->PIO2_1 |= 0x00; 								//���� P2.0 GPIO 
		LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);  //�ر� IOCON ����ʱ��
		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
		LPC_GPIO2->DIR |=(1<<0);									//���� P2.0 Ϊ���
		LPC_GPIO2->DATA |=(1<<0);									//�� P2.0 ��Ϊ�ߵ�ƽ
		LPC_GPIO2->DIR |=(1<<1);									//���� P2.0 Ϊ���
		LPC_GPIO2->DATA |=(1<<1);									//�� P2.0 ��Ϊ�ߵ�ƽ
}
void SysTickInit(void)
{
		SysTick->CTRL &= ~(1<<2);
		SysTick->LOAD = 12499999;
		SysTick->VAL = 0;
		SysTick->CTRL |= ((1<<1)|(1<<0));
		NVIC_EnableIRQ(SysTick_IRQn);
}

void SysTick_Handler(void)
{
		status = LPC_GPIO2->DATA;
		LPC_GPIO2->DATA = ~ status;
}

int main()
{
		LEDInit();
		SysTickInit();
		while(1)
					{
					
					//LED1_ON();
				  //Delayms(500);	
			//	LED1_OFF();
				//	Delayms(500);
					}
}
