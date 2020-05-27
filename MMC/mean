section .data
arr dd 12.3,14.2,23.4,16.3,11.5		;dd double word
point db "."
plen equ $-point
divisor dd 5.0
tent dd 100.0			;control precision
newl db 10


%macro operate 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro


section .bss
mean resd 1  ;Actual Mean
mean1 rest 1  ;store BCD number into pop TOS(Top of the Stack=10 bytes=80 bits)
count resb 1  ;to itereate through the mean1
count1 resb 1 ;2 digit number
temp resb 1  ; ASCII value store


section .text
global _start
 _start:

	mov rsi,arr
	mov cx,05
	fldz   ;Load zero onto TOS (Push +0.0 onto the FPU stack).        
	;;;;finit  ;Initialize Floating-Point Unit	
	up:
	fadd dword[rsi]
	add rsi,4		;shift pointer to next double_word
	dec cx		;as a number is added
	jnz up
	
	fdiv dword[divisor]  ;Divide ST(0) by divisor and store result in ST(0).
	fst dword[mean]      ;store the value of the ST(0) register to the mean (destination operand), mean=15.54
	
	fmul dword[tent]     ;ST(0)*10000.0=15.54*10000=ST(0)=155400
	fbstp tword[mean1]  ;store 80 bit bcd number into ST(0) and mean1, pop from TOS=54 15 00 00 00 00 00 00 00 00 
	mov rbp, mean1

	call display
	operate 1, 1, newl, 1
	operate 60, 0, 0, 0	

	display:
	add rbp, 9		;its reversed in mean1 so to go to first actual elemnt move pointer by 9 bytes
	mov byte[count], 10	;stack length = 80 bits=10 bytes

	above:
	cmp byte[rbp], 00
	je skip
	cmp byte[count], 01
	jne print		;prints number as not reached for decimal point
	operate 1, 1, point, plen

	print:
	mov bl, byte[rbp]	;ex bl=15
	mov byte[count1], 2	;bcoz we need to print 2 digits

	againx:
	rol bl, 4		;@--1bl=51, @2--15
	mov byte[rbp], bl
	and bl, 0fh	;for masking from 51 to 01
	cmp bl, 09h
	jbe downx
	add bl, 07h

	downx:
	add bl, 30h		;;ascii value to digit to print
	mov byte[temp],bl	;temp = 31 then 35
	operate 1, 1, temp, 1	;display result
	mov bl, byte[rbp]	;bl=51
	dec byte[count1]
	jnz againx

	
	skip:
	dec rbp
	dec byte[count]
	jnz above
	ret
	
	




