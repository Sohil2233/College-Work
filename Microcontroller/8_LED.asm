;1st program

org 0
start:
MOV A,#0E5H
MOV P1,A
end

;2nd program

org 0
main: MOV P1,P2
Jmp main
end


;3rd program
org 00h
Back: MOV A,#0FEH        ; Data
MOV P1,A                 ; Output Data to LEDs
Acall Delay              ; call delay
MOV A,#0FFH              ; Data
MOV P1,A                 ; Ouput Data to LEDs
Acall Delay              ; call delay
SJMP Back                ; do it again

Delay: MOV R0,#0FFH      ; outer loop
Again: MOV R1,#0FFH      ; inner loop
Here: Djnz R1,Here       ; jump if R1 not zero
Djnz R0,Again            ; jump if R0 not zero
Ret
End