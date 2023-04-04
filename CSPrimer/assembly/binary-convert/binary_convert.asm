section .text
global binary_convert
binary_convert:
	xor rax, rax
	xor rcx, rcx
	loop:
	mov cl, [rdi]
	add rdi, 1
	cmp cl, 0
	je out
	and cl, 1
	shl rax, 1
	add rax, rcx
	jmp loop
	out:
	ret
