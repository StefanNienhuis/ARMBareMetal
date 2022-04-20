.section .text

.globl _start

_start:
	// Set the stack pointer register to the top of the stack, which for some reason cannot be done directly.
	ldr 	x30, =stack_top
	mov		sp, x30

	bl		kernel_main 	// Call kernel_main() function
	b		. 				// Loop
