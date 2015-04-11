; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_memalloc.s                                      :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/04 17:34:44 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/04 17:34:44 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	extern malloc
	extern ft_bzero 
	global ft_memalloc

ft_memalloc:
	mov r12, rdi
	enter 0, 0
	call malloc
	cmp rax, 0
	je end
	mov rdi, rax
	mov rsi, r12
	call ft_bzero

end:
	leave
	ret
