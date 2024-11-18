/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2018, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

//==============================================================================
// Notes
//
// - The pins mentioned Px_y_ALTz are alternative possibilities which use other
//   HW peripheral instances. You can use them the same way as any other "normal"
//   pin (i.e. PwmOut pwm(PA_7_ALT0);). These pins are not displayed on the board
//   pinout image on mbed.org.
//
// - The pins which are connected to other components present on the board have
//   the comment "Connected to xxx". The pin function may not work properly in this
//   case. These pins may not be displayed on the board pinout image on mbed.org.
//   Please read the board reference manual and schematic for more information.
//
// - Warning: pins connected to the default STDIO_UART_TX and STDIO_UART_RX pins are commented
//   See https://os.mbed.com/teams/ST/wiki/STDIO for more information.
//
//==============================================================================

// Port AF0 AF1 AF2 AF3 AF4 AF5 AF6 AF7
// PA0 SPI2_SCK USART2_CTS - - USART4_TX - - - 
// PA1 SPI1_SCK/ I2S1_CK USART2_RTS _DE_CK - - USART4_RX TIM15_CH1N I2C1_SMBA EVENTOUT 
// PA2 SPI1_MOSI/ I2S1_SD USART2_TX - - - TIM15_CH1 - - 
// PA3 SPI2_MISO USART2_RX - - - TIM15_CH2 - EVENTOUT 
// PA4 SPI1_NSS/ I2S1_WS SPI2_MOSI - - TIM14_CH1 - - EVENTOUT 
// PA5 SPI1_SCK/ I2S1_CK - - - USART3_TX - - EVENTOUT 
// PA6 SPI1_MISO/ I2S1_MCK TIM3_CH1 TIM1_BKIN - USART3_CTS TIM16_CH1 - - 
// PA7 SPI1_MOSI/ I2S1_SD TIM3_CH2 TIM1_CH1N - TIM14_CH1 TIM17_CH1 - - 
// PA8 MCO SPI2_NSS TIM1_CH1 - - - - EVENTOUT 
// PA9 MCO USART1_TX TIM1_CH2 - SPI2_MISO TIM15_BKIN I2C1_SCL EVENTOUT
// PA10 SPI2_MOSI USART1_RX TIM1_CH3 - - TIM17_BKIN I2C1_SDA EVENTOUT
// PA11 SPI1_MISO/ I2S1_MCK USART1_CTS TIM1_CH4 - - TIM1_BKIN2 I2C2_SCL -
// PA12 SPI1_MOSI/ I2S1_SD USART1_RTS _DE_CK TIM1_ETR - - I2S_CKIN I2C2_SDA -
// PA13 SWDIO IR_OUT - - - - - EVENTOUT
// PA14 SWCLK USART2_TX - - - - - EVENTOUT
// PA15 SPI1_NSS/ I2S1_WS USART2_RX - - USART4_RTS _DE_CK USART3_RTS _DE_CK - EVENTOUT
// PB0 SPI1_NSS/ I2S1_WS TIM3_CH3 TIM1_CH2N - USART3_RX - - -
// PB1 TIM14_CH1 TIM3_CH4 TIM1_CH3N - USART3_RTS _DE_CK - - EVENTOUT
// PB2 - SPI2_MISO - - USART3_TX - - EVENTOUT
// PB3 SPI1_SCK/ I2S1_CK TIM1_CH2 - - USART1_RTS _DE_CK - - EVENTOUT
// PB4 SPI1_MISO/ I2S1_MCK TIM3_CH1 - - USART1_CTS TIM17_BKIN - EVENTOUT
// PB5 SPI1_MOSI/ I2S1_SD TIM3_CH2 TIM16_BKIN - - - I2C1_SMBA -
// PB6 USART1_TX TIM1_CH3 TIM16_CH1N - SPI2_MISO - I2C1_SCL EVENTOUT
// PB7 USART1_RX SPI2_MOSI TIM17_CH1N - USART4_CTS - I2C1_SDA EVENTOUT
// PB8 - SPI2_SCK TIM16_CH1 - USART3_TX TIM15_BKIN I2C1_SCL EVENTOUT
// PB9 IR_OUT - TIM17_CH1 - USART3_RX SPI2_NSS I2C1_SDA EVENTOUT
// PB10 - - - - USART3_TX SPI2_SCK I2C2_SCL -
// PB11 SPI2_MOSI - - - USART3_RX - I2C2_SDA -
// PB12 SPI2_NSS - TIM1_BKIN - - TIM15_BKIN - EVENTOUT
// PB13 SPI2_SCK - TIM1_CH1N - USART3_CTS TIM15_CH1N I2C2_SCL EVENTOUT
// PB14 SPI2_MISO - TIM1_CH2N - USART3_RTS _DE_CK TIM15_CH1 I2C2_SDA EVENTOUT
// PB15 SPI2_MOSI - TIM1_CH3N - TIM15_CH1N TIM15_CH2 - EVENTOUT
// PC0 - - - - - - - - 
// PC1 - - TIM15_CH1 - - - - - 
// PC2 - SPI2_MISO TIM15_CH2 - - - - - 
// PC3 - SPI2_MOSI - - - - - - 
// PC4 USART3_TX USART1_TX - - - - - - 
// PC5 USART3_RX USART1_RX - - - - - - 
// PC6 - TIM3_CH1 - - - - - - 
// PC7 - TIM3_CH2 - - - - - - 
// PC8 - TIM3_CH3 TIM1_CH1 - - - - - 
// PC9 I2S_CKIN TIM3_CH4 TIM1_CH2 - - - - - 
// PC10 USART3_TX USART4_TX TIM1_CH3 - - - - - 
// PC11 USART3_RX USART4_RX TIM1_CH4 - - - - - 
// PC12 - - TIM14_CH1 - - - - - 
// PC13 - - TIM1_BKIN - - - - -
// PC14 - - TIM1_BKIN2 - - - - -
// PC15 OSC32_EN OSC_EN TIM15_BKIN - - - - -
// PD0 EVENTOUT SPI2_NSS TIM16_CH1 - - - - -
// PD1 EVENTOUT SPI2_SCK TIM17_CH1 - - - - -
// PD2 USART3_RTS _DE_CK TIM3_ETR TIM1_CH1N - - - - -
// PD3 USART2_CTS SPI2_MISO TIM1_CH2N - - - - -
// PD4 USART2_RTS _DE_CK SPI2_MOSI TIM1_CH3N - - - - -
// PD5 USART2_TX SPI1_MISO/ I2S1_MCK TIM1_BKIN - - - - -
// PD6 USART2_RX SPI1_MOSI/ I2S1_SD ------
// PD8 USART3_TX SPI1_SCK/ I2S1_CK ------
// PD9 USART3_RX SPI1_NSS/ I2S1_WS TIM1_BKIN2 - - - - -
// PF0 - - TIM14_CH1 - - - - -
// PF1 OSC_EN - TIM15_CH1N - - - - -


