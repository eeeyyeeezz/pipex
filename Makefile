SRC =	src/utils.c \
		src/utils2.c \
		src/pars.c \
		src/heredoc.c


all: ${NAME}

RUN:
	@gcc ${SRC} main.c libft/libft.a -o pipex
	@echo "Compile Done!"

BONUS:
	@gcc ${SRC} bonus_pipex.c libft/libft.a -o pipex_bonus
	@echo "Compile Done!"


.PHONY: all clean fclean re

