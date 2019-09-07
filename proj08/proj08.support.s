        .global negate
		.global absolute
		.global add
		.global sub
		.global mul
		.global divide
		.global remain
		.global power
		.global factorial
		.global error
		.text
		.balign 4
negate:						@ Return the negation of N
		push	{lr}

		neg		r0, r0		@ Negate N
		
		pop		{lr}
		bx		lr

absolute:					@ Return absolute value of N
		push	{lr}
		
		cmp 	r0, #0		@ compare N with 0
		it		lt			@ if negative negate
		neglt	r0, r0		@ Negative so negate
		
		pop		{lr}
		bx		lr
		
add:						@ Return the sum of A + B
		push	{lr}
		
		adds	r0, r0, r1	@ A + B, set NZCV
		bvs		error	@ Check for Overflow
		pop		{lr}
		bx		lr
		
sub:						@ Return the value of B - A
		push	{lr}
		
		subs	r0, r1, r0	@ B - A, set NZCV
		bvs		error	@ Check for Overflow
		
		pop		{lr}
		bx		lr
		
mul:						@ Return the product of A * B
		push	{lr}
		
		mov		r4, r0		@ Move A to r4
		mov		r5, r1		@ Move B to r5
		
		smull	r0, r1, r0, r1	@ A * B
		
		cmp 	r4, #0		@ Compare A to 0
		blt		notpos		@ Use signed mul
		cmp		r5, #0		@ Compare B to 0
		blt		notpos 		@ Use signed mul
		
		cmp		r0, r4		@ Cmopare result to A
		blt		error		@ If less then A
		cmp		r0, r4		@ Cmopare result to B
		blt		error		@ If less then B
		cmp 	r0, #0		@If negative
		blt		error
notpos:	
		pop		{lr}
		bx		lr
		
divide:						@ Return the quotation of A / B
		push	{lr}
		
		cmp		r1, #0		@ Compare B to 0
		beq		error		@ If B == 0 throw error
		sdiv	r0, r0, r1	@ A / B
		
		cmp		r0, #0		@ Compare result to 0
		blt		zero		@ Result is negative
		b		end
		
zero:	mov		r0, #0		@ set result to 0
		
end:	pop		{lr}
		bx		lr
		
remain:						@ Return the remainder of A / B
		push	{lr}
		
		cmp		r1, #0		@ Compare B to 0
		beq		error		@ If B == 0 throw error
			
		mov		r7, r0		@ Move A to r4
		bl		divide		@ A / B = Q
		bl		mul			@ Q * B = TQ
		mov		r1, r7 		@ Move A to r1
		bl		sub			@ A - TQ = Remainder
		
		pop		{lr}
		bx		lr
		
power:						@ Return N raised to the Ith power
		push	{lr}
		
		cmp		r1, #0		@compare I to 0
		ble		error
		
		mov		r4, r1		@ Move I to r4 (counter)
		mov		r5, r0		@ Move N to r5
		mov		r6, #0		@ Initialize reult to 0
loop:	
		mov		r1, r5		@ Set r1 == N
		bl		mul			@ N * N
		add		r6, r6, r0	@ add result to r6
		sub		r4, r4, #1  @ Decrement r4
		cmp		r4, #0		@ Compare counter to 0
		beq 	loop		@ If counter != 0, continue loop
		
		mov		r0, r6		@ Move result to r0
		
		pop		{lr}
		bx		lr
		
factorial:					@ Return N!
		push	{lr}

		cmp		r0, #0		@ Compare N to 0
		blt		error		@ N must be >= 0
		beq		one			@ result is 1

		
		mov		r1, #1		@ Default start
		mov		r4, #1		@ increment
		
loopf:	mov		r3, r0		@ Move N to r3
		cmp		r3, #1		@ Compare N to 1
		bgt		mul			@ If N>1: N * n
		mov		r0, r4
		mov		r1, r3
		bgt		sub		 	@ N - 1 (counter)
		bgt		loopf		@ If N > 1, then continue the loop
		
		mov		r0, r3		@ Move result to output
		b		donefac
		
one:	mov		r0, #1		@ Set result to 1
		b		donefac
		
donefac:
		pop		{lr}
		bx		lr
	
error:
		push	{lr}
		
		mov		r0, #0x80000000	@ set result as error
	
		pop 	{lr}
		bx		lr
