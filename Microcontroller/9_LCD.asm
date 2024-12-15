;1. Program to display Number 1 on LCD 3

Org 00h
select: setb P0.7
setb P3.3
setb P3.4
start: mov A,#0f9h
mov P1,A
end

;2. Program to display Number 5 on LCD 2
Org 00h
select: setb P0.7
Clr P3.3
setb P3.4
start: mov A,#92h
mov P1,A
end



;3rd
;Program:
; Put data in RAM
MOV 30H,#'H'
MOV 31H,#'E'
MOV 32H,#'L'
MOV 33H,#'L'
MOV 34H,#'0'
MOV 35H,#20H
MOV 36H,#'W'
MOV 37H,#'O'
MOV 38H,#'R'
MOV 39H,#'L'
MOV 3AH,#'D'
MOV 3BH,#0H
;end of data marker
;initialize the display
;see instruction set for details
CLR P1.3 ; clear RS- indicates that instructions are being sent to the module
;function set
CLR P1.7
CLR P1.6
SETB P1.5
CLR P1.4 ; high nibble set
SETB P1.2
CLR P1.2 ; negative edge on E
CALL DELAY ; wait
SETB P1.2
CLR P1.2 ; negative edge on E

SETB P1.7 ; low nibble set
SETB P1.2
CLR P1.2 ;negative edge on E

CALL DELAY
; entry mode set
CLR P1.7
CLR P1.6
CLR P1.5
CLR P1.4 ; high nibble set
SETB P1.2
CLR P1.2 ;negative edge on E

SETB P1.6
SETB P1.5 ; low nibble set

SETB P1.2
CLR P1.2 ; high nibble set
CALL DELAY ; wait
CLR P1.7
CLR P1.6
CLR P1.5
CLR P1.4
SETB P1.2
CLR P1.2
SETB P1.7
SETB P1.6
SETB P1.5
SETB P1.4
SETB P1.2
CLR P1.2
CALL DELAY
SETB P1.3 ; clear RS
MOV R1,#30H ; data to be sent to LCD is stored in 8051 RAM , starting at location 30 H
LOOP: MOV A,@R1 ; move data pointed to by R1 to A
JZ FINISH ; if A is 0, then end of data has been reached, jump out of loop
CALL SendChar ; send Data in A to LCD module
INC R1
JMP LOOP
FINISH:

JMP $
SendChar: MOV C,ACC.7
MOV P1.7,C
MOV C,ACC.6
MOV P1.6,C
MOV C,ACC.5
MOV P1.5,C
MOV C,ACC.4
MOV P1.4,C
SETB P1.2
CLR P1.2
MOV C,ACC.3
MOV P1.7,C
MOV C,ACC.2
MOV P1.6,C

MOV C,ACC.1
MOV P1.5,C
MOV C,ACC.0
MOV P1.4,C ; low nibble set
SETB P1.2
CLR P1.2 ; negative edge on E
CALL DELAY
DELAY: MOV R0,#50H
DJNZ R0,$
RET