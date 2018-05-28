#ifndef _LED999_H
#define _LED999_H
#include "LPC11XX.h"							// ???
void Delay();
void LedInit(void);
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
#endif