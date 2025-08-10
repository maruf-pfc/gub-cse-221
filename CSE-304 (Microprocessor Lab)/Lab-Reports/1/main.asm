; Using Single Character User Input and Output

; Input:
; Name: Md. Maruf Sarker
; ID: 221002063
; Phone: 01843579712
; Email: marufsarkercse2022@gmail.com

; Output:
; Hello Md. Maruf Sarker, holding id no. 221002063.
; Thank you for sharing your phone as 01843579712 and email as marufsarkercse2022@gmail.com.

.MODEL SMALL
.STACK 100H
.DATA
    ; name = 12 characters
    nm1 db ?
    nm2 db ?
    nm3 db ?
    nm4 db ?
    nm5 db ?
    nm6 db ?
    nm7 db ?
    nm8 db ?
    nm9 db ?
    nm10 db ?
    nm11 db ?
    nm12 db ?

    ; id = 10 characters
    id1 db ?
    id2 db ?
    id3 db ?
    id4 db ?
    id5 db ?
    id6 db ?
    id7 db ?
    id8 db ?
    id9 db ?
    id10 db ?

    ; phone = 11 characters
    ph1 db ?
    ph2 db ?
    ph3 db ?
    ph4 db ?
    ph5 db ?
    ph6 db ?
    ph7 db ?
    ph8 db ?
    ph9 db ?
    ph10 db ?
    ph11 db ?
    ph12 db ?

    ; email = 22 characters
    em1 db ?
    em2 db ?
    em3 db ?
    em4 db ?
    em5 db ?
    em6 db ?
    em7 db ?
    em8 db ?
    em9 db ?
    em10 db ?
    em11 db ?
    em12 db ?
    em13 db ?
    em14 db ?
    em15 db ?
    em16 db ?
    em17 db ?
    em18 db ?
    em19 db ?
    em20 db ?
    em21 db ?
    em22 db ?

    ; input messages
    in1 db "Enter your name: ", "$"
    in2 db "Enter your id: ", "$"
    in3 db "Enter your phone: ", "$"
    in4 db "Enter your email: ", "$"

    ; output messages
    msg1 db "Hello ", "$"
    msg2 db ", holding id no. ", "$"
    msg3 db ".", "$"
    msg4 db "Thank you for sharing your phone as ", "$"
    msg5 db " and email as ", "$"

