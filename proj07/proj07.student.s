/***********************************************************************
	Project07
	6/11/2018
	Ben Traines
	
***********************************************************************/

		.global main
	
		.text
main:
		push	{lr}
		
		mov		r2, #0			@ Initialize char count
		mov		r3, #0			@ Initialize newline count
		mov		r4, #0			@ Initialize whitespace count
		mov		r5, #0			@ Initialize printibal char count
		mov		r6, #0			@ Initialize for control char
		mov		r7, #0			@ Initialize octal digits
		mov		r8, #0			@ Initialize decimal digits
		mov		r9, #0			@ Initialize hexadecimal digits
		mov		r10, #0			@ Initialize upper case letters
		mov		r11, #0			@ Initialize lower case letters
		
loop:	bl		getchar			@ Read one char (returned in r0)
		add		r2, r2, #1		@ Increment char count
		

if1:	cmp		r0, #0x0a		@ Compare return value to newline
		bne		endif1			@ if no newline, skip

then1:	add		r3, r3,	#1		@ Increment Newline count
		add		r4, r4, #1  	@ Increment whitespace count
		

endif1:	

if2:	cmp		r0, #0x20		@ Compare return value to blank
		bne		endif2			@ If no blank, skip
		
then2:	add		r4, r4, #1		@ Increment Whitespace

endif2:	

if3: 	cmp		r0, #0x09			@ Compare to tab
		bne		endif3
		
then3:	add		r4, r4, #1		@ Increment whitespace

endif3:	

if4:	cmp		r0, #0x20		@ Printable
		blt		endif4
		cmp		r0, #0x7E		@ Last printable
		bgt		endif4

then4:	add		r5, r5, #1		@ Increment printable char count

endif4:	

if5:	cmp		r0, #0x00
		blt		endif5
		cmp		r0, #0x1F
		bgt		endif5
		cmp		r0, #0x7F
		beq		endif5
		
then5:	add		r6, r6, #1

endif5:	

if6:	cmp		r0, #'0'
		blt		endif6
		cmp		r0, #'7'
		bgt		endif6
		
then6:	add r7, r7, #1

endif6:	

if7:	cmp		r0, #'0'		@ 0-9
		blt		endif7
		cmp		r0, #'9'
		bgt		endif7
		
then7:	add		r8, r8, #1
		add		r9, r9, #1

endif7:	

if8:	cmp		r0, #0x41		@ A-F
		blt		endif8
		cmp		r0, #0x46
		bgt		endif8
		
then8:	add		r9, r9, #1

endif8:

if9:	cmp		r0, #0x61		@ a-f
		blt		endif9
		cmp		r0, #0x66
		bgt		endif9
		
then9:	add		r9, r9, #1

endif9:	

if10:	cmp		r0, #0x41		@ A-Z
		blt		endif10
		cmp		r0, #0x5A
		bgt		endif10
		
then10:	add		r10, r10, #1

endif10:

if11:	cmp		r0, #0x61		@ a-z
		blt		endif11
		cmp		r0, #0x7A
		bgt		endif11
		
then11:	add		r11, r11, #1
				
endif11:cmp 	r0, #-1			@ If end file end loop
		beq		end
		bl		putchar
		b		loop

end:	ldr		r0, =fmt1		@ First arg -- adress of format string
		mov		r1, r2
		bl		printf
		ldr		r0, =fmt2
		mov		r1, r3
		bl		printf
		ldr		r0, =fmt3
		mov		r1, r4
		bl		printf
		ldr		r0, =fmt4
		mov		r1, r5
		bl		printf
		ldr		r0, =fmt5
		mov		r1, r6
		bl		printf
		ldr		r0, =fmt6
		mov		r1, r7
		bl		printf
		ldr		r0, =fmt7
		mov		r1, r8
		bl		printf
		ldr		r0, =fmt8
		mov		r1, r9
		bl		printf
		ldr		r0, =fmt9
		mov		r1, r10
		bl		printf
		ldr		r0, =fmt10
		mov		r1, r11
		bl		printf		
		ldr		r0, =fmt11
		add		r1, r10, r11
		bl		printf
		
		
		pop		{lr}
		bx		lr
		
		.data
		
fmt1:	.asciz	"\nTotal number of characters: %d\n"
fmt2:	.asciz	"\nNumber of newline characters: %d\n"
fmt3:	.asciz	"\nNumber of whitespace characters (blanks, tabs and newlines): %d\n"
fmt4:	.asciz	"\nNumber of printable characters (0x20 to 0x7E): %d\n"
fmt5:	.asciz	"\nNumber of control characters (0x00 to 0x1F, 0x7F): %d\n"
fmt6:	.asciz	"\nNumber of octal digits (in the set {0-7}): %d\n"
fmt7:	.asciz	"\nNumber of decimal digits (in the set {0-9}): %d\n"
fmt8:	.asciz	"\nNumber of hexadecimal digits (in the set {0-9, A-F, a-f}): %d\n"
fmt9:	.asciz	"\nNumber of upper case letters (in the set {A-Z}): %d\n"
fmt10:	.asciz	"\nNumber of lower case letters (in the set {a-z}): %d\n"
fmt11:	.asciz	"\nNumber of letters (in the set {A-Z, a-z}): %d\n"


