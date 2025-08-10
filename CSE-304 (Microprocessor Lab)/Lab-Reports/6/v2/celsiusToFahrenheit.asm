INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H

.DATA
    TMP DW ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; °C = ((9 / 5) * °C) + 32
    ; => °C * 9 / 5 + 32
    PRINT 'Celsius (°C) - '
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

    ; CONVERTING TO FAHRENHEIT
    MOV BX, 9
    MUL BX
    MOV BX, 5
    DIV BX
    ADD AX, 32

    ; PRINTING RESULT
    PRINTN ''
    PRINT 'Fahrenheit (°F) - '
    MOV TMP, AX
    CALL PRINT_NUM_UNS
    PRINT '°C'

    MOV AH, 4CH
    INT 21H
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
END MAIN
