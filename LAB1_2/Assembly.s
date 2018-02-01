	AREA text, CODE, READONLY
		
		; function asm_math
; inputs:
;   R0 : pointer to input array
;   R1 : pointer to output array
;   R2 : length of input array
; output:
;   float32_t[5] = [RMS_value, max_value, min_value, max_index, min_index]

; WHAT WE NEED TO FIGURE OUT HOW TO DO
; load values from pointer
; compare less than and greater than (CMP)
; set value at index from a pointer
; multiply numbers
; divide numbers
; square root

asm_math PROC
	EXPORT asm_math

	PUSH    			{R5, R6, R7, LR};
	LDR     			R5, = 0               ; R5 = loop counter
	LDR     			R6, = 0               ; R6 = max_index
	LDR     			R7, = 0               ; R7 = min_index

	VSUB.F32      S0, S0, S0      ; Initialize RMS_value
	VSUB.F32      S1, S1, S1      ; Initialize max_value
	VLDM.F32			R0, {S2}			; Initialize min_value
	VSUB.F32      S5, S5, S5      ; Initialize float loop counter ; todo fix this (fix1)
	VMOV.F32			S6, #0x3f800000	; todo fix this (fix1)
loop
	CMP     			R2, R5;
	BEQ     			exit

	VLDM.F32      R0, {S4}        ; Load next element ; todo fix this (fix2)

; update RMS_value
	VFMA.F32      S0, S4, S4      ; Square current elem, add to total

; check max_value
	VCMP.F32     	S4, S1;
	VMRS     		 	APSR_nzcv, FPSCR;
	MOVGT   		 	R6, R5;
	VMOVGT.F32   	S1, S4;

; check min_value
	VCMP.F32     	S4, S2;
	VMRS					APSR_nzcv, FPSCR;
	MOVLT    			R7, R5;
	VMOVLT.F32		S2, S4;

; increment index and pointer
	ADD 					R0, R0, #4
	ADD 					R5, R5, #1
	VADD.F32			S5, S5, S6			; todo fix this (fix1)

	B							loop
exit
	
	VDIV.F32  		S0, S0, S5;			; todo fix this (fix1)
	VSQRT.F32 		S0, S0;
	VSTR.F32			S1, [R1, #4]
	VSTR.F32			S2, [R1]
	STR						R6, [R1, #8]
	STR						R7, [R1, #12]
	VSTR.F32			S0, [R1, #16]

	POP    				{R5, R6, R7, LR};
	BX						LR;
	ENDP
	END

; function asm_math
; inputs:
;   R0 : pointer to input array
;   R1 : pointer to output array
;   R2 : length of input array
; output:
;   float32_t[5] = [RMS_value, max_value, min_value, max_index, min_index]

; WHAT WE NEED TO FIGURE OUT HOW TO DO
; load values from pointer
; compare less than and greater than (CMP)
; set value at index from a pointer
; multiply numbers
; divide numbers
; square root



;asm_math PROC
;	EXPORT asm_math
;	PUSH  {R3, R4, R5, LR}
;	LDR R3, = 0 ; R3 = COUNTER INDEX
;	VLDM.F32 R0, {S1} ; S1 = MAX_VALUE
;	VLDM.F32 R0, {S2} ; S2 = MIN_VALUE
;	VSUB.F32 S0, S0, S0 ; S0 = RMS_SUM
;	
;	LDR R4, = 0 ; CURRENT MIN_INDEX IS AT 0 
;	LDR R5, = 0 ; CURRENT MAX_INDEX IS AT 0
;	
;	
;loop 
;	CMP R2, R3 ; compare index and length
;	BEQ ending
;	VLDM.F32 R0, {S3} ; next element
;	VFMA.F32 S0, S3, S3 ; square and add to sum (RMS) 
;	
;	;MIN VALUE UPDATING
;	VCMP.F32 S0, S2 
;	VMRS APSR_nzcv, FPSCR; 
;	MOVGT R4, R3;
;	VMOVGT.F32 S2, S3 
;	
;	;MAX VALUE UPDATING
;	VCMP.F32 S0, S1 
;	VMRS APSR_nzcv, FPSCR; 
;	MOVGT R5, R3;
;	VMOVGT.F32 S1, S3 
;	
;	; index++
;	ADD R3, R3, #1
;	; increase element address
;	ADD R0, R0, #4
;	
;	B loop

;ending
;	STR R4, [R1, #8]
;	STR R5, [R1, #12]
;	VSTR.F32 S2, [R1, #0]
;	VSTR.F32 S1, [R1, #4]
;	VLDM.F32 R2, {S2} 
;	VDIV.F32 S0, S0, S2
;	VSTR.F32 S0, [R1, #16]
;	
;	POP {R3, R4, R5, LR}
;	BX LR
;	
;ENDP
;END
	