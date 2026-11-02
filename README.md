STM32F401RE – Breathing LED

Bare-metal breathing LED implementation on the STM32F401RE in C with CMSIS, custom clock configuration, and TIM2 hardware PWM for brightness control.


## 1. Project Specifications

| Parameter | Value |
|---|---|
| Development board | NUCLEO-F401RE |
| Microcontroller | STM32F401RET6 (ARM Cortex-M4) |
| Programming | Bare-metal C / CMSIS (no HAL) |
| Development environment | STM32CubeIDE |
| LED | Onboard LD2 (Green) |
| PWM peripheral | TIM2 Channel 1 |
| PWM frequency | 500 Hz |
| System clock | 72 MHz (HSE + PLL) |
| Brightness control | PWM duty cycle via CCR1 |
| Timing | Software delay (SysTick planned) |

## 2. Pin Configuration

| Pin | Function | Configuration |
|---|---|---|
| PA5 | LD2 / TIM2_CH1 | Alternate Function AF1 |
| PH0 | HSE clock input | External 8 MHz clock (bypass) |

## 3. Clock Tree

Simplified Overview of the STM32F401 clock architecture.
<img width="521" height="316" alt="Bild 5  Nov  2026, 10_43_23" src="https://github.com/user-attachments/assets/e65e4e97-7aa6-470f-b4d1-426b0471e7fe" />

## 4. HSE Configuration

The STM32F401RE receives an external 8 MHz clock signal from the ST-LINK MCO output.
Since the clock is supplied externally, the HSE oscillator is configured in bypass mode.

## 5. PLL Configuration

The PLL generates a 72 MHz system clock from the 8 MHz HSE input.
<img width="290" height="292" alt="Bild 4  Nov  2026, 10_43_40" src="https://github.com/user-attachments/assets/3fcd6d89-d4a1-4bf6-b2c7-124cdc3e56c6" />
<img width="293" height="288" alt="Bild 3  Nov  2026, 10_43_48" src="https://github.com/user-attachments/assets/391dd385-3930-4261-96a9-b9467a776b43" />

## 6. AHB & APB Clock Configuration

The 72 MHz SYSCLK is distributed to the AHB and APB buses through the corresponding prescalers.

| Clock | Prescaler | Frequency |
|---|---|---|
| SYSCLK | — | 72 MHz |
| AHB / HCLK | /1 | 72 MHz |
| APB1 / PCLK1 | /2 | 36 MHz |
| APB2 / PCLK2 | /1 | 72 MHz |
| TIM2CLK | 2 × PCLK1 | 72 MHz |

<img width="280" height="311" alt="Bild 2  Nov  2026, 10_43_57" src="https://github.com/user-attachments/assets/2f73046b-0c1a-43f2-b698-ab9e85a6c787" />
<img width="293" height="322" alt="Bild 1  Nov  2026, 10_44_08" src="https://github.com/user-attachments/assets/f299e093-137f-48a1-b4f8-c7d6e8592b4a" />
