MVI C,05H
LXI H,1000H
LXI D,2000H
LOOP: MOV A,M
STAX D
INX H
INX D
DCR C
JNZ LOOP
HLT