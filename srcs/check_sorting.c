/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:02 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 16:09:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int		check_sorting(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while(stack[j])
		{
			if (stack[i] > stack[j] && j < len)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_sorting2(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while(stack[j])
		{
			if (stack[i] < stack[j] && j < len)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
