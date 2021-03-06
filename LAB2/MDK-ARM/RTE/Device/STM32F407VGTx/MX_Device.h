/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 12/02/2018 21:42:28
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            16000000
#define MX_HSE_VALUE                            8000000
#define MX_EXTERNAL_CLOCK_VALUE                 12288000
#define MX_PLLCLKFreq_Value                     168000000
#define MX_SYSCLKFreq_VALUE                     168000000
#define MX_HCLKFreq_Value                       168000000
#define MX_FCLKCortexFreq_Value                 168000000
#define MX_CortexFreq_Value                     168000000
#define MX_AHBFreq_Value                        168000000
#define MX_APB1Freq_Value                       42000000
#define MX_APB2Freq_Value                       84000000
#define MX_APB1TimFreq_Value                    84000000
#define MX_APB2TimFreq_Value                    168000000
#define MX_48MHZClocksFreq_Value                48000000
#define MX_EthernetFreq_Value                   168000000
#define MX_I2SClocksFreq_Value                  96000000
#define MX_RTCFreq_Value                        32000
#define MX_WatchDogFreq_Value                   32000
#define MX_MCO1PinFreq_Value                    16000000
#define MX_MCO2PinFreq_Value                    168000000

/*-------------------------------- ADC1       --------------------------------*/

#define MX_ADC1                                 1

/* GPIO Configuration */

/* Pin PA1 */
#define MX_ADCx_IN1_Pin                         PA1
#define MX_ADCx_IN1_GPIOx                       GPIOA
#define MX_ADCx_IN1_GPIO_PuPd                   GPIO_NOPULL
#define MX_ADCx_IN1_GPIO_Pin                    GPIO_PIN_1
#define MX_ADCx_IN1_GPIO_Mode                   GPIO_MODE_ANALOG

/* NVIC Configuration */

/* NVIC ADC_IRQn */
#define MX_ADC_IRQn_interruptPremptionPriority  0
#define MX_ADC_IRQn_PriorityGroup               NVIC_PRIORITYGROUP_0
#define MX_ADC_IRQn_Subriority                  0

/*-------------------------------- DAC        --------------------------------*/

#define MX_DAC                                  1

/* GPIO Configuration */

/* Pin PA4 */
#define MX_COMP_DAC1_group_Pin                  PA4
#define MX_COMP_DAC1_group_GPIOx                GPIOA
#define MX_COMP_DAC1_group_GPIO_PuPd            GPIO_NOPULL
#define MX_COMP_DAC1_group_GPIO_Pin             GPIO_PIN_4
#define MX_COMP_DAC1_group_GPIO_Mode            GPIO_MODE_ANALOG

/*-------------------------------- I2C1       --------------------------------*/

#define MX_I2C1                                 1

/* GPIO Configuration */

/* Pin PB6 */
#define MX_I2C1_SCL_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_I2C1_SCL_Pin                         PB6
#define MX_I2C1_SCL_GPIOx                       GPIOB
#define MX_I2C1_SCL_GPIO_PuPdOD                 GPIO_PULLUP
#define MX_Audio_SCL_[CS43L22_SCL]              I2C1_SCL
#define MX_I2C1_SCL_GPIO_Pin                    GPIO_PIN_6
#define MX_I2C1_SCL_GPIO_AF                     GPIO_AF4_I2C1
#define MX_I2C1_SCL_GPIO_Mode                   GPIO_MODE_AF_OD

/* Pin PB9 */
#define MX_I2C1_SDA_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_I2C1_SDA_Pin                         PB9
#define MX_I2C1_SDA_GPIOx                       GPIOB
#define MX_I2C1_SDA_GPIO_PuPdOD                 GPIO_PULLUP
#define MX_Audio_SDA_[CS43L22_SDA]              I2C1_SDA
#define MX_I2C1_SDA_GPIO_Pin                    GPIO_PIN_9
#define MX_I2C1_SDA_GPIO_AF                     GPIO_AF4_I2C1
#define MX_I2C1_SDA_GPIO_Mode                   GPIO_MODE_AF_OD

