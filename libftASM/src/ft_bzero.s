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
	global ft_bzero

ft_bzero:
	enter 0, 0
	cmp rdi, 0
	je end

boucle:
	cmp rsi, 0
	je end
	mov [rdi], byte 0
	inc rdi
	dec rsi
	jmp boucle

end:
	leave
	ret
