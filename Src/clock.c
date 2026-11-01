/*
 * clock.c
 *
 *  Created on: Oct 29, 2026
 *      Author: kzvvftre
 */


#include "stm32f4xx.h"
#include <clock.h>

void HSE_Init()
{
	/*HSE disable*/
	RCC->CR &= ~RCC_CR_HSEON;

	/*oscillator bypassed with an external clock, 8MHZ aus STLink Quarz*/
	RCC->CR |= RCC_CR_HSEBYP;

	/*HSE enable*/
	RCC->CR |= RCC_CR_HSEON;

	/*Wait till HSE Oszi stable/ready*/
	while(!(RCC->CR & RCC_CR_HSERDY))
	{

	}
}

void PLL_Init()
{
	/*PLL disable before config*/
	RCC->CR &= ~RCC_CR_PLLON;

	/*Set PLLM to 4, Input frequency = 8MHZ/4 = 2MHZ*/
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM);
	RCC->PLLCFGR |=  (4U<<RCC_PLLCFGR_PLLM_Pos);

	/*Set PLLN to 216*/
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |=  (216U<<RCC_PLLCFGR_PLLN_Pos);

	/*Set PLLP to 6*/
	RCC->PLLCFGR &=  ~(RCC_PLLCFGR_PLLP);
	RCC->PLLCFGR |=   (2U<<RCC_PLLCFGR_PLLP_Pos);

	/*Set HSE oscillator clock as PLL clock entry*/
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;

	/*enable PLL*/
	RCC->CR |= RCC_CR_PLLON;

	/*Wait till PLL ready*/
	while(!(RCC->CR & RCC_CR_PLLRDY))
	{

	}
}

void FLASH_Init()
{
	/*Set 2 Waits for flash latency*/
	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	FLASH->ACR |=  (2U<<FLASH_ACR_LATENCY_Pos);

	/*Wait till the 2 waits have actually been loaded*/
	while ((FLASH->ACR & FLASH_ACR_LATENCY) != (2U << FLASH_ACR_LATENCY_Pos))
	{

	}
}

void SYSCLK_Init()
{

	/*Configure AHB Presc*/
	RCC->CFGR &= ~(RCC_CFGR_HPRE);

	/*Configure APB1 Presc, AHB devided by 2*/
	RCC->CFGR &= ~(RCC_CFGR_PPRE1);
	RCC->CFGR |=   RCC_CFGR_PPRE1_DIV2;

	/*Configure APB2 Presc, AHB not divided*/
	RCC->CFGR &= ~(RCC_CFGR_PPRE2);

	/*Set SYSCLK as System clock*/
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |=   RCC_CFGR_SW_PLL;

	/*Wait till PLL ist used as System clock*/
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
	{

	}

}

void clock_Init()
{
	 HSE_Init();
	 PLL_Init();
	 FLASH_Init();
	 SYSCLK_Init();

	 //SystemCoreClockUpdate();
}