/*-------------------------------- SPI1       --------------------------------*/

#define MX_SPI1                                 1

/* GPIO Configuration */

/* Pin PA6 */
#define MX_SPI1_MISO_GPIO_Speed                 GPIO_SPEED_FREQ_LOW
#define MX_SPI1_MISO_Pin                        PA6
#define MX_SPI1_MISO_GPIOx                      GPIOA
#define MX_SPI1_MISO_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI1_MISO_[LIS302DL_SDO]             SPI1_MISO
#define MX_SPI1_MISO_GPIO_Pin                   GPIO_PIN_6
#define MX_SPI1_MISO_GPIO_AF                    GPIO_AF5_SPI1
#define MX_SPI1_MISO_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PA7 */
#define MX_SPI1_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_LOW
#define MX_SPI1_MOSI_Pin                        PA7
#define MX_SPI1_MOSI_GPIOx                      GPIOA
#define MX_SPI1_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI1_MOSI_[LIS302DL_SDA_SDI_SDO]     SPI1_MOSI
#define MX_SPI1_MOSI_GPIO_Pin                   GPIO_PIN_7
#define MX_SPI1_MOSI_GPIO_AF                    GPIO_AF5_SPI1
#define MX_SPI1_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PA5 */
#define MX_SPI1_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_LOW
#define MX_SPI1_SCK_Pin                         PA5
#define MX_SPI1_SCK_GPIOx                       GPIOA
#define MX_SPI1_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI1_SCK_[LIS302DL_SCL_SPC]          SPI1_SCK
#define MX_SPI1_SCK_GPIO_Pin                    GPIO_PIN_5
#define MX_SPI1_SCK_GPIO_AF                     GPIO_AF5_SPI1
#define MX_SPI1_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/* Pin PA13 */
#define MX_SYS_JTMS-SWDIO_Pin                   PA13
#define MX_SWDIO                                SYS_JTMS-SWDIO

/* Pin PA14 */
#define MX_SYS_JTCK-SWCLK_Pin                   PA14
#define MX_SWCLK                                SYS_JTCK-SWCLK

/* Pin PB3 */
#define MX_SYS_JTDO-SWO_Pin                     PB3
#define MX_SWO                                  SYS_JTDO-SWO

/*-------------------------------- USB_HOST   --------------------------------*/

#define MX_USB_HOST                             1

/* GPIO Configuration */

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PD12 */
#define MX_PD12_GPIO_Speed                      GPIO_SPEED_FREQ_LOW
#define MX_PD12_Pin                             PD12
#define MX_PD12_GPIOx                           GPIOD
#define MX_PD12_PinState                        GPIO_PIN_RESET
#define MX_PD12_GPIO_PuPd                       GPIO_NOPULL
#define MX_LD4_[Green_Led]                      PD12
#define MX_PD12_GPIO_Pin                        GPIO_PIN_12
#define MX_PD12_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PD5 */
#define MX_PD5_Pin                              PD5
#define MX_PD5_GPIOx                            GPIOD
#define MX_PD5_GPIO_PuPd                        GPIO_NOPULL
#define MX_OTG_FS_OverCurrent                   PD5
#define MX_PD5_GPIO_Pin                         GPIO_PIN_5
#define MX_PD5_GPIO_Mode                        GPIO_MODE_INPUT

/* Pin PB2 */
#define MX_PB2_Pin                              PB2
#define MX_PB2_GPIOx                            GPIOB
#define MX_PB2_GPIO_PuPd                        GPIO_NOPULL
#define MX_BOOT1                                PB2
#define MX_PB2_GPIO_Pin                         GPIO_PIN_2
#define MX_PB2_GPIO_Mode                        GPIO_MODE_INPUT

