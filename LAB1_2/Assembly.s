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
	VMOV.F32			S2, #0x40000000	; Initialize min_value
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
	
	VSTR.F32			S0, [R1, #0]
	VSTR.F32			S1, [R1, #4]
	VSTR.F32			S2, [R1, #8]
	STR						R6, [R1, #12]
	STR						R7, [R1, #16]

	POP    				{R5, R6, R7, LR};
	BX						LR;
	ENDP
	END







;	AREA text, CODE, READONLY
;	EXPORT asm_math, example, asm_math_17

;R0 = Input	 (arg into the function)
;R1 = Output (arg into the function)
;R2 = length (arg into the function) 
;R3 = index count

;Output: min, max, min_index, max_index, rms

;S0 = min val 
;S1 = max val
;S2 = current val
;S3 = RMS
;S4 = length 
;S5 = index 

;example
;	MOV R3, #4 
;	SUB R3, R3, R3 ;SETTING INDEX TO 0
;	VLDM.F32 R0, {S2} ; LOADING INPUT INTO CURRENT VAL
;	VMOV.F32 S0, S2 ;INITIALIZING MINIMUM VALUE (TO FIX)
;	VMOV.F32 S1, S2 ;INITIALIZING MAXIMUM VALUE (TO FIX)
;	VMOV.F32 S4, R2 ;SETTING S4 TO LENGTH - SHOULD BE ABLE TO DELETE
;	B END;;


;asm_math
;	MOV R3, #4 
;	SUB R3, R3, R3 ;SETTING INDEX TO 0
;	VLDM.F32 R0, {S2} ; LOADING INPUT INTO CURRENT VAL
;	VMOV.F32 S0, S2 ;INITIALIZING MINIMUM VALUE (TO FIX)
;	VMOV.F32 S1, S2 ;INITIALIZING MAXIMUM VALUE (TO FIX)
;	VMOV.F32 S4, R2 ;SETTING S4 TO LENGTH - SHOULD BE ABLE TO DELETE
	
  ;checks iterator and you have a branch here
	; loop until index == length
;loop
;	;MOV R9, #1
;	;MOV R11, R2
;	;MOV R12, R3
;	CMP R2, R3 ;COMPARE INDEX WITH LENGTH - TERMINATION CONDITION
;	BEQ rms ;(if index > length then go to RMS) 
;	VLDM.F32 R0, {S2} ; LOADING INPUT INTO CURRENT VAL
;	VCMP.F32 S2, S0 ;COMPARING CURRENT VAL WITH MINIMUM VALUE
;	BLT minimum
;	VCMP.F32 S2, S1 ;COMPARING CURRENT VAL WITH MAX VAL
;	BGT maximum
;	B equal
	
;minimum
;	MOV R8, #4
;	VMOV.F32 S0, S2 ;REPLACING THE MIN VAL WITH THE CURRENT VAL
;	;ADD R4, R1, #8 ;STORE min_index ADDRESS in R4 
; 	;STR R3, [R4]
;	VMOV.F32 S5, R3
;	VSTR.F32 S5, [R1, #8]
;	VMLA.F32 S3,S2,S2 ;SQUARE VALUE AND ADD IT TO S3 (RMS VALUE)
;	ADD R3,R3,#1 ;ITERATE INDEX COUNT
;	ADD R0,R0,#4 ;ITERATE ADDRESS OF INPUT - ITERATE BY 4 -- next input
;	B loop
;	
;maximum
;	MOV R8, #3
;	VMOV.F32 S1, S2 ;REPLACING THE MAX VALUE WITH THE CURRENT VAL
;	VMOV.F32 S5, R3
;	VSTR.F32 S5, [R1, #12] ;STORE INDEX VALUES
;	VMLA.F32 S3,S2,S2 ;SQUARE THE VALUE AND ADD IT TO RMS VALUE
;	ADD R3,R3,#1 ;ITERATE INDEX
;	ADD R0,R0,#4 ;ITERATE ADDRESS OF INPUT - ITERATE BY 4 -- next input
;	B loop
;	
;equal
;	MOV R8, #2
;	VMLA.F32 S3,S2,S2 ;SQUARE THE VALUE AND ADD IT TO RMS VALUE
;	ADD R0,R0,#4 ;ITERATE ADDRESS OF INPUT - ITERATE BY 4 -- next input
;	ADD R3,R3,#1 ;ITERATE INDEX
;	B loop
;	
;rms
;	MOV R8, #1
;	VDIV.F32 S3, S3, S4 ;DIVIDE RMS VALUE BY LENGTH
;	VSQRT.F32 S3, S3 ;SQUAREROOT WHAT REMAINS
;	ADD R4, R1, #16 ;MOVE POINTER TO RMS OUTPUT REGISTER
;	VSTR.F32 S3, [R4] ;STORE RMS VALUE IN APPROPRIATE REGISTER IN OUTPUT 
;	ADD R4, R1, #0 ;REGISTER OUTPUT OF MINVAL
;	VSTR.F32 S0, [R4]; STORING MINIMUM VALUE 
;	ADD R4, R1, #4 ;REGISTER OUTPUT OF MAXVAL
;	VSTR.F32 S1, [R4] ;STORING MAXVAL
;	B END;;

;asm_math_17
;	MOV R3, #1
;	VLDM.F32 R0, {S2}
;	VMOV.F32 S1, S2
;	VMOV.F32 S0, S2
;	MOV R4, #0
;	VMOV.F32 S3, R4
;	VMLA.F32 S3, S2, S2
;	ADD R0, R0, #4
;	VSTR.F32 S3, [R0, #8]
;	VSTR.F32 S3, [R0, #12]
;	B loop2;

	
;loop2 
;	CMP R2, R3
;	BEQ rms2
;	VLDM.F32 R0, {S2}
;	VMUL.F32 S2, S2, S2
;	VADD.F32 S3, S3, S2
;	VCMP.F32 S2, S1
;	BGT maximum2
;	VCMP.F32 S2, S0
;	BLT minimum2
;	ADD R3, R3, #1
;	ADD R0, R0, #4
;	B END
;	
;	
;minimum2
;	VMOV.F32 S0, S2
;	ADD R4, R1, #8
;	VMOV.F32 S5, R3
;	VSTR.F32 S5, [R4]
;	B loop2
;	
;maximum2
;	VMOV.F32 S1, S2
;	ADD R4, R1, #12
;	VMOV.F32 S5, R3
;	VSTR.F32 S5, [R4]
;	B loop2
;	
;rms2
;	VDIV.F32 S3, S4
;	VSQRT.F32 S3, S3
;	VSTR.F32 S0, [R1] ;storing minimum
;	VSTR.F32 S1, [R1, #4] ;storing maximum
;	VSTR.F32 S3, [R1, #16] ;storing rms;;



;END
	
	
