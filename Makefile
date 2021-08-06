SRC =	utils.c \
		utils_two.c

RUN:
	@gcc -g ${SRC} main.c -o pipex

BONUS:
	@gcc -g ${SRC} bonus_pipex.c -o pipex_bonus
