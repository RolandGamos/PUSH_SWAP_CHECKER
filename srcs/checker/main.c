/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:43:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 18:11:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	read_input(t_stack stack)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(&line)) > 0)
	{
		if (ret != 0 && ft_strlen(line) != 0)
			do_instruction(stack,line);
		for (int i = 0; stack.stack_a[i]; i++)
		printf("list[%d] %d\n",i , stack.stack_a[i]);
		printf("taille %d\n", stack.stack_a_len);
		free(line);
		line = NULL;
	}
}

int main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 2)
		error(ERR_ARG, &stack);
	stack.av = av;
	stack.stack_a_len = ft_count_arg(av);
	fill_stack(&stack);
	read_input(stack);
	free(stack.stack_a);
}