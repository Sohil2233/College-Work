LHLD 0000H       ; Get 1st 16-bit number in H-L pair
XCHG             ; Save 1st 16-bit number in DE
LHLD 0002H       ; Get 2nd 16-bit number in H-L pair
MOV A, E         ; Get lower byte of the 1st number
ADD L            ; Add lower byte of the 2nd number
MOV L, A         ; Store result in L-register
MOV A, D         ; Get higher byte of the 1st number
ADC H            ; Add higher byte of the 2nd number with CARRY
MOV H, A         ; Store result in H-register
SHLD 0004H       ; Store 16-bit result in memory locations 0004H and 0005H
HLT              ; Stop