/*
 * HeadAndParingLights.c
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */

#include "HeadAndParkingLights.h"

void HeadAndParkingLights()
{
	RCC->AHB1ENR   |= (1<<2);      // GPIOC CLK ENABLE
	RCC->APB1ENR   |= (1<<1);      // TIM3 CLK ENABLE

    GPIOC->AFR[0]  &= ~(0xF<<24);   // clearing 4 bits
    GPIOC->AFR[0]  |= (1<<25);      // AF2 IN AFRL6

	GPIOC->MODER   &= ~( 3 << 12);  // mode clear LED1
	GPIOC->MODER   |= ( 1 << 13);   // GPIOC 01  as AF

	TIM3->PSC       = 0;
	TIM3->ARR       = 16000;

	TIM3->CCMR1    &= ~(3<<0);        // CC1S output mode 00
	TIM3->CCMR1    &= ~(7<<4);        // CCMR channel clear
	TIM3->CCMR1    |= (6<<4);         // PWM Mode 1
	TIM3->CCMR1    |= (1<<3);         // PE enable 1 3rd bit
	TIM3->CR1      |= (1<<7);         //ARPE Bit CR1
	TIM3->EGR      |= (1<<0);         // UG bit
    TIM3->CCER     |= (1<<0);         // enable channel
    TIM3->CNT       = 0;
	TIM3->CR1      |= (1<<0);
}
