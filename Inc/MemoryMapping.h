/*
 * MemoryMapping.h
 *
 *  Created on: Aug 28, 2023
 *      Author: UWF1KOR
 */

#ifndef MEMORYMAPPING_H_
#define MEMORYMAPPING_H_

#include <stdint.h>
#include "stm32f405xx.h"

void GPIOConfigurationForLED();
void GPIOConfigurationForBuzzer();
void GPIOConfigurationForSwitch();
void GPIOConfiguration();

#endif /* MEMORYMAPPING_H_ */
