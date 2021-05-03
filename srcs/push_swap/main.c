/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/05/03 20:46:21 by user42           ###   ########.fr       */
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
			if (pivot > stack->stack_a[j])
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

void	split_stack(t_stack *stack)
{
	int i;
	int	pivot;

	i = 0;
	pivot = find_median(*stack);
	while (has_lower(pivot, stack)) // pb quand median fin de la stack
	{

		printf("pivot %d\n", pivot);
		if (pivot >= stack->stack_a[0])
		{
			do_pb(stack);
			printf("pb\n");
		}
		else
		{
			do_ra(stack);
			printf("ra\n");
		}
	}
}

int		check_sorting2(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack.stack_b[i])
	{
		j = i + 1;
		while(stack.stack_b[j])
		{
			if (stack.stack_b[i] < stack.stack_b[j] && j < stack.stack_b_len)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	sort_stacks(t_stack *stack)
{
	if (check_sorting2(*stack) == 1)
		return;
	while (stack->stack_b[0] != 1) // 8 la plus petite valeur de la stack a
	{
		if (stack->stack_b[1] > stack->stack_b[0])
			do_sb(stack);
		do_rb(stack);
	}
	while (stack->stack_b[0] != 7) // 173 la plus grande valeur de la stack a
	{
		if(stack->stack_b[1] > stack->stack_b[0])
				do_sb(stack);
		do_rrb(stack);
	}
	sort_stacks(stack);
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
	split_stack(&stack);
	sort_stacks(&stack);
	printf("taille a: %d\n", stack.stack_a_len);
	for (int i = 0; i < stack.stack_a_len; i++)
		printf("stack_a[%d] %d\n",i , stack.stack_a[i]);
	printf("\n");
	printf("taille b: %d\n", stack.stack_b_len);
	for (int i = 0; i < stack.stack_b_len; i++)
		printf("stack_b[%d] %d\n",i , stack.stack_b[i]);
	printf("\n");
	printf("i %d\n", stack.i);
	free(stack.stack_a);
}