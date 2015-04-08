; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strsplit.s                                         :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/02 15:16:03 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/02 15:16:03 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

; char **ft_strsplit(char *rdi, int rsi)

%macro t_r14 2
	lea rdi, [rel %1]
	mov rsi, %2
	call printf
%endmacro

section .data
	tests: db "test : %s", 10
	testd: db "test : %d", 10
	testn: db "test :", 10

section .text
	extern printf
	extern malloc
	extern ft_strdup
	global ft_strsplit

ft_strsplit:
	enter 4096, 0
	mov r8, rdi
	call ft_strdup
	mov r8, rax
	mov r12, rax              ; Chaine de caractere
	mov r13, rsi              ; caractere de recherche
	xor r14, r14              ; Compteur de char * pour le malloc
	mov r15, rax

.countchar:
	cmp [r8], byte 0
	je .malloc
	cmp [r8], byte r13
	jne .count
	inc r8
	jmp .countchar

.count:
	inc r14
	inc r8
	jmp .countchar

.malloc:
	t_r14
	leave
	ret
