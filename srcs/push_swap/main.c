/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 23:37:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		has_higher(int pivot, t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (stack->stack_a[i])
	{
		j = 0;
		while(stack->stack_a[j])
		{
			if (pivot <stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	solve(t_stack *stack)
{
	int i;
	int	pivot;

	i = 0;
	pivot = stack->stack_a[stack->stack_a_len - 1];
	while (has_higher(pivot, stack))
	{
		if (pivot < stack->stack_a[0])
		{
			do_pb(stack);
		}
		else
			do_ra(stack);
	}

}

int main(int ac, char **av)
{
	t_stack	stack;

	if (ft_strncmp(av[1], "-v", 2) == 0)
		stack.option_v = 1;
	else
		stack.option_v = 0;
	init_stack(&stack,av, ac);
	fill_stack(&stack);
	//read_input(&stack);
	solve(&stack);
			printf("taille a: %d\n", stack.stack_a_len);
		for (int i = 0; i < stack.stack_a_len; i++)
		printf("stack_a[%d] %d\n",i , stack.stack_a[i]);
		printf("\n");
		if (stack.stack_b != NULL)
		{
			printf("taille b: %d\n", stack.stack_b_len);
		for (int i = 0; i < stack.stack_b_len ; i++)
		printf("stack_b[%d] %d\n",i , stack.stack_b[i]);
		}
	free(stack.stack_a);
}