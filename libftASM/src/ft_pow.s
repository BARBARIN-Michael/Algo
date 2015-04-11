; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_pow.s                                           :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/02 15:16:03 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/02 15:16:03 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

; int ft_pow(int valeur, int puissance);

section .text
	global ft_pow

ft_pow:
	mov r8, rdi
	dec rsi
	mov rax, rdi

pow:
	imul rax, r8
	jc endKO
	dec rsi
	cmp rsi, 0
	jne pow

end:
	ret

endKO:
	mov rax, 1
	ret
