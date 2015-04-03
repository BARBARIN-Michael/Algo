NAME = libfts.a

SRCS = src/ft_bzero.s \
	   src/ft_strcat.s \

INCLUDES = include/

OBJS = $(patsubst src/%.s,obj/%.o,$(SRCS))

NASM ?= nasm
MKDIR ?= mkdir

NFLAGS += -i $(realpath inc)/

ifeq ($(shell uname), Linux)
	NFLAGS += -felf64 -DLINUX
else
	NFLAGS += -fmacho64 -DOSX --prefix _ -g
endif

#CFLAGS += -Wall -Wextra -Werror -Iinclude/
CFLAGS += -Iinclude/

obj/%.o: src/%.s
	@$(MKDIR) -p $(dir $@)
	$(NASM) $(NFLAGS) -o $@ $<

all: $(NAME)

libasm.out: $(NAME) main.o
	$(CC) -Iinclude/ main.o -o $@ -L. -lfts 

lib.out: $(NAME) main.o
	$(CC) -I ./libft/Include/ main.o -o $@ -L. -lft

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

