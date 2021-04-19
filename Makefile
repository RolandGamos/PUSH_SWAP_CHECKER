# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 12:44:51 by user42            #+#    #+#              #
#    Updated: 2021/04/19 12:47:46 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = pushswap.a

FLAGS = -Wall -Wextra -Werror

SRCS =   /

RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	$(CC) srcs/checker/main.c -o checker
	$(CC) srcs/push_swap/main.c -o push_swap
clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)

re: fclean all