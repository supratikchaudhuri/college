;;61 82 x 10

org 0000h		;teeling assembler tells to store program from 0000h

mov r0, #40h		;40h=82h pointer to mem loc having lower 8bit miltiplicand

mov r1, #42h		42h=10h poiner to mem loc of multiplier
mov a, @r1		;r1 r1 only interact with a
mov b, a		;copy to b from a
mov a, @r0		;getlower 8bit multiplicand in r0 to a
mul ab			;ba = 08 20
mov r0 , #52h		;answer in 3 parts: last middle first
			;mom loc 50 51 52h
mov @r0, a		;a = 20
mov r3,b		;b = 08

mov r0, #41h		;to access upper 8 bits of multiplicand
mov r1, #42h		;get multiplier

mov a, @r1
mov b, a
mov a, @r0  		
mul ab			;ba = 06 10
add a, r3		;adds 10, 08 
mov r0, #51h		;points to addr 51h
mov @r0, a		;stores middle part
mov a, #00		;a is now 0
addc a, b		;get correct value of b
mov r0, #50h		
mov @r0, a		;store last part
end
