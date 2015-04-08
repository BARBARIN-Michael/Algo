; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_isprint.s                                       :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/03 15:39:06 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/03 15:39:06 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	global ft_isprint

ft_isprint:
	cmp rdi, 32
	jl .finishKO
	cmp rdi, 126
	jg .finishKO

.finishOK:
	mov eax, 1
	ret

.finishKO:
	mov eax, 0
	ret
