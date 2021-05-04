/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 17:58:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	split_stack(t_stack *stack)
{
	int	pivot;

	pivot = find_median(*stack);
	while (has_lower(pivot, stack)) // pb quand median fin de la stack
	{
		if (pivot >= stack->stack_a[0])
			do_pb(stack);
		else
			do_ra(stack);
	}
	stack->stack_a_lowest = find_lowest(stack->stack_a, stack->stack_a_len);
	stack->stack_b_lowest = find_lowest(stack->stack_b, stack->stack_b_len);
	stack->stack_a_highest = find_highest(stack->stack_a, stack->stack_a_len);
	stack->stack_b_highest = find_highest(stack->stack_b, stack->stack_b_len);
}

void	sort_stackb(t_stack *stack)
{
	if (check_sorting2(stack->stack_b, stack->stack_b_len) == 1)
		return;
	while (stack->stack_b[0] != stack->stack_b_lowest) // 1 la plus petite valeur de la stack b
	{
		if (stack->stack_b[1] > stack->stack_b[0])
			do_sb(stack);
		if (check_sorting2(stack->stack_b, stack->stack_b_len) == 1)
			return;
		do_rb(stack);
	}
	while (stack->stack_b[0] != stack->stack_b_highest) // 7 la plus grande valeur de la stack b
	{
		if(stack->stack_b[1] > stack->stack_b[0])
				do_sb(stack);
		if (check_sorting2(stack->stack_b, stack->stack_b_len) == 1)
			return;
		do_rrb(stack);
	}
	sort_stackb(stack);
}

void	sort_stacka(t_stack *stack)
{
	if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
	while (stack->stack_a[0] != stack->stack_a_lowest) // 8 la plus petite valeur de la stack a
	{
		if (stack->stack_a[1] < stack->stack_a[0])
			do_sa(stack);
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
		do_rra(stack);
	}
	while (stack->stack_a[0] != stack->stack_a_highest) // 173 la plus grande valeur de la stack a
	{
		if(stack->stack_a[1] < stack->stack_a[0])
				do_sa(stack);
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
		do_ra(stack);
	}
	sort_stacka(stack);
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
	sort_stackb(&stack);
	sort_stacka(&stack);
	while (stack.stack_b_len)
		do_pa(&stack);

	printf("taille b: %d\n", stack.stack_b_len);
	for (int i = 0; i < stack.stack_b_len; i++)
		printf("stack_b[%d] %d\n",i , stack.stack_b[i]);
	printf("\n");
	printf("taille a: %d\n", stack.stack_a_len);
	for (int i = 0; i < stack.stack_a_len; i++)
		printf("stack_a[%d] %d\n",i , stack.stack_a[i]);
	printf("\n");
	printf("i %d\n", stack.i);
	free(stack.stack_a);
}