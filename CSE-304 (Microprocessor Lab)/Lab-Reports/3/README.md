# Lab Report 3

Instruction:

1. Print out your name (Example: Federico Faggin) through Emu 8086 emulator.
2. Take an input string as static with the length grater then 20 and change the characters at different positions of the string as per your ID.
(ID: 211002154, Example: This is a sample code of EMU8086 -> 012s45s a sample code of EMU8086) through Emu 8086 emulator.

Note:

1. Follow the Lab Report Template.
2. Pages must be numbered.
3. Add the Raw sample code in the report.
4. Screen shot of the stored output in general purpose registers along the sample output.

```assembly
; Take an input string as static with the length grater then 20 and change the characters at different positions of the string as per your ID. (ID: 211002154, Example: This is a sample code of EMU8086 -> 012s45s a sample code of EMU8086) through Emu 8086 emulator.

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
    
    ; store first value of id string into a register
    mov al, id
    mov si, 2
    mov my_name[si], al

    ; store second value of id string into a register
    mov bl, id + 1
    mov si, 2
    mov my_name[si], '2'

    ; store third value of id string into a register
    mov al, id + 2
    mov si, 1
    mov my_name[si], '1'

    ; store fourth value of id string into a register
    mov bl, id + 3
    mov si, 0
    mov my_name[si], '0'

    ; store fifth value of id string into a register
    mov al, id + 4
    mov si, 0
    mov my_name[si], '0'

    ; store sixth value of id string into a register
    mov bl, id + 5
    mov si, 2
    mov my_name[si], '2'

    ; store seventh value of id string into a register
    mov al, id + 6
    mov si, 0
    mov my_name[si], '0'

    ; store eighth value of id string into a register
    mov bl, id + 7
    mov si, 6
    mov my_name[si], '6'

    ; store ninth value of id string into a register
    mov al, id + 8
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
```