/* Pin PD4 */
#define MX_PD4_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PD4_Pin                              PD4
#define MX_PD4_GPIOx                            GPIOD
#define MX_PD4_PinState                         GPIO_PIN_RESET
#define MX_PD4_GPIO_PuPd                        GPIO_NOPULL
#define MX_Audio_RST_[CS43L22_RESET]            PD4
#define MX_PD4_GPIO_Pin                         GPIO_PIN_4
#define MX_PD4_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PD14 */
#define MX_PD14_GPIO_Speed                      GPIO_SPEED_FREQ_LOW
#define MX_PD14_Pin                             PD14
#define MX_PD14_GPIOx                           GPIOD
#define MX_PD14_PinState                        GPIO_PIN_RESET
#define MX_PD14_GPIO_PuPd                       GPIO_NOPULL
#define MX_LD5_[Red_Led]                        PD14
#define MX_PD14_GPIO_Pin                        GPIO_PIN_14
#define MX_PD14_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PA0-WKUP */
#define MX_PA0_WKUP_Pin                         PA0_WKUP
#define MX_PA0_WKUP_GPIOx                       GPIOA
#define MX_PA0_WKUP_GPIO_PuPd                   GPIO_NOPULL
#define MX_B1_[Blue_PushButton]                 PA0_WKUP
#define MX_PA0_WKUP_GPIO_Pin                    GPIO_PIN_0
#define MX_PA0_WKUP_GPIO_ModeDefaultEXTI        GPIO_MODE_EVT_RISING

/* Pin PD13 */
#define MX_PD13_GPIO_Speed                      GPIO_SPEED_FREQ_LOW
#define MX_PD13_Pin                             PD13
#define MX_PD13_GPIOx                           GPIOD
#define MX_PD13_PinState                        GPIO_PIN_RESET
#define MX_PD13_GPIO_PuPd                       GPIO_NOPULL
#define MX_LD3_[Orange_Led]                     PD13
#define MX_PD13_GPIO_Pin                        GPIO_PIN_13
#define MX_PD13_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PC0 */
#define MX_PC0_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PC0_Pin                              PC0
#define MX_PC0_GPIOx                            GPIOC
#define MX_PC0_PinState                         GPIO_PIN_SET
#define MX_PC0_GPIO_PuPd                        GPIO_NOPULL
#define MX_OTG_FS_PowerSwitchOn                 PC0
#define MX_PC0_GPIO_Pin                         GPIO_PIN_0
#define MX_PC0_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PD15 */
#define MX_PD15_GPIO_Speed                      GPIO_SPEED_FREQ_LOW
#define MX_PD15_Pin                             PD15
#define MX_PD15_GPIOx                           GPIOD
#define MX_PD15_PinState                        GPIO_PIN_RESET
#define MX_PD15_GPIO_PuPd                       GPIO_NOPULL
#define MX_LD6_[Blue_Led]                       PD15
#define MX_PD15_GPIO_Pin                        GPIO_PIN_15
#define MX_PD15_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PE1 */
#define MX_PE1_Pin                              PE1
#define MX_PE1_GPIOx                            GPIOE
#define MX_PE1_GPIO_PuPd                        GPIO_NOPULL
#define MX_MEMS_INT2_[LIS302DL_INT2]            PE1
#define MX_PE1_GPIO_Pin                         GPIO_PIN_1
#define MX_PE1_GPIO_ModeDefaultEXTI             GPIO_MODE_EVT_RISING

/* Pin PE3 */
#define MX_PE3_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PE3_Pin                              PE3
#define MX_PE3_GPIOx                            GPIOE
#define MX_PE3_PinState                         GPIO_PIN_RESET
#define MX_PE3_GPIO_PuPd                        GPIO_NOPULL
#define MX_CS_I2C_SPI_[LIS302DL_CS_I2C_SPI]     PE3
#define MX_PE3_GPIO_Pin                         GPIO_PIN_3
#define MX_PE3_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

#endif  /* __MX_DEVICE_H */

