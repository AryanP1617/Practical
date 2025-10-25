data segment
    blk1 db 01h,02h,03h,04h,05h
    blk2 db 5 dup(0)
data ends



code segment
    ASSUME cs:code,ds:data
    start:
        mov ax,data
        mov ds,ax
        mov es,ax

        lea si,blk1
        lea di,blk2

        mov cx,05h
        CLD

        rep MOVSB

        mov ah,4ch
        int 21h
    
    code ends
    end start
