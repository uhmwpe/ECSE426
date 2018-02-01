#include <stdio.h>
#include "arm_math.h"

int Example_asm(int Input);


void asm_math(float* p1, float* p2, int length);
void FIR_C(int* Input, float* Output);

float coeff[5] = {0.1,0.15,0.5,0.15,0.1};
int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int list_len = (int)( sizeof(list) / sizeof(list[0]) );
int coeff_len = (int)( sizeof(coeff) / sizeof(coeff[0]) );


void FIR_C(int* Input, float* Output)
{
	int i,j =0;
	for (i=0; i < list_len; i++)
	{
		float sum=0;
		for(j=0; j<= i && j < list_len ; j++)
		{
				sum += (coeff[coeff_len - j -1] * Input[i-j]);
		}
		Output[i] = sum;
	}
	return ;
}



int main()
{
	int Input = 10;
	printf("Start FIR\n");
	int len_output = list_len - coeff_len;
	int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float Output[len_output];
	
	FIR_C(list, Output);
	
	int i = 0 ; 
	for(i = 0 ; i < len_output ; i++){
		printf("%f ", Output[i]);
	}	
	

	printf("End FIR\n");
	
	printf("Start ARM\n");
	
	float final[5];
	asm_math(Output, final, len_output);
	for(i = 0 ; i < 5 ; i++){
		printf("%f ", final[i]);
	}	
	
	printf("\nEnd ARM\n");
	return 0;
}


