.model small
.stack 100h

.data
a db 'Lower Case = $'
b db 'Upper Case = $'

.code
main proc
    mov ax, @data
    mov ds, ax

    ; show the first msg
    mov ah, 9
    lea dx, a
    int 21h

    ; lower case input
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

    ; convert lower to Upper and display
    mov ah, 2
    sub bl, 32
    mov dl, bl
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main
