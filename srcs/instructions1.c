/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:30:24 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 18:31:52 by user42           ###   ########.fr       */
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

void	do_instruction(t_stack stack, char *line)
{
	int		i;

	i = 0;
	while ((i < 9) &&
			(ft_strncmp(g_instruction[i].data_type, line,
			 g_instruction[i].data_len)))
		i++;
	if (i <= 9)
		g_instruction[i].tab_elem(stack);
}

int		*ft_strdupint(int *s)
{
	int		i;
	int		size;
	int	*str;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (!(str = malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	do_sa(t_stack stack)
{
	int	*newstack_a;
	unsigned int i;

	i = 2;
	if(!(newstack_a = malloc(sizeof(int) * stack.stack_a_len)))
		error(ERR_MALLOC, &stack);
	newstack_a[1] = stack.stack_a[0];
	newstack_a[0] = stack.stack_a[1];
	while (i < stack.stack_a_len)
	{
		newstack_a[i] = stack.stack_a[i];
		i++;
	}
	free(stack.stack_a);
	stack.stack_a = NULL;
	stack.stack_a = ft_strdupint(newstack_a);
	free(newstack_a);
	newstack_a = NULL;
}

void	do_sb(t_stack stack)
{
	(void)stack;
}

void	do_ss(t_stack stack)
{
	(void)stack;
}

void	do_pa(t_stack stack)
{
	(void)stack;
}
