/*************************************************************************/ 
#include "LPC11XX.H"							// ???

#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0)) 	// ?????P1.0?LED
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0)) 		// ?????P1.0?LED
#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1)) 	// ?????P1.1?LED
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1)) 		// ?????P1.1?LED
#define LED3_ON()  (LPC_GPIO2->DATA &= ~(1<<2)) 	// ?????P1.0?LED
#define LED3_OFF() (LPC_GPIO2->DATA |= (1<<2)) 		// ?????P1.0?LED

/**************************************************************************
* FunctionName   : Delay()
* Description    : ????
* EntryParameter : None
* ReturnValue    : None
**************************************************************************/
	void Delay()
{
	uint32_t i=6000000;
	while(i--);
}
	void Delay2()
{
	uint32_t j=4000000;
	while(j--);
}

/**************************************************************************
* FunctionName   : LedInit()
* Description    : ???LED??
* EntryParameter : None
* ReturnValue    : None
**************************************************************************/
void LedInit(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // ??IOCON?? 
	LPC_IOCON->PIO2_0 &= ~0x07;    
	LPC_IOCON->PIO2_0 |= 0x00; //?P1.0????GPIO
	LPC_IOCON->PIO2_1 &= ~0x07;	
	LPC_IOCON->PIO2_1 |= 0x00; //?P1.1????GPIO
	LPC_IOCON->PIO2_2 &= ~0x07;    
	LPC_IOCON->PIO2_2 |= 0x00; //?P1.0????GPIO

	
	
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // ??IOCON??
	
	LPC_GPIO2->DIR |= (1<<0); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<0); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<1); // ?P1.1???????
	LPC_GPIO2->DATA |= (1<<1); // ?P1.1??????
	LPC_GPIO2->DIR |= (1<<2); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<2); // ?P1.0??????

}
/**************************************************************************
* FunctionName   : main()
* Description    : ???
* EntryParameter : None
* ReturnValue    : None
**********************************************************************/
int main(void) 
{	
	LedInit();
	while(1)
	{
	   
		LED1_ON();
			Delay();
		LED1_OFF();
			Delay2();
			LED1_ON();
	Delay2();
		LED1_OFF();
		Delay2();
			LED1_ON();
	Delay2();
		LED1_OFF();
		  
		LED2_ON();
			Delay();
		LED2_OFF();
			Delay2();
			LED2_ON();
	Delay2();
		LED2_OFF();
				Delay2();
			LED2_ON();
	Delay2();
		LED2_OFF();
		
		
		  
		LED3_ON();
			Delay();
		LED3_OFF();
			Delay2();
			LED3_ON();
	Delay2();
		LED3_OFF();
			Delay2();
			LED3_ON();
	Delay2();
		LED3_OFF();
		
	} 
}