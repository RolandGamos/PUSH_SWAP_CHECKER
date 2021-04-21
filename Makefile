# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 12:44:51 by user42            #+#    #+#              #
#    Updated: 2021/04/21 20:38:13 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

SRCS  =   srcs/fill_stack.c srcs/error.c srcs/utils.c  srcs/instructions1.c  srcs/instructions2.c \
		  srcs/gnl/get_next_line_utils.c srcs/gnl/get_next_line.c \


RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "compile main checker with push_swap.a"
	@$(CC) -g -fsanitize=address srcs/checker/main.c -o checker push_swap.a
	@echo "compile main push_swap with push_swap.a"
	@$(CC) srcs/push_swap/main.c -o push_swap push_swap.a
clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)
	$(RM) checker push_swap

re: fclean all