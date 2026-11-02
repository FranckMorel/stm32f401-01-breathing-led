/*
 * pwm.c
 *
 *  Created on: Oct 29, 2026
 *      Author: kzvvftre
 */


#include "stm32f4xx.h"


void pwm_Init()
{
	/*Enable Clock for GPIOA and TIM2*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*Config GPIOA in alternate function mode*/
	GPIOA->MODER &= ~(3U<<5U*2U);
	GPIOA->MODER |=  (2U<<5U*2U);

	/*Set PA5 to AF01*/
	GPIOA->AFR[0] &= ~(15U<<5U*4U);
	GPIOA->AFR[0] |=  (1U<<5U*4U);

	/*Set f= 500HZ, with Input frequency for TIM2 as 72MHZ*/
	TIM2->PSC = 72U - 1U;
	TIM2->ARR = 2000U - 1U;
	//TIM2->CCR1 = 0; /*Start with 0% Duty Cycle*/

	/*Config to PWM Mode1 */
	TIM2->CCMR1 &= ~(TIM_CCMR1_OC1M);
	TIM2->CCMR1 |= 	(6U<<4U);

	/*Enable PreLoad*/
	TIM2->CCMR1 |= TIM_CCMR1_OC1PE;

	TIM2->CCER |= TIM_CCER_CC1E; /*Enable CH1 output*/
	TIM2->CR1 |= TIM_CR1_CEN;    /*Start TIM2*/

}

void set_dutyCycle(uint32_t duty)
{
	if(duty > 1000U)
	{
		duty = 1000U;
	}

	TIM2->CCR1 = (duty * (TIM2->ARR + 1U))/1000U;
}
