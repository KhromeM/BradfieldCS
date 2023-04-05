section .text
global fib, fun
fun:
	xor rcx, rcx ; var1
	mov r8, 1    ; var 2
	xor, r9, r9  ; iterator
	loop:
	cmp r9, rdi
	je end


	end:
	

	even: ;replace rcx
		add  rcx, r8
		

	odd: ;replace r8
		add r8, rcx









fib:
	; 2^n recursive
	cmp rdi, 0
	je zero
	cmp rdi, 1
	je one

	sub rdi, 1
	push rdi
	call fib
	mov r8, rax
	pop rdi

	sub rdi, 1
	push rdi
	push r8
	call fib
	pop r8
	pop rdi

	add rax, r8
	ret

	zero:
	xor rax, rax
	ret
	one:
	mov rax, 1
	ret

