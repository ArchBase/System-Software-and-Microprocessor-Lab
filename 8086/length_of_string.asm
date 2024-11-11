data segment
    str db "range rover$"
ends
assume cs:code ds:data
code segment
    start:
        mov ax, data
        mov ds, ax
        
        mov cl, 00h
        mov si, offset str
        
    count_loop:
        
        mov al, [si]
        cmp al, '$'
        jz exit
        inc cl
        inc si
        jmp count_loop
        
    exit:
        
        hlt
        
code ends
end start
ends