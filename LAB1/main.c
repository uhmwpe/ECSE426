#include <stdio.h>
#include <math.h>
//#include "arm_math.h"

//int Example_asm(int Input);

//declare the constant FIR filter coefficients 
void FIR_C(int*, float*);


float coeff[5] = {0.1, 0.15, 0.5, 0.15, 0.1};
int order = 4;



int main()
{
	int input[5] = {1, 2, 3, 4, 5};
	float output = 5;




	FIR_C(input, &output);
	return 0;
}

void FIR_C(int* Input, float* Output){ //Input and Output are addresses
	int i, j;
	float avg;
	int length = sizeof(&Input) / sizeof(int);
	printf("%d", length);
	for(i = 0 ; i < (length - order) ; i++){
		avg = 0;
		for( j = 0 ; j < order + 1 ; j++){
			avg += Input[i] * coeff[j];
		}
		Output[j] = avg;
	}
	
	printf("%f", Output[2]);
	
	//return;
	
}
