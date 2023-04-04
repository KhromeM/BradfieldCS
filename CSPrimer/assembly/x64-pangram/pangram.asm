section .text
global pangram
pangram:
	xor r8, r8 ; mask
	xor rdx, rdx
	loop:
	mov dl, [rdi]
	add rdi, 1
	cmp dl, 0
	je out
	cmp dl, 65
	jl loop
	and dl, 0x1f
	mov rax, 1
	mov cl, dl
	sub cl, 1
	shl rax, cl
	or r8, rax
	jmp loop
	out:
	and r8, 0x03ffffff
	cmp r8, 0x03ffffff

	je true
	xor rax, rax
	ret
	true:
	mov rax, 1
	ret

; rdi is a char*
; loop through rdi until it is 0
; OR the value of 1 << [rdi] and mask
; check if mask == 0x03ffffff

