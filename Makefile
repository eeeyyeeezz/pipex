NAME = pipex

SRC =	src/utils.c \
		src/utils2.c \
		src/pars.c \
		src/heredoc.c


RED = "\033[1;31m"
BLUE = "\033[1;34m"
YELLOW = "\033[1;33m"
WHITE = "\033[1;37m"
GREEN = "\033[1;32m"
PURPLE = "\033[1;35m"
GRAY = "\033[1;30m"
NORMAL = "\033[0m"

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	@${CC} ${CFLAGS} ${SRC} main.c -o ${NAME} -Llibft -lft -Ilibft
	@echo ${GREEN}"Compile pipex done! ✅"${NORMAL}

${LIBFT}:
	make -C libft

BONUS:
	@${CC} ${CFLAGS} ${SRC} bonus_pipex.c libft/libft.a -o pipex_bonus
	@echo ${GREEN}"Compile pipex_bonus done! ✅"${NORMAL}

clean: 
	@rm -rf src/*.o
	@make clean -C libft
	@echo ${YELLOW}"Clean pipex Done!"${NORMAL}

fclean: clean
	@rm -rf pipex
	@rm -rf pipex_bonus
	@make fclean -C libft
	@echo ${YELLOW}"fClean pipex Done!"${NORMAL}

re: fclean all

.PHONY: all clean fclean re