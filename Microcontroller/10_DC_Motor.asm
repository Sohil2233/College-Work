;Program to rotate DC Motor
Org 00h
Main: SETB P3.1
ACALL rotate
rotate: MOV R1, #02H
Delay: DJNZ R1,Delay
JZ Loop
RET
Loop : CLR P3.1
JMP Main


