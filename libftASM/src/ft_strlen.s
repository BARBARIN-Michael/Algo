; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strlen.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2015/04/04 10:24:00 by mbarbari          #+#    #+#              #
;    Updated: 2015/04/04 10:24:00 by mbarbari         ###   ########.fr        #
;                                                                              #
; **************************************************************************** #

; rdi

section .text
	global ft_strlen

ft_strlen:
	mov rax, 0
	cmp rdi, 0
	jz .leave

.while:
	xor al, al
	xor rcx, rcx
	dec rcx         ; on rep que sur une valeur <>0
	repne scasb
	inc rcx         ; on enleve le hack de la decrementation
	not rcx         ; passe la valeur en positive (equivalent a neg)

.leave:
	mov rax, rcx
	ret
