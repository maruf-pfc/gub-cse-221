.model small
.stack 100h

.data
    my_name db "Muhammad Maruf Sarker $"
    id db 10, 13, "221002063 $"

    msg db 10, 13, "Output: $"

.code
main proc
    mov ax, @data
    mov ds, ax

    ; print name
    mov ah, 9
    lea dx, my_name
    int 21h

    ; print id
    mov ah, 9
    lea dx, id
    int 21h

    ; print msg
    mov ah, 9
    lea dx, msg
    int 21h

    ; perform the operation
    ; brute force approach
    mov si, 2
    mov my_name[si], '2'

    mov si, 2
    mov my_name[si], '2'

    mov si, 1
    mov my_name[si], '1'

    mov si, 0
    mov my_name[si], '0'

    mov si, 0
    mov my_name[si], '0'

    mov si, 2
    mov my_name[si], '2'
    
    mov si, 0
    mov my_name[si], '0'

    mov si, 6
    mov my_name[si], '6'

    mov si, 3
    mov my_name[si], '3'

    ; print the result
    mov ah, 9
    lea dx, my_name
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main