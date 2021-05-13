/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:02:01 by user42            #+#    #+#             */
/*   Updated: 2021/05/13 16:36:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_instruction		g_instruction[11] = {
	{"rrb", 3, &do_rrb}, {"rra", 3, &do_rra},
	{"rrr", 3, &do_rrr}, {"sa", 2, &do_sa},
	{"sb", 2, &do_sb}, {"ss", 2, &do_ss},
	{"pa", 2, &do_pa}, {"pb", 2, &do_pb},
	{"ra", 2, &do_ra}, {"rb", 2, &do_rb},
	{"rr", 3, &do_rr}
};

void	do_instruction(t_stack *stack, char *line)
{
	int		i;
	int		ret;

	i = 0;
	while (i < 11)
	{
		if ((ret = ft_strncmp(g_instruction[i].data_type, line,
			ft_strlen(line)) == 0))
			break ;
		i++;
	}
	if (i < 11)
	{
		stack->tmp_stack_a = NULL;
		stack->tmp_stack_b = NULL;
		g_instruction[i].tab_elem(stack);
	}
}
