data segment
    str db "raceicar$"
    msg1 db "not palindrome$"
    msg2 db "palindrome$"
ends
assume cs:code ds:data
code segment
    start:
        mov ax, data
        mov ds, ax
        
        mov si, offset str
        mov di, offset str
        
    loop_1:
        mov al, [di]
        cmp al, '$'
        jz found_di
        inc di
        jmp loop_1
        
    found_di:
        dec di
        
    loop_main:
        mov al, [si]
        mov ah, [di]
        cmp al, ah
        jnz no_palindrome
        inc si
        dec di
        cmp di, si
        jz palindrome
        jmp loop_main
    
    no_palindrome:
        lea dx, msg1
        mov ah, 09h
        int 21h
        jmp exit
    
    palindrome:
        lea dx, msg2
        mov ah, 09h
        int 21h
        jmp exit
    
    exit:
        hlt         

code ends
end start
ends