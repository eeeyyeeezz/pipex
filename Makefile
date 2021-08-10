NAME = pipex

SRC =	src/utils.c \
		src/utils2.c \
		src/pars.c \
		src/heredoc.c


GREEN = "\033[1;32m"

NORMAL = "\033[0m"

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS =	pipex.h \
			libft/libft.h

LIBFT = libft/libft.a

all: ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRC} main.c -o ${NAME} ${LIBFT}
	@echo ${GREEN}"Compile Done!"${NORMAL}

BONUS:
	@${CC} ${CFLAGS} ${SRC} bonus_pipex.c libft/*.c -o pipex_bonus
	@echo ${GREEN}"Compile Done!"${NORMAL}

clean: 
	@rm -rf pipex
	@rm -rf libft/*.o
	@echo ${GREEN}"Clean Done!"${NORMAL}

fclean: clean
	@rm -rf pipex_bonus
	@rm -rf libft/*.o
	@rm -rf libft/libft.a
	@echo ${GREEN}"fClean Done!"${NORMAL}

re: fclean all

.PHONY: all clean fclean re

