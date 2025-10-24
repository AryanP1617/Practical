data segment
    msg1 db 0dh,0ah,"Enter a number: $"
    msg2 db 0dh,0ah,"Enter another number: $"
    msg3 db 0dh,0ah,"THe result of the addition is: $"
data ends

code segment
assume cs:code,ds:data

start:
    mov ax,data
    mov ds,ax

    mov dx,OFFSET msg1
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h
    sub al,30h

    mov cl,4
    shl al,cl
    mov bl,al

    mov ah,01h
    int 21h
    sub al,30h
    or bl,al

    mov dx,OFFSET msg2
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h
    sub al,30h

    mov cl,4
    shl al,cl
    mov bh,al

    mov ah,01h
    int 21h
    sub al,30h
    or bh,al

    mov al,bh
    add al,bl
    daa
    mov bh,al

    mov dx,OFFSET msg3
    mov ah,09h
    int 21h

    jnc down
    mov dl,31h
    mov ah,02h
    int 21h

    down:
        mov cl,4
        mov al,bh
        and al,0F0h
        ror al,cl
        add al,30h
        mov dl,al
        mov ah,02h
        int 21h

        mov al,bh
        and al,0Fh
        ror al,cl
        add al,30h
        mov dl,al
        mov ah,02h
        int 21h
    
    mov ah,4ch
    int 21h

code ends
end start
