;1 unconditional Jump instruction
MVI A, 07H    ; Get the value 07H into accumulator
MVI B, 05H    ; Get the value 05H into B register
ADD B         ; Add the content of accumulator with B reg and store in accumulator
JMP NEXT      ; Jump unconditionally to label NEXT
INR A
NEXT: HLT     ; Stop the execution



;2 Jump instruction when condition is not satisfied.
MVI A, 0F8H      ; Load 0F8H (248 in decimal) into accumulator
MVI B, 0FCH      ; Load 0FCH (252 in decimal) into B register
ADD B            ; Add the content of accumulator and B (results in a carry)
JC NEXT          ; Jump to NEXT if carry flag is set
INR A            ; Increment content of accumulator
INR A            ; Increment content of accumulator
INR A            ; Increment content of accumulator
INR A            ; Increment content of accumulator
NEXT: HLT        ; Stop the execution



;3 Jump instruction when condition is satisfied
MVI A, 07H    ; Get the value 07H into accumulator
MVI B, 05H    ; Get the value 05H into B register
ADD B         ; Add the content of accumulator with B reg and store in accumulator
JMP NEXT      ; Jump unconditionally to label NEXT
INR A
INR A
NEXT: HLT     ; Stop the execution