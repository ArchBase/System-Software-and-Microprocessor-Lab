data segment
    str1 db "computer$"
    str2 db "computer$"
    msg1 db "strings are equal$"
    msg2 db "strings are not equal$"
ends

code segment
    assume cs:code, ds:data

start:
    ; Initialize data segment
    mov ax, data
    mov ds, ax

    ; Initialize pointers to start of str1 and str2
    lea si, str1
    lea di, str2

compare_loop:
    ; Load a byte from each string
    mov al, [si]
    mov bl, [di]

    ; Check if end of either string is reached ('$' terminator)
    cmp al, '$'
    jne check_mismatch
    cmp bl, '$'
    jne check_mismatch

    ; If both strings ended with '$', they are equal
    jmp strings_equal

check_mismatch:
    ; Compare characters from str1 and str2
    cmp al, bl
    jne strings_not_equal

    ; If characters are the same, advance to the next
    inc si
    inc di
    jmp compare_loop

strings_equal:
    ; Display msg1: "strings are equal"
    lea dx, msg1
    mov ah, 09h       ; DOS interrupt for displaying string
    int 21h
    jmp end_program

strings_not_equal:
    ; Display msg2: "strings are not equal"
    lea dx, msg2
    mov ah, 09h       ; DOS interrupt for displaying string
    int 21h

end_program:
    ; Exit the program
    mov ah, 4Ch       ; DOS interrupt for program termination
    int 21h
ends

end start
