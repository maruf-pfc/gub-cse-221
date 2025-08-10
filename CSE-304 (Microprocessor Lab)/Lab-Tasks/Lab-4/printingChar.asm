include 'emu8086.inc'

.model small
.stack 100h
.data
    v1 dw 5 dup(10)
    nl db 0dh, 0ah, '$' ; print new line

.code
main proc
    mov ax, @data
    mov ds, ax
    
    printn 'Character printing - A'
    mov ah, 02h
    mov dl, 'a'
    int 21h

    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h

    printn 'Character printing - B'
    mov ah, 02h
    mov dl, 'b'
    int 21h

    mov ah, 09h
    lea dx, nl
    int 21h

    printn 'Character printing - C'
    mov ah, 02h
    mov dl, 'c'
    int 21h

    mov ah, 4CH
    int 21h
    main endp
end main