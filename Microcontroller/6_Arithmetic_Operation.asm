;ADDITION
ORG 0H       ; Start at memory location 0H

START:

    MOV R2, #00H     ; Initialize R2 to 0 (for storing carry)

    MOV A, 20H       ; Load the value at address 20H into accumulator A
    ADD A, 21H       ; Add the value at address 21H to accumulator A

    JNC SKIP         ; If there is no carry, jump to SKIP
    INC R2           ; If there is a carry, increment R2

SKIP:
    MOV 22H, A       ; Store the result of the addition (sum) in address 22H
    MOV 23H, R2      ; Store the carry flag (0 or 1) in address 23H

HERE:
    SJMP HERE        ; Infinite loop to stop execution

END                 ; End of program









;SUBSTRACTION
ORG 0H       ; Start at memory location 0H

START:

    MOV R2, #00H     ; Initialize R2 to 0 (for storing borrow)

    MOV A, 20H       ; Load the value at address 20H into accumulator A
    CLR C            ; Clear the carry flag to prepare for subtraction
    SUBB A, 21H      ; Subtract the value at address 21H from accumulator A

    JNC SKIP         ; If there is no borrow, jump to SKIP
    INC R2           ; If there is a borrow, increment R2

SKIP:
    MOV 22H, A       ; Store the result of the subtraction (difference) in address 22H
    MOV 23H, R2      ; Store the borrow flag (0 or 1) in address 23H

HERE:
    SJMP HERE        ; Infinite loop to stop execution

END                 ; End of program





;MULTIPLICATION
ORG 0H       ; Start at memory location 0H

START:

    MOV A, 20H       ; Take the first number into accumulator A
    MOV B, 21H       ; Take the second number into register B

    MUL AB           ; Multiply the numbers in A and B

    MOV 22H, A       ; Store the lower byte of the result (A) at address 22H
    MOV 23H, B       ; Store the higher byte of the result (B) at address 23H

HERE:
    SJMP HERE        ; Infinite loop to stop execution

END                 ; End of program





;DIVISION
ORG 0H       ; Start at memory location 0H

START:

    MOV A, 20H       ; Take the dividend into accumulator A
    MOV B, 21H       ; Take the divisor into register B

    DIV AB           ; Divide the numbers in A and B

    MOV 22H, A       ; Store the quotient (A) at address 22H
    MOV 23H, B       ; Store the remainder (B) at address 23H

HERE:
    SJMP HERE        ; Infinite loop to stop execution

END                 ; End of program
