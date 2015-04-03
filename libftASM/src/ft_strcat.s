section .text
	global ft_strcat
; rdi, rsi, rdx
ft_strcat:

.test:
	enter 0, 0
	mov rax, rdi
	cmp rdi, 0
	jne .boucle_rdi
	mov rax, rsi
	jmp .end

.continue:
	cmp [rsi], byte 0
	je .end
	mov dl, [rsi]
	mov [rdi], dl
	inc rdi
	inc rsi
	jmp .continue

.boucle_rdi:
	cmp [rdi], byte 0
	je .continue
	inc rdi
	jmp .boucle_rdi

.end:
	inc rdi
	mov [rdi], byte 0
	leave
	ret
