/***********************************************************************
	Project09
	Ben Traines
***********************************************************************/

		.global search
		.global delete
		.global	insert
		
		.data
index:	.word	0
count:	.word	0
id:		.word	0

name:	.word	0
exam1: 	.word	0
exam2:	.word	0
hw:		.word	0
sp:		.skip	4
		
search:
		push	{lr}
		
		ldr		r4, =id
		str		r1, [r4]
		
		ldr		r5, =count		
		mov		r4, r0 			@ Move table address to r4
		ldrh	r6, [r4,#2]		@ r5: count
		str		r6, [r5]
		ldr 	r4, [r4, #8]	@ Adress to arry
		mov		r6, #0			@ r6: index
loop:	
		cmp		r6, r5			@ Compare Index and Count
		bge		notfound
		
		lsl		r7, r6, #5		@ Offset <== Index * 16
		add		r8, r4, r7		@ r8: address of current record
		
		
		mov		r10, #8
		mul		r9, r6, r10
		add		r8, r8, r9
		
		ldrh	r7, [r8, #0]	@ ID
		ldr		r9, =id			@ Given ID
		ldr		r9, [r9]
		cmp		r7, r9			@ Compare ID and Given ID
		beq		found

		add		r6, r6, #1
		
		b		loop
notfound:
		mov		r0, #0
		b		end

found:
		ldr		r7, =sp
		str		r8, [r7]
		mov		r0, #1
end:	
		add		r6, r6, #1
		ldr		r7, =index
		str		r6, [r7]
		pop		{lr}
		bx		lr






		
delete:
		push	{lr}
		
		bl		search
		
		
		ldr		r8, =sp
		ldr		r8, [r8]
		ldr		r2, =index
		ldr		r2, [r2]
		ldr		r3, =count
		ldr		r3, [r3]
		cmp		r2, r3
		bgt		false
		

		
		
		lsl		r3, r2, #5
		add		r8, r8, r3
		mov		r6, #8
		mul		r5, r2, r6
		add		r8, r8, r5

		
		ldr		r9, =sp
		ldr		r9, [r9]
		mov		r0, r9		@ Move og address to destination
		mov		r1, r8		@ Move next address to source
		mov		r2, #40
		bl		memmove
		mov		r0, #1
false:
		mov		r0, #0
		b		end2
end2:
		pop		{lr}
		bx		lr






insert:
		push	{lr}
		
		ldr		r4, =id
		str		r1, [r4]
		ldr		r4, =name
		str		r2, [r4]
		ldr		r4, =exam1
		str		r3, [r4]
		ldr		r4, =exam2
		ldr		r3, [r0, #4]
		str		r3, [r4]
		ldr		r4, =hw
		ldr		r3, [r0, #8]
		str		r3, [r4] 
		
		
		
		ldr		r5, =count		
		mov		r4, r0 			@ Move table address to r4
		ldrh	r6, [r4,#2]		@ r5: count
		str		r6, [r5]
		ldr 	r4, [r4, #8]	@ Adress to arry
		mov		r6, #0			@ r6: index
loop:	
		cmp		r6, r5			@ Compare Index and Count
		bgt		notfound
		
		lsl		r7, r6, #5		@ Offset <== Index * 16
		add		r8, r4, r7		@ r8: address of current record
		
		
		mov		r10, #8
		mul		r9, r6, r10
		add		r8, r8, r9
		
		ldrh	r7, [r8, #0]	@ ID
		ldr		r9, =id			@ Given ID
		ldr		r9, [r9]
		cmp		r7, r9			@ Compare ID and Given ID
		ble		found

		add		r6, r6, #1
		
		b		loop
notfound:
		mov		r0, #0
		b		end

found:

		ldr		r2, =index
		ldr		r2, [r2]
		ldr		r3, =count
		ldr		r3, [r3]
		cmp		r2, r3
		lsl		r3, r2, #5
		add		r8, r8, r3
		mov		r6, #8
		mul		r5, r2, r6
		add		r8, r8, r5
		ldr		r9, =sp
		ldr		r9, [r9]
		mov		r0, r9		@ Move og address to destination
		mov		r1, r8		@ Move next address to source
		mov		r2, #40
		bl		memmove
		mov		r0, #1
		
end:	
		add		r6, r6, #1
		ldr		r7, =index
		str		r6, [r7]
		pop		{lr}
		bx		lr



