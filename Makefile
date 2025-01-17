# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 12:44:51 by user42            #+#    #+#              #
#    Updated: 2021/05/13 16:40:11 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = checker.a

FLAGS = -Wall -Wextra -Werror

SRCS  =   srcs/fill_stack.c srcs/error.c srcs/utils1.c srcs/utils2.c srcs/utils3.c srcs/do_instruction.c srcs/instructions1.c    \
		  srcs/instructions2.c srcs/instructions3.c srcs/gnl/get_next_line_utils.c srcs/gnl/get_next_line.c srcs/check_sorting.c \


RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "compile main checker with checker.a"
	@$(CC) main.c -o checker checker.a
clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)
	$(RM) checker

re: fclean all