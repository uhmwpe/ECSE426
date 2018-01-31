AREA text, CODE, READONLY
	EXPORT asm_math

; function asm_math
; inputs:
; -------
; R0: input


asm_math
	VMOV.F32 S5, #0x40000000
	VSUB.F32 S5, S5, S5
	VMOV.F32 S0, #0x40000000
	VMOV.F32 S1, #0x3f800000
	VMOV.F32 S4, R2
	VMOV.F32 R3, S5

line12
  ;checks iterator and you have a branch here
	CMP R3, R2
	BGE rms
	VLDM R0, {S2}
	BLE S2, S0, minimum
	BGE S2, S1, maximum
	jmp rip
	
minimum
	LDR S0, S2
	VADD.F32 R4, R1, #8
	VADD.F32 R0, R0, #4
	VSTR.F32 R4, S5
	VMLA.F32 S3,S2,S2
	VADD.F32 S5,S5,#1
	jmp line12
	
maximum
	LDR S1, S2
	VADD.F32 R4, R1, #12 
	VSTR.F32 R4, S5
	VADD.F32 R0, R0, #4
	VMLA.F32 S3,S2,S2
	VADD.F32 S5,S5,#1
	jmp line12
	
rip
	VMLA.F32 S3,S2,S2
	VADD.F32 R0, R0, #4
	VADD.F32 S5,S5,#1
	jmp line12
	
rms
	VDIV.F32 S3, S3, S4
	VSQRT.F32 S3, S3
	VADD.F32 R4, R1, #16
	VSTR.F32 R4, S3
	VADD.F32 R4, R1, #0
	VSTR.F32 R4, S0
	VADD.F32 R4, R1, #4
	VSTR.F32 R4, S1

END
