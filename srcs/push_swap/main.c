/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:46:42 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 17:58:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	split_stack(t_stack *stack)
{
	int	pivot;

	pivot = find_median(*stack);
	printf("pivot %d\n", pivot);
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
	printf("high%d\n", stack->stack_a_lowest);
}

void	sort_stackb(t_stack *stack)
{
	if (check_sorting(stack->stack_b, stack->stack_b_len) == 2)
		return;
	while (stack->stack_b[0] != stack->stack_b_lowest)
	{
		if (stack->stack_b[1] > stack->stack_b[0])
			do_sb(stack);
		else
			do_rb(stack);
		if (check_sorting2(stack->stack_b, stack->stack_b_len) == 2)
			return;
	}
	while (stack->stack_b[0] != stack->stack_b_highest)
	{
		if(stack->stack_b[1] > stack->stack_b[0])
				do_sb(stack);
		else
			do_rrb(stack);
		if (check_sorting2(stack->stack_b, stack->stack_b_len) == 2)
			return;
	}
	sort_stackb(stack);
}

void	sort_stacka(t_stack *stack)
{
	if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
	while (stack->stack_a[0] != stack->stack_a_lowest)
	{
		if (stack->stack_a[1] < stack->stack_a[0])
			do_sa(stack);
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
		do_rra(stack);
	}
	while (stack->stack_a[0] != stack->stack_a_highest)
	{
		if(stack->stack_a[1] < stack->stack_a[0])
				do_sa(stack);
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1)
		return ;
		do_ra(stack);
	}
	sort_stacka(stack);
}

void	sort_stack(t_stack *stack)
{	
	if (check_sorting(stack->stack_a, stack->stack_a_len) == 1 && check_sorting(stack->stack_b, stack->stack_b_len) == 2)
		return ;
	while (stack->stack_a[0] != stack->stack_a_lowest && stack->stack_b[0] != stack->stack_b_highest)
	{
		if (stack->stack_a[1] < stack->stack_a[0] && stack->stack_b[1] > stack->stack_b[0])
			do_ss(stack);
		else if (stack->stack_a[1] < stack->stack_a[0])
			do_sa(stack);
		else if(stack->stack_b[1] > stack->stack_b[0])
			do_sb(stack);
	//	else
			do_rrr(stack);
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1 && check_sorting(stack->stack_b, stack->stack_b_len) == 2)
			return ;
	}
	while (stack->stack_a[0] != stack->stack_a_highest && stack->stack_b[0] != stack->stack_b_lowest)
	{
		if(stack->stack_a[1] < stack->stack_a[0] && stack->stack_b[1] > stack->stack_b[0])
			do_ss(stack);
		else if (stack->stack_a[1] < stack->stack_a[0])
			do_sa(stack);
		else if (stack->stack_b[1] > stack->stack_b[0])
			do_sb(stack);
	//	else
			do_rr(stack);
		if (check_sorting(stack->stack_a, stack->stack_a_len) == 1 && check_sorting(stack->stack_b, stack->stack_b_len) == 2)
		return ;
	}
	sort_stack(stack);

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
	if (stack.stack_a_len > 3)
		split_stack(&stack);
		/*
	if (stack.stack_a_len > 1)
		sort_stacka(&stack);
	if (stack.stack_b_len > 1)
		sort_stackb(&stack);
		*/
	sort_stack(&stack);// si une des deux est sort on quitte cett fonction
	// deux fonctions pour sort la stack qui reste à sorte
	while (stack.stack_b_len)
		do_pa(&stack);
		free(stack.stack_b);
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