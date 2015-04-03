; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_tolower.s                                       :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/03 15:43:26 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/03 15:43:26 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	extern ft_isdigit
	global ft_tolower

ft_tolower:
	enter 0, 0
	call ft_isdigit
	cmp eax, 1
	jne .finishKO
	cmp rdi, 'A'
	jl .finishKO
	cmp rdi, 'Z'
	jg .finishKO

.finishOK:
	mov rax, rdi
	mov rax, [rax + 32]
	leave
	ret

.finishKO:
	mov rax, rdi
	leave
	ret