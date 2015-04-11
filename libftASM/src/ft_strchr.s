; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_bzero.s                                         :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/02 15:16:03 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/02 15:16:03 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	global ft_strchr

ft_strchr:
	cmp [rdi], sil
	je end
	cmp byte [rdi], 0
	je null
	inc rdi
	jmp ft_strchr

null:
	xor rdi, rdi

end:
	mov rax, rdi
	ret
