/*
 * systick.c
 *
 *  Created on: Nov 2, 2026
 *      Author: kzvvftre
 */

#include "stm32f4xx.h"

static volatile uint32_t sysTick_ms;

void SysTick_Init()
{
	/*Disable Systick before Config*/
	SysTick->CTRL &=  ~SysTick_CTRL_ENABLE_Msk;

	/*Select Processor Clock (AHB) as clock source*/
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

	/*Enable interrupt Flag for when counter reaches 0*/
	SysTick->CTRL |=  SysTick_CTRL_TICKINT_Msk;

	/*Load 71999 for 1ms*/
	SysTick->LOAD = 72000U - 1U;

	/*Reset Systick counter; writing any Bit sets value to 0*/
	SysTick->VAL = 0U;

	/*Enable Systick*/
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Handler()
{

	sysTick_ms++;

}

uint32_t SysTick_GetMillis()
{

	return sysTick_ms;
}
