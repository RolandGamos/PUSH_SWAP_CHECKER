/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:43:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 17:13:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 2)
		error(ERR_ARG, &stack);
	stack.av = av;
	fill_stack(&stack);
	for (int i = 0; stack.stack_a[i]; i++)
		printf("list[%d] %d\n",i , stack.stack_a[i]);
	if (ac > 3)
	{

	}
	free(stack.stack_a);
}