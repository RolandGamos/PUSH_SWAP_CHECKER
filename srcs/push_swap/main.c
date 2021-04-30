/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/04/30 17:01:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <math.h>

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

int	int_pow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		if(exp %2)
			result *= base;
		exp /= 2;
		base *= base;
	}
	return (result);
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
		printf("stack i %d\n", stack.stack_a[i]);
		printf("count %d\n", count);
		i++;
	}
	return (stack.stack_a[i]);
}

void	solve(t_stack *stack)
{
	int i;
	int	pivot;
	i = 0;
	//pivot = stack->stack_a[stack->stack_a_len / 2];
	pivot = find_median(*stack);
	printf("pivot :%d\n", pivot);
	while (has_higher(pivot, stack))
	{
		if (pivot < stack->stack_a[0])
			do_pb(stack);
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