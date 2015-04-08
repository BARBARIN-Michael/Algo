; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strdup.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/04 17:34:44 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/04 17:34:44 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

; rdi, rsi, rdx

section .text
	extern ft_memcpy
	extern ft_strlen
	extern malloc
	extern printf
	global ft_strdup

ft_strdup:
	enter 0, 0
	push r13
	push r12
	mov r13, rdi

.strlen:
	call ft_strlen
	inc rax           ; len++ pour '\0'
	mov r12, rax      ; On Sauvegarde la taille de str

.malloc:
	mov rdi, r12     ; malloc (len[rdi])
	call malloc
	test rax, rax
	jz .finish

.bzero:
	mov [rax + r12], byte 0

.memcpy:
	mov rdi, rax      ; pointeur dst sortie de malloc
	mov rsi, r13      ; chaine de caractere
	mov rdx, r12      ; size_t n
	dec rdx
	call ft_memcpy

.finish:
	pop r12
	pop r13
	leave
	ret
