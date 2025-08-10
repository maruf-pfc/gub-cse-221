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
    CALL SCAN_NUM

    MOV AX, CX

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

    MOV AH, 4CH
    INT 21H
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
END MAIN
