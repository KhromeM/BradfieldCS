default rel

section .data
pi: dd 1.0471975512

section .text
global volume
volume:
	mulss xmm0, xmm0
	mulss xmm0, xmm1
	mulss xmm0, [pi]
 	ret
