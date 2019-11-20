
/*
 * Assembler1.s
 *
 * Created: 10/2/2019 9:40:48 AM
 *  Author: bpaiva1
 */ 
.global func
.global KillSwitch

func:
	pop	r0
	pop	r1

	push r2
	push r3
	push r4
	push r5
	push r6
	push r7
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
	push r16
	push r17
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r28
	push r29
	push r30
	push r31
	in r16, SREG
	in r17, SPL
	in r18, SPH
	push r16
	push r17
	push r18
//switch sections of memory and call nextTask()
    call nextTask()
	pop r16
	out SPH, r16
    pop r17
    out SPL, r16
    pop r18
    out SREG, r16
    pop r31
    pop r30 
    pop r29 
    pop r28
    pop r27
    pop r26
    pop r25
    pop r24
    pop r23
    pop r22
    pop r21
    pop r20
    pop r19
    pop r18
    pop r17
    pop r16
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8 
    pop r7
    pop r6
    pop r5 
	pop r4
	pop r3
	pop r2

	push r1
	push r0

	clr r0
	clr r1

	ret

KillSwitch:
    pop r16 //gets program counter of stack to be deleted
    pop r17

    pop r16
    out SPH, r16
    pop r17
    out SPL, r16
    pop r18
    out SREG, r16
    pop r31
    pop r30
    pop r29
    pop r28
    pop r27
    pop r26
    pop r25
    pop r24
    pop r23
    pop r22
    pop r21
    pop r20
    pop r19
    pop r18
    pop r17
    pop r16
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop r7
    pop r6
    pop r5
    pop r4
    pop r3
    pop r2

    push r1
    push r0

    clr r0
    clr r1

    ret
