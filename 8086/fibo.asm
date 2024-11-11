    mov dl, 0ah
    mov al, 00h
    mov bl, 01h
    mov cl, 00h
    mov si, 8000h

loop1:
    mov [si], al
    inc si
    mov cl, al
    add cl, bl
    mov al, bl
    mov bl, cl
    dec dl
    jnz loop1
    
    hlt
    