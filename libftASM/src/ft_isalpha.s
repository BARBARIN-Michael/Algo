; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_isalpha.s                                       :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/03 10:31:39 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/03 10:31:39 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

;rdi (param 1), rsi (param 2), rdx (param 3), rcx (var), rbx (var), eax (retour)

section .text
	global ft_isalpha

ft_isalpha:
	mov eax, 1

.lowercase:
	cmp rdi, 'a'
	jl .uppercase
	cmp rdi, 'z'
	jg .finishKO
	jmp .finishOK

.uppercase:
	cmp rdi, 'A'
	jge .uppercasel
	jmp .finishKO

.uppercasel:
	cmp rdi, 'Z'
	jg .finishKO
	jmp .finishOK

.finishKO:
	mov eax, 0
	ret

.finishOK:
	mov eax, 1
	ret

