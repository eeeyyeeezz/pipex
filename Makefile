NAME = pipex

SRC =	src/utils.c \
		src/utils2.c \
		src/pars.c \
		src/heredoc.c


GREEN = "\033[1;32m"

NORMAL = "\033[0m"

CC = gcc

CFLAGS = -Wall -Wextra -Werror


all: ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRC} main.c libft/libft.a -o ${NAME}
	@echo ${GREEN}"Compile Done!"${NORMAL}

BONUS:
	@${CC} ${CFLAGS} ${SRC} bonus_pipex.c libft/libft.a -o pipex_bonus
	@echo ${GREEN}"Compile Done!"${NORMAL}

clean: 
	@rm -rf pipex
	@echo ${GREEN}"Clean Done!"${NORMAL}

fclean: clean
	@rm -rf pipex_bonus
	@echo ${GREEN}"fClean Done!"${NORMAL}

re: fclean all

.PHONY: all clean fclean re

