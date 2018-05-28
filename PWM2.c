#include "LPC11XX.H"


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

void CT32B1_Init(uint32_t interval)
{
		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);
		LPC_IOCON->R_PIO1_2 &= ~(0x07);
		LPC_IOCON->R_PIO1_2 |= 0x03;
		LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);
		LPC_SYSCON->SYSAHBCLKCTRL |= (1<<10);
		LPC_TMR32B1->TCR = 0x02;
		LPC_TMR32B1->PR = 0;
		LPC_TMR32B1->MCR = 0x02<<9;
		LPC_TMR32B1->PWMC = 0x02;
		LPC_TMR32B1->MR1 = interval/2;
		LPC_TMR32B1->MR3 = interval;
		LPC_TMR32B1->TCR = 0x01;

}
/********************************************************************************
* FunctionName   : PIOINT1_IRQHandler()
* Description    : P1???????
* EntryParameter : None
* ReturnValue    : None
********************************************************************************/


extern int i=5;
void PIOINT3_IRQHandler()
{
    if(KEY1_DOWN()) // ???P1.9?????
    {
			Delay();
				if(KEY1_DOWN())
					{
						i-=1;
						if(i<1){
							i=1;}
						else
							{
								LPC_TMR32B1->MR1 = ((SystemCoreClock/1000)/10)*i;
							}
					}
				
        LPC_GPIO3->IC = (1<<0);  // ???
    }
    if(KEY2_DOWN()) // ???P1.10?????
    {
			Delay();
			if(KEY2_DOWN())
			{
				i+=1;
						if(i>10)
						i=10;
						else
						LPC_TMR32B1->MR1 = ((SystemCoreClock/1000)/10)*i;
					}
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
			CT32B1_Init(SystemCoreClock/1000);
	
	
    while(1)
    
        
		{;}
    
}