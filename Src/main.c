#include "stm32f4xx.h"
#include <clock.h>
#include <pwm.h>
#include <systick.h>

int main(void)
{

	uint16_t brightness = 500; /*0 - 1000*/
	int8_t direction = 1;

	clock_Init();
	SysTick_Init();
	pwm_Init();

	uint32_t lastTime = SysTick_GetMillis();

	while(1)
	{
		set_dutyCycle(brightness);


		if(SysTick_GetMillis() - lastTime >= 2){
			brightness += direction;
			if(brightness >= 1000)
			{
				direction = -1;
			}else if(brightness == 0){

				direction = 1;
			}

			lastTime = SysTick_GetMillis();
		}

	}

}
