
section .text
global sum_to_n
sum_to_n:
;	mov rax, 0
;	start:
;	cmp rdi, 0
;	je  end
;	add rax, rdi
;	add rdi, -1
;	jmp start
;	end:
;	ret



	mov rax, rdi
	add rdi, 1
	imul rax, rdi
	sar rax, 1
	ret


