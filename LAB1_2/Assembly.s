	AREA text, CODE, READONLY
		
	; function asm_math
	; inputs:
	;   R0 : pointer to input array
	;   R1 : pointer to output array
	;   R2 : length of input array
	; output: 
	; float32_t[5] = [min, max, index_min, index_max, rms]

	

asm_math PROC
	EXPORT asm_math

	PUSH    			{R3, R5, R6, LR};
	LDR     			R3, = 0               ; R5 = loop counter
	LDR     			R5, = 0               ; R6 = max_index
	LDR     			R6, = 0               ; R7 = min_index

	VSUB.F32      S0, S0, S0      ; S0 = RMS = 0
	VLDM.F32			R0, {S2}				; max_value = R0
	VLDM.F32			R0, {S1}				; Initialize =  R0
	VSUB.F32      S5, S5, S5      ; COUNTER = 0 
	VMOV.F32			S6, #0x3f800000	; 
loop ;LOOP UNTIL INDEX COUNTER = LENGTH OF INPUT
	CMP     			R2, R3; 
	BEQ     			exit						; STOP WHEN COUNTER = LENGTH

	VLDM.F32      R0, {S4}        ; UPDATE S4 WITH CURR_VAL
	VFMA.F32      S0, S4, S4      ; UPDATE RSM WITH CURR_VAL^2


;=======MAX=======
	VCMP.F32     	S4, S2;					; COMPARE MAX_VAL & CURR_VAL
	VMRS     		 	APSR_nzcv, FPSCR;
	MOVGT   		 	R5, R3					;	UPDATE MAX_INDEX
	VMOVGT.F32   	S8, S5;					; UPDATE MAX_VAL
	VMOVGT.F32   	S2, S4;					; UPDATE MAX_VAL

;=======MIN=======
	VCMP.F32     	S4, S1					; COMPARE MIN_VAL & CURR_VAL
	VMRS					APSR_nzcv, FPSCR;
	MOVLT    			R6, R3;					;	UPDATE MIN_INDEX
	VMOVGT.F32   	S7, S5;					; UPDATE MAX_VAL
	VMOVLT.F32		S1, S4;					; UPDATE MIN_VAL

; ======ITERATE THROUGH THE LOOP ======
	ADD 					R0, R0, #4
	ADD 					R3, R3, #1
	VADD.F32			S5, S5, S6			; INCREMENT S5 COUNTER

	B							loop
exit
	
	VDIV.F32  		S0, S0, S5;			; GET RMS VALUE --> RMS = RMS / LENGTH
	VSQRT.F32 		S0, S0;					; GET FINAL RMS VALUE --> RMS = sqrt(RMS)
	VSTR.F32			S1, [R1]				; STORE MIN VALUE IN OUTPUT VECTOR
	VSTR.F32			S2, [R1, #4]		; STORE MAX VALUE IN OUTPUT VECTOR
	VSTR.F32			S7, [R1, #8]		; STORE MIN_IDX VALUE IN OUTPUT VECTOR
	VSTR.F32			S8, [R1, #12]		; STORE MAX_IDX VALUE IN OUTPUT VECTOR
	VSTR.F32			S0, [R1, #16]		; STORE RMS VALUE IN OUTPUT VECTOR

	POP    				{R3, R5, R6, LR}; 
	BX						LR;							; RETURN TO BRANCH ADDRESS
	ENDP
	END