#ifndef MBED_PERIPHERALPINMAPS_H
#define MBED_PERIPHERALPINMAPS_H

#include "PinNamesTypes.h"
#include <mstd_cstddef>

//*** ADC ***

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_ADC[] = {
    {PA_0,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 0, 0)}, // ADC1_IN0
    {PA_1,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC1_IN1 
    {PA_2,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC1_IN2 
    {PA_3,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0)}, // ADC1_IN3
    {PA_4,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0)}, // ADC1_IN4
    {PA_5,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 5, 0)}, // ADC1_IN5
    {PA_6,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)}, // ADC1_IN6
    {PA_7,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 7, 0)}, // ADC1_IN7
    {PB_0,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 8, 0)}, // ADC1_IN8 
    {PB_1,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 9, 0)}, // ADC1_IN9
    {PB_2,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 10, 0)}, // ADC1_IN10
    {PB_10,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 11, 0)}, // ADC1_IN11
    {PB_11,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 15, 0)}, // ADC1_IN15
    {PB_12,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 16, 0)}, // ADC1_IN16
    {PC_4,       ADC_1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 17, 0)}, // ADC1_IN17
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_ADC_Internal[] = {
    {ADC_TEMP,   ADC_1,    STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 12, 0)},
    {ADC_VREF,   ADC_1,    STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 13, 0)},
    {ADC_VBAT,   ADC_1,    STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 14, 0)},
    {NC, NC, 0}
};

