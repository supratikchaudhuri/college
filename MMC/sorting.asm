section .data
arr db 08h,11h,05h,14h,0Ah
msg db "the sorted array is :",10
msglen equ $-msg
newline db 10
%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss
temp resb 1


section .text
global _start
_start:
	rw 1,1,msg,msglen
	mov ch,05
up3:	mov rsi,arr
	mov cl,04
up2:	mov bl,[rsi]
	cmp bl,[rsi+1]
	jbe up1
	xchg [rsi+1],bl
	mov [rsi],bl
up1:	inc rsi
	dec cl
	jnz up2
	dec ch
	jnz up3
mov ch,05
mov rbp,arr
up4:	mov cl,02
	mov al,[rbp]
u1:	rol al,4
	mov bl,al
	and al,0fh
	cmp al,09h
	jbe d1
	add al,07h
d1:	add al,30h
	mov byte[temp],al
	rw  1,1,temp,1
	mov al,bl
	dec cl
	jnz u1
	rw 1,1,newline,1
	inc rbp
	dec ch
	jnz up4

exit:	mov rax,60
	mov rdi,0
	syscall
	
