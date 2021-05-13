/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:40:20 by user42            #+#    #+#             */
/*   Updated: 2021/05/13 16:36:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	check_duplicates(t_stack *stack)
{
	int i;
	int j;
	int k;
	int *tmptab;

	i = 0;
	j = 0;
	k = 0;
	tmptab = stack->stack_a;
	while (stack->stack_a[i])
	{
		while (tmptab[j])
		{
			if (tmptab[j] == stack->stack_a[i])
				k++;
			if (k > 1)
				error(ERR_VALUE3, stack);
			j++;
		}
		i++;
	}
}

void	fill_stack(t_stack *stack)
{
	int		i;
	int		j;
	long	tmp_atoi;

	i = 1;
	j = 0;
	if (!(stack->stack_a = malloc(sizeof(int) * stack->stack_a_len)))
		error(ERR_MALLOC, stack);
	if (stack->option_v == 1)
		i = 2;
	while (stack->av[i])
	{
		tmp_atoi = ft_atoi(stack->av[i], stack);
		if (tmp_atoi < -2147483648 || tmp_atoi > 2147483647)
			error(ERR_VALUE2, stack);
		stack->stack_a[j] = (int)tmp_atoi;
		j++;
		i++;
	}
	check_duplicates(stack);
}
