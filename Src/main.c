#include "stm32f4xx.h"
#include <clock.h>
#include <pwm.h>


int main(void)
{
	uint16_t brightness = 0;
	int8_t direction = 1;
	uint32_t stepdelay = 5000;


	clock_Init();
	pwm_Init();

	while(1)
	{
		set_dutyCycle(brightness);

		brightness += direction;
		if(brightness >= TIM2->ARR)
		{
			direction = -1;
		}else if(brightness == 0){

			direction = 1;
		}

		for(volatile uint32_t i=0; i<stepdelay; i++){}

	}

}
