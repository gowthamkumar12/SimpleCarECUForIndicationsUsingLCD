/*
 * Indicators.c
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */


#include "Indicators.h"

void RightIndicator()
{
	//LED-3- PB 14
	GPIOB->MODER   &= ~(3<<28);
	GPIOB->MODER   |= (2<<28);
	GPIOB->OTYPER  &= ~(1<<14);
	GPIOB->OSPEEDR &= ~(3<<28);
	GPIOB->OSPEEDR |= (1<<28);
	GPIOB->AFR[1]  &= ~(0xF<<24);	//clear PB14 AFRH bits
	GPIOB->AFR[1]  |= (1<<24);	    // PB14 alternate fn as TIM1 CH3
	RCC->APB2ENR   |= (1<<0);

	TIM1->PSC       = 3200-1;	    //prescalar register
	TIM1->ARR       = 10000-1;		// Timer Output 1KHz
	TIM1->CNT       = 0;			// Reset the Counter
	TIM1->CCMR1    &= ~(7<<12);		// Setting the PWM mode for TIM1 CH3 output
	TIM1->CCMR1    |= (6<<12);		// Channel 3N (Complement) active low polarity
	TIM1->CCER     |= (1<<7);
	TIM1->CCER     |= (1<<6);
	TIM1->BDTR     |= (1<<13)|(1<<15);	//Break Polarity High// main output enable
	TIM1->CR1      |= (1<<0);			// start timer1
}

void LeftIndicator()
{
	RCC->AHB1ENR   |= (1<<1);		// GPIOB clock enable
	GPIOB->MODER   &= ~(3<<30);		//clearing PB15 mode bits
	GPIOB->MODER   |= (2<<30);		// Alternate function for PB15
	GPIOB->OTYPER  &= ~(1<<15);		// PB15 push pull
	GPIOB->OSPEEDR &= ~(3<<30);		// PB15 clear speed
	GPIOB->OSPEEDR |= (1<<30);		// PB15 medium speed
	GPIOB->AFR[1]  &= ~(0xF<<28);	// clear PB15 AFRL bits
	GPIOB->AFR[1]  |= (1<<28);		// PB15 alternate function as TIM1 CH3
	RCC->APB2ENR   |= (1<<0);		// enable TIM1 clock in APB2


	TIM1->PSC       = 3200-1;
	TIM1->ARR       = 10000-1;			// Timer Output 1KHz
	TIM1->CNT       = 0; 			    // Resetting the Counter
	TIM1->CCMR2    &= ~(7<<4);			// Clearing Output mode in TIM1 CH3
	TIM1->CCMR2    |= (6<<4);			// Setting PWM mode for TIM1 CH3 output
	TIM1->CCER     |= (1<<11);			// Channel 3N (Complement) active low polarity
	TIM1->CCER     |= (1<<10);			// CH3 N connect to PB15
	TIM1->BDTR     |= (1<<13)|(1<<15);	// Break Polarity High
	TIM1->CR1      |= (1<<0);			// starting timer1
}
