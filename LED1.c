/*************************************************************************/ 
#include "LPC11XX.H"							// ???

#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0)) 	// ?????P1.0?LED
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0)) 		// ?????P1.0?LED
#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1)) 	// ?????P1.1?LED
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1)) 		// ?????P1.1?LED
#define LED3_ON()  (LPC_GPIO2->DATA &= ~(1<<2)) 	// ?????P1.0?LED
#define LED3_OFF() (LPC_GPIO2->DATA |= (1<<2)) 		// ?????P1.0?LED
#define LED4_ON()  (LPC_GPIO2->DATA &= ~(1<<3)) 	// ?????P1.1?LED
#define LED4_OFF() (LPC_GPIO2->DATA |= (1<<3)) 		// ?????P1.1?LED
#define LED5_ON()  (LPC_GPIO2->DATA &= ~(1<<4)) 	// ?????P1.0?LED
#define LED5_OFF() (LPC_GPIO2->DATA |= (1<<4)) 		// ?????P1.0?LED
#define LED6_ON()  (LPC_GPIO2->DATA &= ~(1<<5)) 	// ?????P1.1?LED
#define LED6_OFF() (LPC_GPIO2->DATA |= (1<<5)) 		// ?????P1.1?LED
#define LED7_ON()  (LPC_GPIO2->DATA &= ~(1<<6)) 	// ?????P1.0?LED
#define LED7_OFF() (LPC_GPIO2->DATA |= (1<<6)) 		// ?????P1.0?LED
#define LED8_ON()  (LPC_GPIO2->DATA &= ~(1<<7)) 	// ?????P1.1?LED
#define LED8_OFF() (LPC_GPIO2->DATA |= (1<<7)) 		// ?????P1.1?LED
/**************************************************************************
* FunctionName   : Delay()
* Description    : ????
* EntryParameter : None
* ReturnValue    : None
**************************************************************************/
void Delay()
{
	uint16_t i,j;
	for(i=0;i<5000;i++)
		for(j=0;j<200;j++);
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
	LPC_IOCON->PIO2_0 |= 0x01; //?P1.0????GPIO
	LPC_IOCON->PIO2_1 &= ~0x07;	
	LPC_IOCON->PIO2_1 |= 0x01; //?P1.1????GPIO
	LPC_IOCON->PIO2_2 &= ~0x07;    
	LPC_IOCON->PIO2_2 |= 0x01; //?P1.0????GPIO
	LPC_IOCON->PIO2_3 &= ~0x07;    
	LPC_IOCON->PIO2_3 |= 0x01; //?P1.0????GPIO
	LPC_IOCON->PIO2_4 &= ~0x07;    
	LPC_IOCON->PIO2_4 |= 0x01; //?P1.0????GPIO
	LPC_IOCON->PIO2_5 &= ~0x07;    
	LPC_IOCON->PIO2_5 |= 0x01; //?P1.0????GPIO
	LPC_IOCON->PIO2_6 &= ~0x07;    
	LPC_IOCON->PIO2_6 |= 0x01; //?P1.0????GPIO
	LPC_IOCON->PIO2_7 &= ~0x07;    
	LPC_IOCON->PIO2_7 |= 0x01; //?P1.0????GPIO
	
	
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // ??IOCON??
	
	LPC_GPIO2->DIR |= (1<<0); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<0); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<1); // ?P1.1???????
	LPC_GPIO2->DATA |= (1<<1); // ?P1.1??????
	LPC_GPIO2->DIR |= (1<<2); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<2); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<3); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<3); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<4); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<4); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<5); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<5); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<6); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<6); // ?P1.0??????
	LPC_GPIO2->DIR |= (1<<7); // ?P1.0???????
	LPC_GPIO2->DATA |= (1<<7); // ?P1.0??????
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
		Delay();
		LED1_ON();
		LED2_OFF();
		LED3_OFF();
		LED4_OFF();
		LED5_OFF();
		LED6_OFF();
		LED7_OFF();
		LED8_OFF();
		
		Delay();
		LED1_OFF();
		LED2_ON();
		LED3_OFF();
		LED4_OFF();
		LED5_OFF();
		LED6_OFF();
		LED7_OFF();
		LED8_OFF();
		Delay();
			LED1_OFF();
		LED2_OFF();
		LED3_ON();
		LED4_OFF();
		LED5_OFF();
		LED6_OFF();
		LED7_OFF();
		LED8_OFF();
		Delay();
			LED1_OFF();
		LED2_OFF();
		LED3_OFF();
		LED4_ON();
		LED5_OFF();
		LED6_OFF();
		LED7_OFF();
		LED8_OFF();
		Delay();
			LED1_OFF();
		LED2_OFF();
		LED3_OFF();
		LED4_OFF();
		LED5_ON();
		LED6_OFF();
		LED7_OFF();
		LED8_OFF();
		Delay();
			LED1_OFF();
		LED2_OFF();
		LED3_OFF();
		LED4_OFF();
		LED5_OFF();
		LED6_ON();
		LED7_OFF();
		LED8_OFF();
		Delay();
			LED1_OFF();
		LED2_OFF();
		LED3_OFF();
		LED4_OFF();
		LED5_OFF();
		LED6_OFF();
		LED7_ON();
		LED8_OFF();
		Delay();
			LED1_OFF();
		LED2_OFF();
		LED3_OFF();
		LED4_OFF();
		LED5_OFF();
		LED6_OFF();
		LED7_OFF();
		LED8_ON();
	} 
}
