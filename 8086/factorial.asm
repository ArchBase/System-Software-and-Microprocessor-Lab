    mov cx, 05h
    mov ax, 01h
li: 
    mul cx
    dec cx
    jnz li
    
    mov bx, ax
    hlt