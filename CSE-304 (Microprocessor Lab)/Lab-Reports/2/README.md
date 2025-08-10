# Lab Report 2

Instruction:

1. Introduce the Assembly Language, EMU 8086, RAM, CPU, System Bus, General Purpose Registers (AX, BX, CX, DX)
2. Short note on numbering system (Decimal, Binary, Octal, Hexadecimal).
3. Segments of Microprocessor.
4. Multiply two single character numbers and show the output. The input can be both user input and static.

Note:

1. Follow the Lab Report Template.
2. Pages must be numbered.
3. Add the Raw sample code in the report.
4. Screen shot of the stored output in general purpose registers along the sample output.

## Introduce the Assembly Language

Assembly language is a low-level programming language for a computer, or other programmable device specific to a particular computer architecture in contrast to most high-level programming languages, which are generally portable across multiple systems. Assembly language is converted into executable machine code by a utility program referred to as an assembler like NASM, MASM, etc.

## EMU 8086

EMU8086 is the emulator of 8086 (Intel and AMD compatible) microprocessor and integrated assembler with tutorials for beginners. The emulator runs programs like the real microprocessor in step-by-step mode. It shows registers, memory, stack, variables and flags. All memory values can be investigated and edited by a double click.

## RAM

RAM (Random Access Memory) is the hardware in a computing device where the operating system (OS), application programs and data in current use are kept so they can be quickly reached by the device's processor. RAM is the main memory in a computer, and it is much faster to read from and write to than other kinds of storage, such as a hard disk drive (HDD), solid-state drive (SSD) or optical drive. Data remains in RAM as long as the computer is running. When the computer is turned off, RAM loses its data. When the computer is turned on again, the OS and other files are once again loaded into RAM, usually from an HDD or SSD.

## CPU

The CPU (Central Processing Unit) is the part of a computer system that is commonly referred to as the "brains" of a computer. The CPU is also known as the processor or microprocessor. The CPU is responsible for executing a sequence of stored instructions called a program.

## System Bus

A system bus is a single computer bus that connects the major components of a computer system, combining the functions of a data bus to carry information, an address bus to determine where it should be sent, and a control bus to determine its operation. The technique was developed to reduce costs and improve modularity, and although popular in the 1970s and 1980s, more modern computers use a variety of separate buses adapted to more specific needs.

## General Purpose Registers (AX, BX, CX, DX)

The 8086 microprocessor has a total of fourteen registers that are accessible to the programmer. These registers are further divided into the following two groups −

- General Purpose Registers − The 8086 has a total of eight general purpose registers divided into four groups containing two registers each. Each group can be referred to either as a byte group or a word group. The four groups are as follows −

  - Data Group Registers − AX, BX, CX, and DX
  - Pointer Group Registers − SI, DI, BP, and SP
  - Index Group Registers − AL, BL, CL, and DL
  - Segment Group Registers − CS, DS, SS, and ES

## Short note on numbering system (Decimal, Binary, Octal, Hexadecimal)

### Decimal Number System

Decimal number system is a base 10 number system using digits for 0 to 9 whereas binary number system is base 2 and uses 0 and 1. Hexadecimal uses base 16 and range of digits are from 0 to 9 and A to F. Octal uses base 8 and range of digits are from 0 to 7.

### Binary Number System

Binary number system is a base 2 number system. It uses only 0 and 1. It is also known as Base 2 number system since it uses 2 digits to represent any number. It is the simplest number system that is used to represent data in a computer. Binary number system is used because binary digits are easy to store electronically and are less likely to get corrupted.

### Octal Number System

Octal number system is a base 8 number system. It uses digits from 0 to 7. It is also known as Base 8 number system since it uses 8 digits to represent any number. Octal number system is used in situations where binary number system is too long and decimal number system is too short to represent a number.

### Hexadecimal Number System

Hexadecimal number system is a base 16 number system. It uses digits from 0 to 9 and A to F. It is also known as Base 16 number system since it uses 16 digits to represent any number. Hexadecimal number system is used because it is easy to convert between binary and hexadecimal number system.

## Segments of Microprocessor

The 8086 microprocessor has a total of fourteen registers that are accessible to the programmer. These registers are further divided into the following two groups −

- General Purpose Registers − The 8086 has a total of eight general purpose registers divided into four groups containing two registers each. Each group can be referred to either as a byte group or a word group. The four groups are as follows −

  - Data Group Registers − AX, BX, CX, and DX
  - Pointer Group Registers − SI, DI, BP, and SP
  - Index Group Registers − AL, BL, CL, and DL
  - Segment Group Registers − CS, DS, SS, and ES

- Special Purpose Registers − The 8086 has a total of six special purpose registers. These registers are used for internal operations and are not accessible to the programmer. The six special purpose registers are as follows −

  - Instruction Pointer (IP)
  - Flags Register (FLAGS)
  - Stack Pointer (SP)
  - Base Pointer (BP)
  - Source Index (SI)
  - Destination Index (DI)

## Multiply two single character numbers and show the output. The input can be both user input and static

Multiply two single character numbers and show the output. The input can be both user input and static.

Analysis and discussion:

- The program starts by defining the model as small and stack size as 100h.
- Then the data section is defined.
- The data section contains the messages to be displayed and the variables to store the input and output.
- The code section starts by moving the data segment to the data register.
- Then the first message is displayed.
- Then the first number is taken as input and stored in the num1 variable.
- Then the second message is displayed.
- Then the second number is taken as input and stored in the num2 variable.
- Then the multiplication is performed and the result is stored in the result variable.
- Then the third message is displayed.
- Then the result is displayed.
- Then the program ends.
