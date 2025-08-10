; 1. Write assembly language codes to compute and store the output of the following equations in general-purpose registers.
; a) First four digits of your ID + last three digits of your ID.
; b) Increment 7 times the number obtained from the last three digits of your ID.
; c) First four digits of your ID - answer received from "b".
; d) Decrement the answer x times. where x = highest digit that can be obtained from the answer "c".

include 'emu8086.inc'

.model small
.stack 100h

.data
    ; my id: 221002063
    
.code
main proc
    mov ax, @data
    mov ds, ax

    ; a) First four digits of your ID + last three digits of your ID.
    print "Enter first four digits of your ID: "
    call scan_num
    mov ax, cx
    mov dx, cx    
    
    printn ''

    print "Enter last three digits of your ID: "
    call scan_num
    mov bx, cx 

    printn ''

    print "First four digits + Last three digits = "
    add ax, bx
    call print_num

    printn ''
    printn ''

    ; b) Increment 7 times the number obtained from the last three digits of your ID.
    ; here I store last three digits of my id in bx register
    ; before incrementing
    print 'Last three digits of my ID = '
    mov ax, bx
    call print_num

    printn ''

    ; increment 7 times
    inc ax
    inc ax
    inc ax
    inc ax
    inc ax
    inc ax
    inc ax
    mov cx, ax

    print 'Incremented 7 times = '
    call print_num

    printn ''
    printn ''

    ; c) First four digits of your ID - answer received from "b".
    print 'First four digits of my ID = '
    mov ax, dx
    call print_num
    printn ''

    print 'Answer received from b = '
    mov ax, cx
    call print_num
    printn ''

    print 'First four digits - Answer received from b = '
    mov ax, dx
    sub ax, cx
    call print_num

    printn ''
    printn ''

    ; d) Decrement the answer x times. where x = highest digit that can be obtained from the answer "c".

    print 'Answer received from c = '
    call print_num
    printn ''

    printn 'Highest digit that can be obtained from the answer c = 4'

    print 'Decremented the answer x times = '
    mov cx, 4
    l1:

    mov bx, 0
    cmp cx, bx
    jl endoffile

    jmp level1
    level1:
        dec ax

    loop l1

    endoffile:
    call print_num
    
    mov ah, 4ch
    int 21h
main endp

define_scan_num
define_print_num
define_print_num_uns
end main
