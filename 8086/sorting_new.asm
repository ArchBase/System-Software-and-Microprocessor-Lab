        mov ch, 04h
        mov si, 8000h

outer:
        mov cl, 04h
        mov si, 8000h

inner:        
        mov al, [si]
        inc si
        mov ah, [si]
        cmp al, ah
        jl continue
        mov [si-1], ah
        mov [si], al
        
continue:
        dec cl
        jnz inner
        
        dec ch
        jnz outer
        
        hlt