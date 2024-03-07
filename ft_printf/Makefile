# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 12:21:27 by fcarlucc          #+#    #+#              #
#    Updated: 2023/05/21 21:11:11 by fcarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a

SRCS 	= ft_printf.c ft_printf_utils.c help.c dot.c dot_.c sharp.c sharp_.c \
			space.c space_.c plus.c plus_.c minus.c minus_.c minus_bonus.c \
			zero.c zero_.c zero_bonus.c zero_bonus_.c width.c width_.c \
			width_bonus.c width_bonus_.c width_and_len.c \

OBJS 	= ${SRCS:.c=.o}

CC	 	= gcc
RM 		= rm -f

FLAGS 	= -Wall -Wextra -Werror -g

.c:.o
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

bonus:	all

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re