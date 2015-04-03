; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_isalnum.s                                       :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/03 10:31:39 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/03 10:31:39 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;rdi (param 1), rsi (param 2), rdx (param 3), rcx (var), rbx (var), eax (retour)

section .text
	global ft_isalnum
	extern ft_isalpha
	extern ft_isdigit

ft_isalnum:
	enter 0, 0
	call ft_isalpha
	cmp rax, 1
	je .finishOK
	call ft_isdigit
	cmp rax, 1
	je .finishOK

.finishKO:
	leave
	ret

.finishOK:
	leave
	ret