.CODE
MAIN PROC
    ; set data segment
    mov ax, @DATA
    mov ds, ax

    ; ask for enter name
    mov ah, 9
    lea dx, in1
    int 21h

    ; take name as input
    mov ah, 1
    int 21h
    mov nm1, al
    mov ah, 1
    int 21h
    mov nm2, al
    mov ah, 1
    int 21h
    mov nm3, al
    mov ah, 1
    int 21h
    mov nm4, al
    mov ah, 1
    int 21h
    mov nm5, al
    mov ah, 1
    int 21h
    mov nm6, al
    mov ah, 1
    int 21h
    mov nm7, al
    mov ah, 1
    int 21h
    mov nm8, al
    mov ah, 1
    int 21h
    mov nm9, al
    mov ah, 1
    int 21h
    mov nm10, al
    mov ah, 1
    int 21h
    mov nm11, al
    mov ah, 1
    int 21h
    mov nm12, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; ask for enter id
    mov ah, 9
    lea dx, in2
    int 21h
    mov ah, 1
    int 21h
    mov id1, al
    mov ah, 1
    int 21h
    mov id2, al
    mov ah, 1
    int 21h
    mov id3, al
    mov ah, 1
    int 21h
    mov id4, al
    mov ah, 1
    int 21h
    mov id5, al
    mov ah, 1
    int 21h
    mov id6, al
    mov ah, 1
    int 21h
    mov id7, al
    mov ah, 1
    int 21h
    mov id8, al
    mov ah, 1
    int 21h
    mov id9, al
    mov ah, 1
    int 21h
    mov id10, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; ask for enter phone
    mov ah, 9
    lea dx, in3
    int 21h

    ; take phone as input
    mov ah, 1
    int 21h
    mov ph1, al
    mov ah, 1
    int 21h
    mov ph2, al
    mov ah, 1
    int 21h
    mov ph3, al
    mov ah, 1
    int 21h
    mov ph4, al
    mov ah, 1
    int 21h
    mov ph5, al
    mov ah, 1
    int 21h
    mov ph6, al
    mov ah, 1
    int 21h
    mov ph7, al
    mov ah, 1
    int 21h
    mov ph8, al
    mov ah, 1
    int 21h
    mov ph9, al
    mov ah, 1
    int 21h
    mov ph10, al
    mov ah, 1
    int 21h
    mov ph11, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; ask for enter email
    mov ah, 9
    lea dx, in4
    int 21h

    ; take email as input
    mov ah, 1
    int 21h
    mov em1, al
    mov ah, 1
    int 21h
    mov em2, al
    mov ah, 1
    int 21h
    mov em3, al
    mov ah, 1
    int 21h
    mov em4, al
    mov ah, 1
    int 21h
    mov em5, al
    mov ah, 1
    int 21h
    mov em6, al
    mov ah, 1
    int 21h
    mov em7, al
    mov ah, 1
    int 21h
    mov em8, al
    mov ah, 1
    int 21h
    mov em9, al
    mov ah, 1
    int 21h
    mov em10, al
    mov ah, 1
    int 21h
    mov em11, al
    mov ah, 1
    int 21h
    mov em12, al
    mov ah, 1
    int 21h
    mov em13, al
    mov ah, 1
    int 21h
    mov em14, al
    mov ah, 1
    int 21h
    mov em15, al
    mov ah, 1
    int 21h
    mov em16, al
    mov ah, 1
    int 21h
    mov em17, al
    mov ah, 1
    int 21h
    mov em18, al
    mov ah, 1
    int 21h
    mov em19, al
    mov ah, 1
    int 21h
    mov em20, al
    mov ah, 1
    int 21h
    mov em21, al
    mov ah, 1
    int 21h
    mov em22, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; print msg
    mov ah, 9
    lea dx, msg1
    int 21h

    ; output name
    mov ah, 2
    mov dl, nm1
    int 21h
    mov ah, 2
    mov dl, nm2
    int 21h
    mov ah, 2
    mov dl, nm3
    int 21h
    mov ah, 2
    mov dl, nm4
    int 21h
    mov ah, 2
    mov dl, nm5
    int 21h
    mov ah, 2
    mov dl, nm6
    int 21h
    mov ah, 2
    mov dl, nm7
    int 21h
    mov ah, 2
    mov dl, nm8
    int 21h
    mov ah, 2
    mov dl, nm9
    int 21h
    mov ah, 2
    mov dl, nm10
    int 21h
    mov ah, 2
    mov dl, nm11
    int 21h
    mov ah, 2
    mov dl, nm12
    int 21h

    ; print msg
    mov ah, 9
    lea dx, msg2
    int 21h

    ; output id
    mov ah, 2
    mov dl, id1
    int 21h
    mov ah, 2
    mov dl, id2
    int 21h
    mov ah, 2
    mov dl, id3
    int 21h
    mov ah, 2
    mov dl, id4
    int 21h
    mov ah, 2
    mov dl, id5
    int 21h
    mov ah, 2
    mov dl, id6
    int 21h
    mov ah, 2
    mov dl, id7
    int 21h
    mov ah, 2
    mov dl, id8
    int 21h
    mov ah, 2
    mov dl, id9
    int 21h
    mov ah, 2
    mov dl, id10
    int 21h

    ; print msg
    mov ah, 9
    lea dx, msg3
    int 21h

    ; new line

    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h


    ; print msg
    mov ah, 9
    lea dx, msg4
    int 21h

    ; output phone
    mov ah, 2
    mov dl, ph1
    int 21h
    mov ah, 2
    mov dl, ph2
    int 21h
    mov ah, 2
    mov dl, ph3
    int 21h
    mov ah, 2
    mov dl, ph4
    int 21h
    mov ah, 2
    mov dl, ph5
    int 21h
    mov ah, 2
    mov dl, ph6
    int 21h
    mov ah, 2
    mov dl, ph7
    int 21h
    mov ah, 2
    mov dl, ph8
    int 21h
    mov ah, 2
    mov dl, ph9
    int 21h
    mov ah, 2
    mov dl, ph10
    int 21h
    mov ah, 2
    mov dl, ph11
    int 21h

    ; print msg
    mov ah, 9
    lea dx, msg5
    int 21h

    ; output email
    mov ah, 2
    mov dl, em1
    int 21h
    mov ah, 2
    mov dl, em2
    int 21h
    mov ah, 2
    mov dl, em3
    int 21h
    mov ah, 2
    mov dl, em4
    int 21h
    mov ah, 2
    mov dl, em5
    int 21h
    mov ah, 2
    mov dl, em6
    int 21h
    mov ah, 2
    mov dl, em7
    int 21h
    mov ah, 2
    mov dl, em8
    int 21h
    mov ah, 2
    mov dl, em9
    int 21h
    mov ah, 2
    mov dl, em10
    int 21h
    mov ah, 2
    mov dl, em11
    int 21h
    mov ah, 2
    mov dl, em12
    int 21h
    mov ah, 2
    mov dl, em13
    int 21h
    mov ah, 2
    mov dl, em14
    int 21h
    mov ah, 2
    mov dl, em15
    int 21h
    mov ah, 2
    mov dl, em16
    int 21h
    mov ah, 2
    mov dl, em17
    int 21h
    mov ah, 2
    mov dl, em18
    int 21h
    mov ah, 2
    mov dl, em19
    int 21h
    mov ah, 2
    mov dl, em20
    int 21h
    mov ah, 2
    mov dl, em21
    int 21h
    mov ah, 2
    mov dl, em22
    int 21h

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    mov ax, 4ch
    int 21h
main endp
end main
