/*#include <stdio.h>
#include "arm_math.h"

int Example_asm(int Input);

int main()
{
	
	int Input = 10;
	printf("Begins Asm\n");
	
	Example_asm(Input);

	printf("The end!\n");
	
	return 0;
}
*/

#include <stdio.h>
#include <math.h>

void asm_math(float* p1, float* p2, int length);

int test_array[7] = {1,2,3,4,5,6,7};
float coeff[5] = {0.1,0.15,0.5,0.15,0.1};
int len = (int)( sizeof(test_array) / sizeof(test_array[0]) );
//int len_coeff = (int)( sizeof(coeff) / sizeof(coeff[0]) );


void FIR_C(int Input[], float Output[])
{
	int i,j =0;
	for (i=0; i < len; i++)
	{
		float sum=0;
		for(j=0; j<= i; j++)
		{
			if (j < 5) {
				sum += (coeff[j] * Input[i-j]);
			}
		}
		Output[i] = sum;
	}
	
}

void G22_math(float InputArray[], float OutputArray[], int Length)
{
	int i, index_min, index_max =0; 
	float sum =0;
	float max = 0;
	float min = 1000000;
	for (i=0; i < Length; i++)
	{
		float x = InputArray[i];
		sum += (x * x);
		if (x < min)
		{
			min = x;
			index_min = i;
		}
		
		else if( x > max)
		{
			max = x;
			index_max = i;
		}
		
		else
		{
			continue;
		}
	}
	
	float rms = sqrt(sum / Length);
	
	OutputArray[0] = rms;
	OutputArray[1] = max;
	OutputArray[2] = min;
	OutputArray[3] = index_max;
	OutputArray[4] = index_min;
	
}

int main () {
	float fir_output[len];
	FIR_C(test_array, fir_output);

	float math_output[5];
	float ypointer = *fir_output;
	float outputpointer = *math_output;
	asm_math(&ypointer, &outputpointer, len);
	for (int i = 0; i < 5 ; i++) {
		printf("%f\n", math_output[i]);
	}
	
	
	float math_output2[5];
	G22_math(fir_output, math_output2, len);
	
	
}
