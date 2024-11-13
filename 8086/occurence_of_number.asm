DATA SEGMENT
    array DB 5, 2, 7, 5, 3, 5, 1, 5   ; Array of numbers
    target DB 5                       ; Number to count in the array
    count DB 0                        ; Variable to store count of occurrences
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX                        ; Load data segment

    MOV CX, 8                         ; Load the length of the array into CX
    MOV SI, 0                         ; SI will be the index for the array
    MOV BL, 0                         ; BL will store the count of occurrences

LOOP_START:
    MOV AL, array[SI]                 ; Load the current element into AL
    INC SI                            ; Move to the next element in array

    CMP AL, target                    ; Compare element with target
    JNE NO_MATCH                      ; If not equal, skip incrementing count

    INC BL                            ; Increment count if element matches target

NO_MATCH:
    DEC CX                            ; Decrease CX (array length counter)
    JNZ LOOP_START                    ; If CX is not zero, repeat the loop

    MOV count, BL                     ; Store the count result in `count`

    MOV AX, 4C00H                     ; Terminate the program
    INT 21H
CODE ENDS
END START
