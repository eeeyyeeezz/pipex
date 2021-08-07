SRC =	utils.c \
		utils2.c


all: ${NAME}

RUN:
	@gcc ${SRC} main.c libft/libft.a -o pipex
	@echo "Compile Done!"

BONUS:
	@gcc ${SRC} bonus_pipex.c libft/libft.a -o pipex_bonus
	@echo "Compile Done!"

