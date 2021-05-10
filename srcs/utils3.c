/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:53:19 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 15:54:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		has_higher(int pivot, t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (stack->stack_a[i])
	{
		j = 0;
		while(j < stack->stack_a_len)
		{
			if (pivot < stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		has_lower(int pivot, t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (stack->stack_a[i])
	{
		j = 0;
		while(j < stack->stack_a_len)
		{
			if (pivot >= stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		find_median(t_stack stack)
{
	int i;
	int	j;
	int count;

	i = 0;
	while (stack.stack_a[i])
	{
		j = 0;
		count = 0;
		while (stack.stack_a[j])
		{
			if (stack.stack_a[i] >= stack.stack_a[j])
				count++;
			j++;
		}
		if (count == stack.stack_a_len / 2)
				break ;
		i++;
	}
	return (stack.stack_a[i]);
}

int		find_lowest(int *stack, int len)
{
	int i;
	int	j;
	int count;

	i = 0;
	while (stack[i])
	{
		j = 0;
		count = 0;
		while (j < len)
		{
			if (stack[i] <= stack[j])
				count++;
			j++;
		}
		if (count == len)
				break ;
		i++;
	}
	return (stack[i]);
}

int		find_highest(int *stack, int len)
{
	int i;
	int	j;
	int count;

	i = 0;
	while (stack[i])
	{
		j = 0;
		count = 0;
		while (j < len)
		{
			if (stack[i] >= stack[j])
				count++;
			j++;
		}
		if (count == len)
				break ;
		i++;
	}
	return (stack[i]);
}