/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 13:50:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int		check_sorting(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
			printf("taille a check: %d\n", stack.stack_a_len);
		for (int i = 0; i < stack.stack_a_len; i++)
		printf("stack_a[%d] check %d\n",i , stack.stack_a[i]);
		printf("\n");
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