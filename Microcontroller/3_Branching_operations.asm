;1 unconditional Jump instruction
MVI A, 07H       ; get the value 07 H into accumulator
MVI B, 05H       ; get the value 05H into B register
ADD B            ; Add the content of accumulator with B reg and store in acc
JMP NEXT         ; Jump unconditionally to label NEXT
INR A            ; Increment content of accumulator. Note: this step is not executed
NEXT:HLT         ; Stop the execution



;2 Jump instruction when condition is not satisfied.
MVI A, 07H       ; get the value 07 H into accumulator
MVI B, 05H       ; get the value 05H into B register
ADD B            ; Add the content of accumulator with B reg and store in acc
JC NEXT          ; Jump if carry flag is set (Cy =1) to label NEXT
INR A            ; Increment content of accumulator. Note: this step is executed
INR A            ; Increment content of accumulator. Note: this step is executed
INR A            ; Increment content of accumulator. Note: this step is executed
INR A            ; Increment content of accumulator. Note: this step is executed
NEXT:HLT         ; Stop the execution


;3 Jump instruction when condition is satisfied
MVI A, 07H       ; get the value 07 H into accumulator
MVI B, 05H       ; get the value 05H into B register
ADD B            ; Add the content of accumulator with B reg and store in acc
JNC NEXT         ; Jump if carry flag is not set ( CY =0 )to label NEXT
INR A            ; Increment content of accumulator. Note: this step is executed
INR A            ; Increment content of accumulator. Note: this step is executed
NEXT:HLT         ; Stop the execution