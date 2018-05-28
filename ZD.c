#include "LPC11XX.H"

#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0))
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0))

#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1))
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1))

#define LED3_ON()  (LPC_GPIO2->DATA &= ~(1<<2))
#define LED3_OFF() (LPC_GPIO2->DATA |= (1<<2))

#define LED4_ON()  (LPC_GPIO2->DATA &= ~(1<<3))
#define LED4_OFF() (LPC_GPIO2->DATA |= (1<<3))

#define LED5_ON()  (LPC_GPIO2->DATA &= ~(1<<4))
#define LED5_OFF() (LPC_GPIO2->DATA |= (1<<4))

#define LED6_ON()  (LPC_GPIO2->DATA &= ~(1<<5))
#define LED6_OFF() (LPC_GPIO2->DATA |= (1<<5))

#define LED7_ON()  (LPC_GPIO2->DATA &= ~(1<<6))
#define LED7_OFF() (LPC_GPIO2->DATA |= (1<<6))

#define LED8_ON()  (LPC_GPIO2->DATA &= ~(1<<7))
#define LED8_OFF() (LPC_GPIO2->DATA |= (1<<7))

#define KEY1_DOWN() ((LPC_GPIO3->DATA & (1<<0)) != (1<<0))
#define KEY2_DOWN() ((LPC_GPIO3->DATA & (1<<1))!=(1<<1))
/********************************************************************************
* FunctionName   : LEDInit()
* Description    : LED?????
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
void Delay()
{
	uint16_t i,j;
	for(i=0;i<5000;i++)
		for(j=0;j<200;j++);
}
void LEDInit()
{
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // ??IOCON?? 
    LPC_IOCON->PIO2_0 &= ~0x07;    
    LPC_IOCON->PIO2_0 |= 0x00; //?P1.0????GPIO
    LPC_IOCON->PIO2_1 &= ~0x07;   
    LPC_IOCON->PIO2_1 |= 0x00; 
	  LPC_IOCON->PIO2_2 &= ~0x07;    
    LPC_IOCON->PIO2_2 |= 0x00;
    LPC_IOCON->PIO2_3 &= ~0x07;    
    LPC_IOCON->PIO2_3 |= 0x00; 
    LPC_IOCON->PIO2_4 &= ~0x07;    
    LPC_IOCON->PIO2_4 |= 0x00; 
    LPC_IOCON->PIO2_5 &= ~0x07;    
    LPC_IOCON->PIO2_5 |= 0x00; 
    LPC_IOCON->PIO2_6 &= ~0x07;    
    LPC_IOCON->PIO2_6 |= 0x00; 
    LPC_IOCON->PIO2_7 &= ~0x07;    
    LPC_IOCON->PIO2_7 |= 0x00; 	
    LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // ??IOCON??
    
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);  //??AHB???GPIO??    
    LPC_GPIO2->DIR |= (1<<0); 
    LPC_GPIO2->DATA |= (1<<0); 
    LPC_GPIO2->DIR |= (1<<1); 
    LPC_GPIO2->DATA |= (1<<1); 
		 LPC_GPIO2->DIR |= (1<<2); 
    LPC_GPIO2->DATA |= (1<<2);
	
		LPC_GPIO2->DIR |=(1<<3);
    LPC_GPIO2->DATA |= (1<<3);
		LPC_GPIO2->DIR |= (1<<4); 
    LPC_GPIO2->DATA |= (1<<4);
		LPC_GPIO2->DIR |= (1<<5); 
    LPC_GPIO2->DATA |= (1<<5);
		LPC_GPIO2->DIR |= (1<<6); 
    LPC_GPIO2->DATA |= (1<<6);
		LPC_GPIO2->DIR |= (1<<7); 
    LPC_GPIO2->DATA |= (1<<7);
}
/********************************************************************************
* FunctionName   : PIOINT1_IRQHandler()
* Description    : P1???????
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/

void PIOINT3_IRQHandler()
{
    if((LPC_GPIO3->MIS & (1<<0))==(1<<0)) // ???P1.9?????
    {
        LED1_ON();
			Delay();
			LED3_ON();
			Delay();
			LED5_ON();
			Delay();
			LED7_ON();
			Delay();
        while(KEY1_DOWN());
        LED1_OFF();
			Delay();
			 LED3_OFF();
			Delay();
			LED5_OFF();
			Delay();
			LED7_OFF();
			Delay();
        LPC_GPIO3->IC = (1<<0);  // ???
    }
    if((LPC_GPIO3->MIS & (1<<1))==(1<<1)) // ???P1.10?????
    {
      LED2_ON();
			Delay();
			LED4_ON();
			Delay();
			LED6_ON();
			Delay();
			LED8_ON();
			Delay();
       while(KEY2_DOWN());
      LED2_OFF();
			Delay();
			LED4_OFF();
			Delay();
			LED6_OFF();
			Delay();
			LED8_OFF();
			
			
       LPC_GPIO3->IC = (1<<1);  // ???
    }
}
/********************************************************************************
* FunctionName   : main()
* Description    : ???
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/
int main()
{
    LEDInit(); // ??LED
    
    LPC_IOCON->PIO3_0 &= ~(0x07);//?P1_9???GPIO
    LPC_GPIO3->DIR&= ~(1<<0);//?P1_9?????
    LPC_IOCON->PIO3_1 &= ~(0x07);//?P1_10???GPIO
    LPC_GPIO3->DIR &= ~(1<<1);//?P1_10?????
    
    LPC_GPIO3->IE |= (1<<0); // ??P1.9??????
    LPC_GPIO3->IE |= (1<<1); // ??P1.10??????
    LPC_GPIO3->IS &= ~(1<<0); // ??P1.9???????
    LPC_GPIO3->IS &= ~(1<<1); // ??P1.10???????
    LPC_GPIO3->IEV &= ~(1<<0); // ??P1.9????????
    LPC_GPIO3->IEV &= ~(1<<1); // ??P1.10????????
     
	  NVIC_EnableIRQ(EINT3_IRQn); 
    while(1)
    
        
		{;}
    
}
