mov cl,04h         ; Outer loop counter (number of passes)
    mov si,8000h       ; Starting address of the array

l1: mov ch,04h         ; Inner loop counter (number of comparisons per pass)
    mov si,8000h       ; Reset SI to the start of the array

l2: mov al,[si]        ; Load the current byte into AL
    inc si             ; Move SI to the next byte
    mov ah,[si]        ; Load the next byte into AH
    cmp al,ah          ; Compare AL and AH
    jbe l3             ; If AL <= AH, no swap needed; jump to l3
    mov [si-1],ah      ; Otherwise, swap: store AH in the previous byte
    mov [si],al        ; Store AL in the current byte

l3: dec ch             ; Decrement inner loop counter
    jnz l2             ; Repeat inner loop if CH != 0

    dec cl             ; Decrement outer loop counter
    jnz l1             ; Repeat outer loop if CL != 0

    hlt                ; Halt program