# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 16:39:14 by gmorra            #+#    #+#              #
#    Updated: 2020/11/09 14:03:56 by gmorra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

CC = gcc

RED = "\033[1;31m"
BLUE = "\033[1;34m"
YELLOW = "\033[1;33m"
WHITE = "\033[1;37m"
GREEN = "\033[1;32m"
PURPLE = "\033[1;35m"
GRAY = "\033[1;30m"
NORMAL = "\033[0m"

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c	ft_isdigit.c\
	ft_isprint.c ft_itoa.c ft_memccpy.c	ft_memchr.c	ft_memcmp.c	ft_memcpy.c	ft_memmove.c\
	ft_memset.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
	ft_strchr.c	ft_strdup.c	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c	ft_substr.c	ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			 ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): ${OBJ}
	@ar rc $(NAME) $(OBJ)
	@echo ${RED}"Compile libft done! ✅"${NORMAL}

bonus: ${OBJ} ${OBJ_BONUS}
	@ar rc $(NAME) $(OBJ) ${OBJ_BONUS}
	@echo ${RED}"Compile libft_bonus done! ✅"${NORMAL}

clean:
	@rm -f $(OBJ) ${OBJ_BONUS}
	@echo ${BLUE}"Clean libft Done!"${NORMAL}

fclean: clean
	@rm -f $(NAME)
	@echo ${BLUE}"fClean libft Done!"${NORMAL}

re: fclean all

.PHONY: all clean fclean re
