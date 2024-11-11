data segment
    num db 8h
    prime_str db "prime$"
    np_str db "not prime$"
ends

assume cs:code, ds:data

code segment
    start:
        mov ax, data
        mov ds, ax
        
        
            
        mov al, num;check is number if 2            
        cmp al, 02h
        jz op_prime
                  
        mov bl, num
        mov cl, 00h
        mov ah, 00h
                  
    division_loop: 
        
        mov ah, 00h
        mov al, num       
        div bl
        cmp ah, 00h
        jz count
        
    continue:
    
        dec bl
        jz exit
        jmp division_loop
    
    count:
        
        add cl, 01h
        jmp continue
        
        
        

op_prime:
        lea dx, prime_str
        mov ah, 09h
        int 21h
        jmp end_pgm
op_np:
        lea dx, np_str
        mov ah, 09h
        int 21h
        jmp end_pgm

exit:        
        cmp cl, 03h
        jg op_np
        jl op_prime
        jmp end_pgm
        
end_pgm:

code ends
end start