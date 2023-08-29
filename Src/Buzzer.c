/*
 * Buzzer.c
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */


#include "Buzzer.h"

void Buzzer()
{
	RCC->AHB1ENR   |=  (1<<2);    // GPIOC clock enable
	RCC->APB1ENR   |=  (1<<1);    // TIM3 clock enable

	GPIOC->AFR[1]  &= ~(0xF<<4);  // clearing  4 bits
	GPIOC->AFR[1]  |= (1<<5);     // AF2 IN AFRL6

	GPIOC->MODER   &= ~( 3 << 18);// mode clear LED1
	GPIOC->MODER   |= ( 1 << 19); //GPIOC 01  as AF

	TIM3->PSC       = 3200-1;
	TIM3->ARR       = 10000-1;

	TIM3->CCMR2    &= ~(3<<10);   // CC1S output mode 00
	TIM3->CCMR2    &= ~(7<<12);   // CCMR2 channel clear
	TIM3->CCMR2    |= (6<<12);     // PWM Mode 1
	TIM3->CCMR2    |= (1<<11);     // PE enable 1 3rd bit
	TIM3->CR1      |= (1<<0);      //ARPE Bit CR1
	TIM3->EGR      |= (1<<4);     // UG bit
	TIM3->CCER     |= (1<<12);    // enable channel in
	TIM3->CNT       = 0;
	TIM3->CR1      |= (1<<0);     //starting timer1
}
void BuzzerON()
{
	Buzzer();
	TIM3->CCR4      = (uint32_t) TIM3->ARR * 50/100;
}

void BuzzerOFF()
{
	Buzzer();
	TIM3->CCR4      = (uint32_t) TIM3->ARR * 0/100;
}
