INCLUDE 'EMU8086.INC' ; include header file
.MODEL SMALL ; memory model
.STACK 100h ; stack size

.DATA ; data segment

.CODE
MAIN PROC ; main procedure
    MOV AX, @DATA ; initialize DS
    MOV DS, AX

    PRINT 'ENTER A NUMBER: '
    CALL SCAN_NUM ; read number from keyboard
    MOV BX, 2

    PRINTN ''
    PRINT 'PRINT NUMBERS: '

    START:
        MOV AX, CX
        CALL PRINT_NUM
        PRINT ' '
        CMP BX, CX
        JE ENDOFCODE
        LOOP START
    
    PRINTN ''
    PRINT 'SUCCESSFULLY EXECUTED!'

    ENDOFCODE:
        MOV AH, 4CH ; return control to DOS
        INT 21H
MAIN ENDP ; end of main procedure

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS

END MAIN ; end of file