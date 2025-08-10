INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    TMP DW ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; °C = ((°F - 32) * 5) / 9
    PRINT 'Fahrenheit (°F) - '
    ; TAKING MULTIPLE DIGIT INPUT FROM USER
    MOV BH, 0
    MOV BL, 10D

    INPUT:
        MOV AH, 1
        INT 21H
        CMP AL, 13
        JNE NUM
        JMP EXIT

    NUM:
        SUB AL, 30H
        MOV CL, AL
        MOV AL, BH
        MUL BL
        ADD AL, CL
        MOV BH, AL
        JMP INPUT
    
    EXIT:
        MOV AX, 0
        MOV AL, BH

        ; F - 32
        MOV CX, 32
        SUB AX, CX

        ; (F - 32) * 5
        MOV CX, 5
        MUL CX

        ; ((F - 32) * 5) / 9
        MOV CX, 9
        DIV CX

        ; PRINTING RESULT
        PRINTN ''
        PRINT 'Celsius (°C) - '
        MOV TMP, AX
        CALL PRINT_NUM_UNS
        PRINT '°C'

    ENDOFFILE:
        MOV AH, 4CH
        INT 21H
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
END MAIN
