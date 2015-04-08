; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_memcpy.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/04 17:34:44 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/04 17:34:44 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

; rdi, rsi, rdx

section .text
	global ft_memcpy

ft_memcpy:
	cmp rdi, 0
	jz .finish
	enter 8, 0
	push rdi

.while:
	mov rcx, rdx     ; Taille du buffer a reecrire
	rep movsb        ; loop rdi->rcx++ = rax

.finish:
	pop rdi
	mov rax, rdi
	leave
	ret
