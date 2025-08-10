; Task: Sum of n numbers along with their patterns
; User Input: 5
; Output: 5 + 4 + 3 + 2 + 1 = 15

INCLUDE 'EMU8086.INC' ; include header file
.MODEL SMALL ; memory model
.STACK 100h ; stack size

.DATA ; data segment
    SUM DW 0 ; sum of numbers

.CODE
MAIN PROC ; main procedure
    MOV AX, @DATA ; initialize DS
    MOV DS, AX

    PRINT 'ENTER N: '
    CALL SCAN_NUM ; read number from keyboard
    MOV BX, AX ; BX = N

    START:
        MOV AX, CX
        ADD SUM, AX
        CALL PRINT_NUM
        PRINT '+'
        CMP BX, CX
        JE ENDOFCODE
        LOOP START

    PRINTN ''
    PRINT 'SUM = '
    MOV AX, SUM
    CALL PRINT_NUM

    ENDOFCODE:
        MOV AH, 4CH ; return control to DOS
        INT 21H
MAIN ENDP ; end of main procedure

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS

END MAIN ; end of file