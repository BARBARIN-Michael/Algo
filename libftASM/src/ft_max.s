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
	global ft_max

ft_max:
	cmp             edi, esi
	jg				max
	mov				eax, esi
	ret

max:
	mov				eax, edi
	ret
