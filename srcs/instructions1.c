/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:30:24 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 18:00:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_instruction		g_instruction[9] = {
	{"sa", 2, &do_sa}, {"sb", 2, &do_sb},
	{"ss", 2, &do_ss}, {"pa", 2, &do_pa},
	{"pb", 2, &do_pb}, {"ra", 2, &do_ra},
	{"rb", 2, &do_rb}, {"rr", 2, &do_rr},
	{"rra", 3, &do_rra}
};

void	do_instruction(t_stack *stack, char *line)
{
	int		i;

	i = 0;
	while ((i < 9) &&
			(ft_strncmp(g_instruction[i].data_type, line,
			 g_instruction[i].data_len)))
		i++;
	if (i < 9)
	{
		stack->tmp_stack_a = NULL;
		stack->tmp_stack_b = NULL;
		g_instruction[i].tab_elem(stack);
	}
}

void	do_sa(t_stack *stack)
{
	int i;

	i = 2;
	if (stack->stack_a_len <= 1)
		return ;
	if(!(stack->tmp_stack_a = malloc(sizeof(int) * stack->stack_a_len)))
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
}

void	do_sb(t_stack *stack)
{
	int	*newstack_b;
	int i;

	i = 2;
	if (stack->stack_b_len <= 1)
		return ;
	if(!(newstack_b = malloc(sizeof(int) * stack->stack_b_len)))
		error(ERR_MALLOC, stack);
	newstack_b[1] = stack->stack_b[0];
	newstack_b[0] = stack->stack_b[1];
	while (i < stack->stack_b_len)
	{
		newstack_b[i] = stack->stack_b[i];
		i++;
	}
	free(stack->stack_b);
	stack->stack_b = NULL;
	stack->stack_b = ft_strdupint(newstack_b);
	free(newstack_b);
	newstack_b = NULL;
}

void	do_ss(t_stack *stack)
{
	do_sa(stack);
	do_sb(stack);
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
}
