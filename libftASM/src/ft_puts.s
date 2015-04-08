; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_puts.s                                          :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/03 15:43:26 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/03 15:43:26 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	extern ft_strlen
	global ft_puts

ft_puts:
	enter 0, 0
	mov r8, 0
	xor rax, rax
	xor rbx, rbx

.iserror:
	mov rsi, rdi          ; move char * dans l'arg write
	cmp rsi, 0
	jnz .writechain
	lea rsi, [rel .endnull]
	mov rdx, .endlen
	jmp .write

.writechain:
	call ft_strlen
	mov rdx, rax          ; longueur de la chaine
	jmp .write

.writeendfile:
	lea rsi, [rel .endline]
	mov rdx, 1            ; longueur de endline
	inc r8

.write:
	mov rax, 0x2000004    ; appel a write
	mov rdi, 1            ; fd stdout
	syscall
	add rbx, rax          ; Rajout des caracteres retourne
	cmp r8, 0
	jz .writeendfile

.finish:
	mov rax, rbx
	leave
	ret

section .data
	.endnull	db "(null)"
	.endlen		equ $ - .endnull
	.endline	db 10
