ORG 0100		;assembler directive tells prog to start from

MAIN:
	mov, ie, #82h		;init the interrupt  enables timer0 intr
	mov tmod, #01h		;use timer0 in mode1
	mov tl0, #0ch		;load value of timer
	mov th0, #0feh		;as per calculation ( fe 0ch )
	setb tr0		;start the timer TCON.6

here:
	sjmp here		;wait till tf0=1

	org 000bh			;vector address of inturrupt
	cpl p2.1			;cpmplement
	clr tr0				;stop timer
	clr tf0				
	mov tl0, #0ch			;reload timer
	mov th0, #0feh			
	setb tr0			;start tier again
	reti   		 		;return   from isr
