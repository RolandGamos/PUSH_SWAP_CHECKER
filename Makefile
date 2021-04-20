# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 12:44:51 by user42            #+#    #+#              #
#    Updated: 2021/04/20 17:03:38 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

SRCS  =   srcs/fill_stack.c srcs/error.c srcs/libftutils.c 


RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "compile main checker with push_swap.a"
	@$(CC) srcs/checker/main.c -o checker push_swap.a
	@echo "compile main push_swap with push_swap.a"
	@$(CC) srcs/push_swap/main.c -o push_swap push_swap.a
clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)
	$(RM) checker push_swap

re: fclean all