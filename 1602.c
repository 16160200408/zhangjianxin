#include "LPC11XX.H"
#include "string.h"
#define LCD_RS_LOW LPC_GPIO2->DATA &=~(1<<0)
#define LCD_RS_HIGH  LPC_GPIO2->DATA |=(1<<0)
#define LCD_RW_LOW LPC_GPIO2->DATA &=~(1<<1)
#define LCD_RS_HIGH LPC_GPIO2->DATA |=(1<<1)
#define LCD_RS_E_LOW LPC_GPIO2->DATA &=~(1<<2)
#define LCD_RS_E_HIGH LPC_GPIO2->DATA |=(1<<2)
#define LCD_DATAPORT LPC_GPIO2->DATA 
#define LCD_DATA_IN LPC_GPIO2->DATA &=~0xFF
#define LCD_DATA_OUT LPC_GPIO2->DATA |= 0xFF
static volatile unsigned int ticks=0;
void Delayms(unit16_t ms)
{
	SysTick->CTRL &=~(1<<2);
	SysTick->LOAD= 25000*ms-1;
	SysTick->VAL=0;
	SysTick->CTRL=((1<<1)|(1<<0));
	while(! ticks);
	ticks=0;
	SyTick->CTRL=0;	
}
void SyTick_Handler(void)
{
ticks++;

}
unit8_t Busy_Check()
{
unit8_t LCD_Status;
	LCD_RS_LOW;
	LCD_RW_HIGH;
	LCD_E_HIGH;
	Delayms(1);
	LCD_DATA_IN;
	
	LCD_Status= LCD_DATAPORT;
	LCD_DATA_OUT;
	LCD_E_LOW;
	return LCD_Status;
}
 void LCD_WriteCommand(uint8_t cmd)
 {
	 
	 while((Busy_Check()&0x80)==0x80);
	 LCD_RS_LOW;
	 LCD_RW_LOW;
	 LCD_E_LOW;
	 LCD_DADTAPORT=cmd;
	 Delayms(1);
	 LCD_E_HIGH;
	 Delayms(1);
	 LCD_E_LOW;
 
 


}
 
void LCD_WriteData(uint8_t dat){
	
	while((Busy_Check()&0x80)==0x80);
	LCD_RS_HIGH;
	LCD_RW_LOW;
	LCD_E_LOW;
	LCD_DATAPORT=dat;
	Delayms(1);
	LCD_E_HIGH;
	Delayms(1);
	LCD_E_LOW;
}
uint8_t LCD_DisplayChar(uint8_t x,uint8_t y,unit8_t_ch)
{
	if((y>2)||(x>16))
	{
	return 1;
	}
	x|=((y==1)?0xC0 : 0x80);
	LCD_WriteCommand(x);
	LCD_WriteData(ch);
	return 0;
	
}
	uint8_t LCD_DisplayStr(uint8_t x,uint8_t y,unit8_t*pStr)
{
	uint8_t i;
	uint8_t lineSdder[]={0x80,0xC0};
	if((y>=2)||(x>=16))
	{
	return 1;
	}
	LCD_WriteCommand(lineAdder[y]+x);
	  for(i=x;((i<16)&&(*pStr++!='\0'));i++);
	{
	LCD_WriteData(*(pStr++));
	
	}
	if(*pStr!='\0')
	{
	
	x=0;
		if(++y<2)
		{
		LCD_DisplayStr(x,y,pStr);	
			
		}
	}
	return 0;
	}
	
	void LCD_IOInit(void){
	
	LPC_GPIO2->DIR|=0xFF;
		//LPC_GPIO3->DIR|=0xFF;;
	
	
	
	}
	void InitLCD()
	
	{
	
	LCD_IOInit();
		LCD_WriteCommand(0x38);
		Delayms(1);
		LCD_WriteCommand(0x01);
		Delayms(1);
		LCD_WriteCommand(0x06);
		Delayms(1);
		LCD_WriteCommand(0x0c);
		Delayms(1);
		
	
	
	}
int main()
	{


InitLCD();
		while(1){
			
			LCD_DisplayStr(0,0,"Hello World! Hello Kitty!");
		}

}