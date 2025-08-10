# Lab - 2

- MODEL
- SEGMENTS
  - Stack Segment
  - Data Segment
  - Code Segment
  - Extra Segment
- SINGLE CHARACTER INPUT/OUTPUT
- STRING PRINT
- SYNTAX
- ALLOpCATION

---

- MODEL - Large, Medium, Compact
- STACK 100H
- Data
  - V1 DB 10
  - V2 DW 10000
  - MSG DB 'Hello World!$'
  - V3 DW ?
- CODE
  - MAIN PROC

  - MAIN ENDP

  - END MAIN

- AX --> AH/AL
- BX --> BH/BL
- CX --> CH/CL
- DX --> DH/DL

## Class Task

- 5 ta character input niye sei 5 ta character print krte hobe

write a assembly program in emu8086 where take Name, ID, Phone, Email form user and print those input values inside a string like Hello $Name, we know your ID $ID. Thank you for sharing your phone number $Phone and Email address $Email
