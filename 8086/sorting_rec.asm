    mov cl, 04h
    mov si, 8000h
l1:
    mov ch, 04h
l2:
    mov al, [si]
    inc si
    mov ah, [si]
    cmp al, ah
    jbe l3
    mov [si-1], ah
    mov [si], al
l3:
    dec ch
    jnz l2
    dec cl
    jnz l1
    hlt