/*
 * MemoryMapping.c
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */


#include "MemoryMapping.h"

void GPIOConfigurationForLED()
{
	//LED 1-PC 6
	GPIOC->MODER   &= ~(3<<12);     //Clear bit 12 and 13
	GPIOC->MODER   |= (1<<12);      //Setting bit 12

	//LED 2-PB13
	GPIOB->MODER   &= ~(3<<26);     //clearing pin12, 13
	GPIOB->MODER   |= (1<<26);      //01 -output mode

    //LED-3- PB 14
	GPIOB->MODER   &= ~(3<<28);     //BIT 28 AND 29 CLEAR FOR PB14
	GPIOB->MODER   |= (2<<28);      //AF MODE 10
	GPIOB->OTYPER  &= ~(1<<14);     //OTYPER PB14
	GPIOB->OSPEEDR &= ~(3<<28);     //CLEARING BITS
	GPIOB->OSPEEDR |= (1<<28);      //SETTING BITS
	GPIOB->AFR[1]  &= ~(0xF<<24);	// PB14 AFRH BITS CLEARING
	GPIOB->AFR[1]  |= (1<<24);	    // TIM1 CH3 PB14 AF
	RCC->APB2ENR   |= (1<<0);

	//LED-4 -PB 15
	GPIOB->MODER   &= ~(3<<30);      //clearing-00-> 13 12 GPIO pin12, 13
	GPIOB->MODER   |= (1<<30);       //01 -output mode
}

void GPIOConfigurationBuzzer()
{
	//Buzzer
	GPIOC->MODER  &= ~(3 << 18);      //clearing BUZZER PIN PC9
	GPIOC->MODER  |= (1 << 18);       //01 -output mode
}

void GPIOConfigurationSwitch()
{
	GPIOB->MODER &= ~(3<<14);          //PB7 AS INPUT-CLEARING BIT 14,15 FOR PB7-INPUT MODE=00 SWITCH1

	//PULL UP PULL DOWN REGISTER -00 NO PULL NO PULL DOWN
	GPIOB->PUPDR &= ~(3<<14);         //NO PULL UP NO PULL DOWN AT PB7
	GPIOB->MODER &= ~((3<<6)|(3<<8)); //SWITCH 2 AND SWITCH 3
	GPIOB->PUPDR &= ~((3<<6)|(3<<8));
	GPIOA->MODER &= ~(3<<30);         //SWITCH 2 AND SWITCH 3
	GPIOA->PUPDR &= ~(3<<30);
}

void GPIOConfiguration()
{
	RCC->AHB1ENR |= (7<<0);          //Enable GPIOB,GPIOC CLOCK

	GPIOConfigurationForLED();
	GPIOConfigurationBuzzer();
	GPIOConfigurationSwitch();
}
