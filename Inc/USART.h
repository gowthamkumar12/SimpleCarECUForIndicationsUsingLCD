/*
 * USART.h
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */

#ifndef USART_H_
#define USART_H_

#include "MemoryMapping.h"

void USARTInit();
void USARTWrite(uint8_t f_character);
uint8_t USARTRead();

#endif /* USART_H_ */
