/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
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
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

// Group 17 
// Tiffany Wang 260684152
// Isaac Chan 260624096


#include "stm32f4xx_hal.h"
#include "adc.h"
#include "gpio.h"
#include "arm_math.h"

 
#define SAMPLINGCOUNTER 10*/
#define PROCESSINGCOUNTER 200
#define DISPLAYINGCOUNTER 1
#define ALARMCOUNTER 100
#define TEMPERATURETHRESHOLD 30


/* Private variables ---------------------------------------------------------*/

volatile int systick_flag;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void initialize_ADC(void);
void initialize_GPIO_segments(void);
void initialize_GPIO_digits(void);
void initialize_GPIO_dp(void);
void initialize_GPIO_alarms(void);
float function_ADC(void);
float tempConversion(float);
void alarm_overheating(void);
void led_display(float,int);
void led_number(int);
void led_unit(char);
float celsius_to_farenheit (float);
void initialize_GPIO_button(void);
// Function header declaration
void FIR_C(int input, float* output);
void asm_math(float* p1, float* p2, int length);
void c_math(float* p1, float* p2, int length);
void cmsis_math(float* input, float* output, int len);


// Global Variables
//============================== TEST INPUT ARRAY - TO BE UPDATED BY TA ==============================
int Input[100] = {12,19,34,50,63,83,74,86,99,101,103,117,114,103,117,94,105,85,82,67,67,46,41,31,14,-1,-6,-14,-28,-42,-46,-56,-69,-79,-90,-88,-87,-86,-86,-96,-82,-80,-67,-62,-62,-38,-41,-28,-10,3,12,19,34,50,63,83,74,86,99,101,103,117,114,103,117,94,105,85,82,67,67,46,41,31,14,-1,-6,-14,-28,-42,-46,-56,-69,-79,-90,-88,-87,-86,-86,-96,-82,-80,-67,-62,-62,-38,-41,-28,-10,3};

//============================== TEST INPUT ARRAY - TO BE UPDATED BY TA ==============================
int input_len = (int)( sizeof(Input) / sizeof(Input[0]) );
float coeff[5] = {0.1,0.15,0.5,0.15,0.1};
int coeff_len = 5;
int x[5] = {0, 0, 0, 0, 0};

int main(void)
{	
	
	
	/*
	// initialize variables
	float adc_value,temperature;

	// initialize counters for sampling, processing, and displaying
	int sampling_count=0;
	int processing_count=0;
	int digit_count=0;
	int displaying_count=0;
	int alarm_count=0;
	float filteredVoltage[15];
	
  // Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

	/* Configure the system clock */
  //SystemClock_Config();
 
	/*Initialize*/
	
	
	initialize_ADC();
	initialize_GPIO_segments();
	initialize_GPIO_digits();
	initialize_GPIO_dp();	
	initialize_GPIO_alarms();	
	initialize_GPIO_button();


/* Infinite loop */

/*
 while (1)
  {
		// read button input
		GPIO_PinState currentState= GPIO_PIN_RESET;
		GPIO_PinState nextState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		
		//execute the code only at interrupts
		if(systick_flag==1){
			//set interrupt back to zero
			systick_flag=0;

			// sample only when sampling count hits the number of sampling counter (10ms) 
			if(sampling_count++ >= SAMPLINGCOUNTER){
				//reset counter
				sampling_count=0;
				//fetch ADC value
				adc_value = function_ADC();
				printf("the adc_value is: %f \n", adc_value);
				
				if(filterArrayCounter<=15){					
					//store the adc_value at the array
					inputArray[filterArrayCounter]=adc_value;
					filterArrayCounter++;
				}else{
					filterArrayCounter=0;
				}
			}
			
			// process only when processing counter hits the number of processing counter (200ms)
			if(processing_count++ >=PROCESSINGCOUNTER){
				processing_count=0;
		
				//filter the sampled voltage
				FIR_C(inputArray, filteredVoltage, coeff,15,4);		
				for (int i =0;i<15;i++){
				printf("the filteredVoltage is: %f \n", filteredVoltage[i]);
				}
	
				//set temperature
//			temperature=tempConversion(*filteredVoltage);
				temperature=tempConversion(adc_value);

				printf("the temperature (F) is: %f \n", temperature);
			}
			// display only when time counter hits the number of displaying counter (1ms)
			if(displaying_count++ >= DISPLAYINGCOUNTER){
				//reset displaying_count
				displaying_count=0;
				//if the increments of digit goes beyond 4, reset it
				if(digit_count++>=4){
					digit_count=0;
				}
				// if temperature is within threshold, display
				if(temperature >= TEMPERATURETHRESHOLD){
					// increment alarm count every CC but only execute the alarm if overheated every ALARMCOUNTER
				if(alarm_count++ >=ALARMCOUNTER){
						//reset alarm counter
						alarm_count=0;
						alarm_overheating();
					}
				//display temperature
					led_display(temperature, digit_count);
				}else if (currentState!=nextState){
					currentState=nextState;
					// display temperature in farenheit
					led_display(celsius_to_farenheit(temperature), digit_count);
				}
				//display temperature in celsius
				else{
					led_display(temperature, digit_count);
				}
			}
			}
}
} */
}

/**
 * @brief  Find the min, max, min_idx, max_idx, rms of an array using CMSIS build-in functions
 * @param  input address (pointer), output address (pointer), length of input
 * @retval None
 */
/*
void cmsis_math(float* input, float* output, int len){
    uint32_t max_idx;
    uint32_t min_idx;
    arm_rms_f32(input, len, &output[4]);
    arm_max_f32(input, len, &output[1], &max_idx);
    arm_min_f32(input, len, &output[0], &min_idx);
    output[3] = (float) max_idx;
    output[2] = (float) min_idx;
    return;
}*/



/**
 * @brief  FIR Filter takes in integer inputs serially and returns the filtered data (output)
 * @param  integer input, output address (pointer to index in output array)
 * @retval None
 */
void FIR_C(int input, float* output){
    // Shift all x to the left
    for(int i = 0 ; i < 4 ; i++){
        x[i] = x[i + 1];
    }
    
    //update x[4] with new input
    x[4] = input;
    
    
    //calculate output
    *output = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        *output = *output + x[i] * coeff[i];
    }
}


// Conversion from voltage to celsius
/*float tempConversion(float voltage){
	float V_25 = 0.76;
	float avg_slope = 2.5/1000;
	return ((voltage-V_25)/avg_slope)+25;
}*/

/** System Clock Configuration
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq());

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  // SysTick_IRQn interrupt configuration */
  //HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
//}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
