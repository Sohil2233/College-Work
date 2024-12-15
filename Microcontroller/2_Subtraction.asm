LHLD 0000H       ; Get first 16-bit number in HL
XCHG             ; Save first 16-bit number in DE
LHLD 0002H       ; Get second 16-bit number in HL
MOV A, E         ; Get lower byte of the first number
SUB L            ; Subtract lower byte of the second number
MOV L, A         ; Store lower byte subtraction result in L register
MOV A, D         ; Get higher byte of the first number
SBB H            ; Subtract higher byte of second number with borrow
MOV H, A         ; Store higher byte subtraction result in H register
SHLD 0004H       ; Store l6-bit result in memory locations 0004H and 0005H.
HLT              ; Terminate program execution