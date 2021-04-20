/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:44:11 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 17:23:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define ERR_VALUE1 -1
#define ERR_VALUE2 -2
#define ERR_VALUE3 -3
#define ERR_ARG -4
#define ERR_MALLOC -5

typedef struct 	s_stack
{
		int 	*stack_a;
		int 	*stack_b;
		char	**av;
}			 	t_stack;

void	fill_stack(t_stack *stack);
void	error(int errcode, t_stack *stack);

int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);

int 	ft_count_arg(char **list);

#endif