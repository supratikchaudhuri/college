

					Assignment No: 3



section .data

msg1 db "Error",10
msgl1 equ $-msg1

msg2 db "File Copy Successfully",10
msgl2 equ $-msg2 



%macro operate 4 	;macro declaration
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss

	fname1 resb 15			;first filename 
	fd1 resq 1	;first file descriptor or file pointer	8 bytes
 	fname2 resb 15  ;second filename 
	fd2 resq 1   ;second file descriptor or file pointer
	buff resb 512  
	bufflen resq 1 

section .txt
global _start 
 _start:
	pop r8	;pop the number of arguments(r8 is the GPR)
	cmp r8,3 ;compare No of arguments with 3(i.e exe 				filename, source filename ,destination          			filename)
	jne err   ;if no of arguments not equal to 3 then it 			display the error message
	pop r8	;pop the address exe file name
	pop r8	;pop the address source file name

	
	mov rsi,fname1
	
	above:

	mov al,[r8] 
	cmp al,00		;check for end of filename
	je next		
	mov [rsi],al
	inc r8
	inc rsi
	jmp above	
	
	next:
		pop r8   ;pop the destination file name
			
		mov rsi,fname2
		
	above2:
		
		mov al,[r8]
		cmp al,00
		je next2
		mov [rsi],al
		inc r8
		inc rsi
		jmp above2
	next2:

	operate 2,fname1,000000q,0777q	;open first file
	;(macroname system file_open(2),filename,file access mode(readonly(0)),file permision of OGU is RWX(i.e read,write,execute)
	mov [fd1],rax  ;weget handle at accumulator 64 bit

	operate 0, [fd1], buff, 512		;read first file
	mov [bufflen], rax

	operate 85, fname2, 0777q, 0		;create second file
	operate 2, fname2, 2, 0777q		;open second file
	mov [fd2], rax

	operate 1, [fd2], buff, [bufflen]		;write second file
	
	operate 3, [fd2], 0, 0
	operate 3, [fd1], 0, 0

	operate 1, 1, msg2, msgl2
	jmp end

	err:
	operate 1, 1, msg1, msgl1
	end:
	operate 60, 0, 0,0




















