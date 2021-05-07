/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:30:24 by user42            #+#    #+#             */
/*   Updated: 2021/05/07 21:05:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_sa(t_stack *stack)
{
	int i;

	i = 2;
	if (stack->stack_a_len <= 1)
		return ;
	if (!(stack->tmp_stack_a = malloc(sizeof(int) * stack->stack_a_len)))
		error(ERR_MALLOC, stack);
	stack->tmp_stack_a[1] = stack->stack_a[0];
	stack->tmp_stack_a[0] = stack->stack_a[1];
	while (i < stack->stack_a_len)
	{
		stack->tmp_stack_a[i] = stack->stack_a[i];
		i++;
	}
	free(stack->stack_a);
	stack->stack_a = NULL;	
	stack->stack_a = ft_strdupint(stack->tmp_stack_a);
	free(stack->tmp_stack_a);
	stack->tmp_stack_a = NULL;
	stack->i++;
}

void	do_sb(t_stack *stack)
{
	int i;

	i = 2;
	if (stack->stack_b_len <= 1)
		return ;
	if (!(stack->tmp_stack_b = malloc(sizeof(int) * stack->stack_b_len)))
		error(ERR_MALLOC, stack);
	stack->tmp_stack_b[1] = stack->stack_b[0];
	stack->tmp_stack_b[0] = stack->stack_b[1];
	while (i < stack->stack_b_len)
	{
		stack->tmp_stack_b[i] = stack->stack_b[i];
		i++;
	}
	free(stack->stack_b);
	stack->stack_b = NULL;
	stack->stack_b = ft_strdupint(stack->tmp_stack_b);
	free(stack->tmp_stack_b);
	stack->tmp_stack_b = NULL;
	stack->i++;
}

void	do_pa(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (stack->stack_b_len <= 0)
		return ;
	if (!(stack->tmp_stack_a = malloc(sizeof(int) * ++stack->stack_a_len)))
		error(ERR_MALLOC, stack);
	if (!(stack->tmp_stack_b = malloc(sizeof(int) * --stack->stack_b_len)))
		error(ERR_MALLOC, stack);
	stack->tmp_stack_a[0] = stack->stack_b[0];
	while (++i < stack->stack_b_len + 1)
	{
		stack->tmp_stack_b[j] = stack->stack_b[i];
		j++;
	}
	i = 0;
	j = 0;
	while (++i < stack->stack_a_len)
	{
		stack->tmp_stack_a[i] = stack->stack_a[j];
		j++;
	}
	put_in_stack(stack);
	stack->i++;
}

void	do_pb(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (stack->stack_a_len <= 0)
		return ;
	if (!(stack->tmp_stack_b = malloc(sizeof(int) * ++stack->stack_b_len)))
		error(ERR_MALLOC, stack);
	if (!(stack->tmp_stack_a = malloc(sizeof(int) * --stack->stack_a_len)))
		error(ERR_MALLOC, stack);
	stack->tmp_stack_b[0] = stack->stack_a[0];
	while (++i < stack->stack_a_len + 1)
	{
		stack->tmp_stack_a[j] = stack->stack_a[i];
		j++;
	}
	i = 0;
	j = 0;
	while (++i < stack->stack_b_len)
	{
		stack->tmp_stack_b[i] = stack->stack_b[j];
		j++;
	}
	put_in_stack(stack);
	stack->i++;
}
