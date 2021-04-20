/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:41:51 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 17:12:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(int errcode, t_stack *stack)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (errcode == ERR_VALUE1)
		write(STDERR_FILENO, "Not a number\n", 13);
		if (errcode == ERR_VALUE2)
		write(STDERR_FILENO, "not an integer\n", 15);
	if (errcode == ERR_ARG)
		write(STDERR_FILENO, "Too few arguments\n", 18);
	if (errcode == ERR_MALLOC)
		write(STDERR_FILENO, "Malloc error\n", 13);
	
	free(stack->stack_a);
	exit(errcode);
}
