/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:30:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 20:52:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_pb(t_stack *stack)
{
	int *newstack_a;
	int *newstack_b;
	int i = 1;
	int j = 0;
	if(!(newstack_b = malloc(sizeof(int) * stack->stack_b_len + 1)))
		error(ERR_MALLOC, stack);
	if(!(newstack_a = malloc(sizeof(int) * stack->stack_a_len - 1)))
		error(ERR_MALLOC, stack);
	newstack_b[0] = stack->stack_a[0];
	stack->stack_a_len--;
	stack->stack_b_len++;
	while (i < stack->stack_a_len + 1)
	{
		newstack_a[j] = stack->stack_a[i];
		i++;
		j++;
	}
	i = 1;
	j = 0;
	while (i < stack->stack_b_len)
	{
		newstack_b[i] = stack->stack_b[j];
		j++;
		i++;
	}
	free(stack->stack_a);
	stack->stack_a = NULL;
	stack->stack_a = ft_strdupint(newstack_a);
	free(newstack_a);
	if (stack->stack_b != NULL)
	{
		free(stack->stack_b);
		stack->stack_b = NULL;
	}
	stack->stack_b = ft_strdupint(newstack_b);
	free(newstack_b);
	newstack_b = NULL;
}

void	do_ra(t_stack *stack)
{
	(void)stack;
}

void	do_rb(t_stack *stack)
{
	(void)stack;
}

void	do_rr(t_stack *stack)
{
	(void)stack;
}

void	do_rra(t_stack *stack)
{
	(void)stack;
}
