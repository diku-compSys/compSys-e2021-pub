	.file	"simple-program.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	addq	%rdi, %rdi
	movl	$0, %edx
.L4:
	addq	$1, %rdx
	cmpq	$5, %rdx
	jne	.L4
	leaq	(%rdi,%rsi), %rax
	movl	$4, %edi
	subq	%rdx, %rdi
	imulq	%rsi, %rdi
	addq	%rax, %rdi
	leaq	(%rsi,%rdi), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
