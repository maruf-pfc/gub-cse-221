.model small
.stack 100h

.data
a db 'Upper Case = $'
b db 'Lower Case = $'

.code
main proc
    mov ax, @data
    mov ds, ax

    ; show the first msg
    mov ah, 9
    lea dx, a
    int 21h

    ; upper case input
    mov ah, 1
    int 21h
    mov bl, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; show the second msg
    mov ah, 9
    lea dx, b
    int 21h

    ; convert upper to lower and display
    mov ah, 2
    add bl, 32
    mov dl, bl
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main
