#include <stdio.h>
#include "arm_math.h"
#include "stm32f4xx_hal.h"
//#include "usb_host.h"


int Example_asm(int Input);

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI1_Init(void);
void MX_USB_HOST_Process(void);


int main()
{
	
	int Input = 10;
	printf("Begins Asm\n");
	
	Example_asm(Input);

	printf("The end!\n");
	
	MX_GPIO_Init();
  MX_ADC1_Init();
  MX_DAC_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  //MX_USB_HOST_Init();
	
	return 0;
}
