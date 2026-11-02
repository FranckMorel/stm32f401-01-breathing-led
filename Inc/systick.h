/*
 * systick.h
 *
 *  Created on: Nov 2, 2026
 *      Author: kzvvftre
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

void SysTick_Init();
void SysTick_Handler();
uint32_t SysTick_GetMillis();

#endif /* SYSTICK_H_ */
