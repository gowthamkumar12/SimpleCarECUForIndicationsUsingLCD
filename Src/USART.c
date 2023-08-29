/*
 * UASRT.c
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */


#include "USART.h"

uint32_t abc,abc1;

void USARTInit()
{
	RCC->AHB1ENR  |= (1<<2);// GPIOC clk
	RCC->APB1ENR  |= (1<<18);//USART3 clk enable

	GPIOC->MODER  &= ~(3<<20); //pin 10 reset next alternate function mode
	GPIOC->MODER  |= (1<<21);  //AFRH is used and respective af no is set in arfh
	GPIOC->AFR[1] &= ~(0xF<<8);//AF7 0111 from the alternate function table
	GPIOC->AFR[1] |= (7<<8);

	GPIOC->MODER  &= ~(3<<22);// similar as 10pin to 11 pin of port b
	GPIOC->MODER  |= (1<<23);
	GPIOC->AFR[1] &= ~(0xF<<12);
	GPIOC->AFR[1] |= (7<<12);

	USART3->BRR    = 0x0683;// BRR value mantice and fraction part 9600 baud rate
	USART3->CR1   |= (3<<2);// enable the RE and TE bits
	USART3->CR2    = 0;// default setting
	USART3->CR3    = 0;
	USART3->CR1   |= (1<<13);//ENABLE UART3
}

void USARTWrite(uint8_t f_character)
{
	while (!(USART3->SR & (1<<7)))
	{
		abc1++;
		if(abc1==100)
		{
			abc1=0;
			break;
		}
	}

	USART3->DR = (f_character & 0xFF);
}

uint8_t USARTRead()
{
	while (!(USART3->SR & (1<<5)))
	{
		abc++;
		if(abc==100)
		{
			abc=0;
			break;
		}
	}

	return USART3->DR; //return to data register
}
