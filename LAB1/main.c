// Group 17 
// Tiffany Wang 260684152
// Isaac Chan 260624096


#include <stdio.h>
#include "arm_math.h"


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




int main()
{
    //============================== START PART 1 ==============================
    printf("Start FIR\n");
    int len_output = input_len;
    float Output[len_output];
    
    //serially input the elements in the input array into the FIR filter and update the output array
    for(int j = 0 ; j < input_len ; j++){
        FIR_C(Input[j], &Output[j]);
    }
    
    //print out the output filter array
    for(int i = 0 ; i < len_output ; i++){
        printf("%f ", Output[i]);
    }
    
    printf("\nEnd FIR\n");
    
    //============================== END PART 1 ==============================
	
    //============================== START PART 2 ==============================
    printf("Start Part 2\n");

    float final_c[5];
    float final_asm[5];
    float final_cmsis[5];

    c_math(Output, final_c, len_output);
    asm_math(Output, final_asm, len_output);
    cmsis_math(Output, final_cmsis, len_output);

    //Print out c_math output
    printf("\nC Output:");
    for(int i = 0 ; i < 5 ; i++){
        printf("%f ", final_c[i]);
    }

    //Print out asm_math output
    printf("\nASM Output:");
    for(int i = 0 ; i < 5 ; i++){
        printf("%f ", final_asm[i]);
    }

    //Print out cmsis_math output
    printf("\nCMSIS Output:");
    for(int i = 0 ; i < 5 ; i++){
        printf("%f ", final_cmsis[i]);
    }
    
    printf("\nEnd Part 2\n");
    return 0;
    
    //============================== END PART 2 ==============================
}

/**
 * @brief  FIR Filter takes in integer inputs serially and returns the filtered data (output)
 * @param  integer input, output address (pointer to index in output array)
 * @retval None
 */
void FIR_C(int input, float* output)
{
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




/**
 * @brief  Find the min, max, min_idx, max_idx, rms of an array in C
 * @param  input address (pointer), output address (pointer), length of input
 * @retval None
 */
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

/**
 * @brief  Find the min, max, min_idx, max_idx, rms of an array using CMSIS build-in functions
 * @param  input address (pointer), output address (pointer), length of input
 * @retval None
 */
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

