; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_isascii.s                                       :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/03 10:31:39 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/03 10:31:39 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;rdi (param 1), rsi (param 2), rdx (param 3), rcx (var), rbx (var), eax (retour)

section .text
	global ft_isascii

ft_isascii:
	cmp rdi, 0
	jl .finishKO
	cmp rdi, 127
	jg .finishKO

.finishOK:
	mov eax, 1
	ret

.finishKO:
	mov eax, 0
	ret
