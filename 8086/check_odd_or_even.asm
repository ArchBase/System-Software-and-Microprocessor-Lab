    mov al, 0ch ;number to be checked
    mov bl, 02h
    div bl
    cmp ah, 00h
    jz even
    jnz odd
    
even:
    mov al, 0ffh
    hlt
odd:
    mov bl, 0ffh
    hlt