//*** DAC ***

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_DAC[] = {

    {NC, NC, 0}
};

//*** I2C ***

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_I2C_SDA[] = {
    {PA_10,       I2C_1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
    {PB_7,       I2C_1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
    {PB_9,      I2C_1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},

    {PB_11,       I2C_2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C2)},
    {PB_14,      I2C_2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C2)},
    {PA_2,      I2C_2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C2)},

    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_I2C_SCL[] = {

    {PA_9,       I2C_1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
    {PB_6,       I2C_1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
    {PB_8,       I2C_1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},

    {PA_11,       I2C_2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C2)},
    {PB_10,       I2C_2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C2)},
    {PB_13,       I2C_2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C2)},
    {NC, NC, 0}
};

//*** PWM ***

//TIM3, 14, 15, 16, 17 can be used for PWM
//@todo add rest of PWM complementary channels

// TIM5 cannot be used because already used by the us_ticker
MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_PWM[] = {
    {PA_6,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 1, 0)}, // TIM3_CH1
    {PB_4,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 1, 0)}, // TIM3_CH1
    {PC_6,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 1, 0)}, // TIM3_CH1

    {PA_7,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 2, 0)}, // TIM3_CH2
    {PB_5,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 2, 0)}, // TIM3_CH2
    {PC_7,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 2, 0)}, // TIM3_CH2

    {PB_0,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 3, 0)}, // TIM3_CH3
    {PC_8,       PWM_3,  STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF1_TIM3, 3, 0)}, // TIM3_CH3
    //@todo 

    {NC, NC, 0}
};

//*** SERIAL ***

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_UART_TX[] = {
    {PA_9,       UART_1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
    {PC_4,       UART_1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},

    {PA_2,       UART_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART2)},
    
    {PB_2,       UART_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF4_USART3)},
    {PC_4,       UART_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_USART3)},
    //@todo
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_UART_RX[] = {
    {PA_10,      UART_1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)}, 
    {PC_5,       UART_1,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},

    {PA_3,       UART_2,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART2)},

    {PB_0,       UART_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF4_USART3)},
    {PC_5,       UART_3,  STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_USART3)},
    //@todo
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_UART_RTS[] = {
    //@todo
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_UART_CTS[] = {
    //@todo
    {NC, NC, 0}
};

//*** SPI ***

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_SPI_MOSI[] = {
    {PA_7,       SPI_1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF0_SPI1)}, 
    //@todo
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_SPI_MISO[] = {
    {PA_6,       SPI_1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF0_SPI1)},
    //@todo
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_SPI_SCLK[] = {
    {PA_5,       SPI_1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, GPIO_AF0_SPI1)},
    //@todo
    {NC, NC, 0}
};

MSTD_CONSTEXPR_OBJ_11 PinMap PinMap_SPI_SSEL[] = {
    //@todo
    {NC, NC, 0}
};



#define PINMAP_ANALOGIN PinMap_ADC
#define PINMAP_ANALOGIN_INTERNAL PinMap_ADC_Internal
#define PINMAP_ANALOGOUT PinMap_DAC
#define PINMAP_I2C_SDA PinMap_I2C_SDA
#define PINMAP_I2C_SCL PinMap_I2C_SCL
#define PINMAP_UART_TX PinMap_UART_TX
#define PINMAP_UART_RX PinMap_UART_RX
#define PINMAP_UART_CTS PinMap_UART_CTS
#define PINMAP_UART_RTS PinMap_UART_RTS
#define PINMAP_SPI_SCLK PinMap_SPI_SCLK
#define PINMAP_SPI_MOSI PinMap_SPI_MOSI
#define PINMAP_SPI_MISO PinMap_SPI_MISO
#define PINMAP_SPI_SSEL PinMap_SPI_SSEL
#define PINMAP_PWM PinMap_PWM

#endif
