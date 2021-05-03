/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/30 18:03:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int		check_sorting(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack.stack_a[i])
	{
		j = i + 1;
		while(stack.stack_a[j])
		{
			if (stack.stack_a[i] > stack.stack_a[j] && j < stack.stack_a_len)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}