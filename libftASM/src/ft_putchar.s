; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_putchar.s                                       :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/02 15:16:03 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/02 15:16:03 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

section .text
	global	ft_putchar

ft_putchar:
	push	rbp
	mov		[rbp], di
	mov		rsi, rbp
	mov		rdi, 1
	mov		rdx, 1
	mov		rax, 0x2000004 
	syscall
	pop		rbp
	ret
