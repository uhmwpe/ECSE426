#include <stdio.h>
#include "arm_math.h"

int Example_asm(int Input);


void asm_math(float* p1, float* p2, int length);
void c_math(float* p1, float* p2, int length);
void example(float* p1, float* p2, int length);
void FIR_C(int* Input, float* Output);
void cmsis_math(float* input, float* output, int len);

float coeff[5] = {0.1,0.15,0.5,0.15,0.1};
int list[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 1,0,0,1,1,1,1,1,8,9,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 1,0,0,1,1,1,1,1,8,9,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9};
float Output[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 1,0,0,1,1,1,1,1,8,9,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 1,0,0,1,1,1,1,1,8,9,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9};

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
	int len_output = 100;
	//float Output[len_output];
	
	//FIR_C(list, Output);
	
	int i = 0 ; 
	for(i = 0 ; i < len_output ; i++){
		printf("%f ", Output[i]);
	}	
	

	printf("End FIR\n");
	
	printf("Start ARM\n");
	
	float final[5];
	
	printf("length: %d\n", len_output);
	
	//c_math(Output, final, len_output);
	asm_math(Output, final, len_output);
	//cmsis_math(Output, final, len_output);
	
	for(i = 0 ; i < 5 ; i++){
		printf("%f ", final[i]);
	}	
	
	//example(Output, final, len_output);
	
	printf("\nEnd ARM\n");
	return 0;
} 

void c_math(float* input, float* output, int len){
	float sum = 0;
	output[0] = input[0];
	output[1] = input[0];
	for (int i = 0; i<len; i++){
		sum += input[i] * input[i];
		if (input[i] > output[1]){
			output[1] = input[i];
			output[3] = i;
		}
		else if (input[i] < output[0]){
			output[0] = input[i];
			output[2] = i;
		}
	}
	output[4] = sqrt(sum/len);
	
	return;
}

void cmsis_math(float* input, float* output, int len){
	uint32_t max_idx;
	uint32_t min_idx;
	arm_rms_f32(input, len, &output[4]);
	arm_max_f32(input, len, &output[1], &max_idx);
	arm_min_f32(input, len, &output[0], &min_idx);
	output[3] = (float) max_idx;
	output[2] = (float) min_idx;
	return;
}
