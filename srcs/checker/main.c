/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:43:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 20:54:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	read_input(t_stack *stack)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(&line)) > 0)
	{
		if (ret != 0 && ft_strlen(line) != 0)
			do_instruction(stack,line);
		printf("taille a: %d\n", stack->stack_a_len);
		for (int i = 0; i < stack->stack_a_len; i++)
		printf("stack_a[%d] %d\n",i , stack->stack_a[i]);
		printf("\n");
		if (stack->stack_b != NULL)
		{
			printf("taille b: %d\n", stack->stack_b_len);
		for (int i = 0; i < stack->stack_b_len ; i++)
		printf("stack_b[%d] %d\n",i , stack->stack_b[i]);
		}
		free(line);
		line = NULL;
	}
}

void	init_stack(t_stack *stack, char **av, int ac)
{
	stack->stack_a = NULL;
	stack->av = av;
	if (ac < 2)
		error(ERR_ARG, stack);
	stack->stack_a_len = ft_count_arg(av);
	stack->stack_b = NULL;
	stack->stack_b_len = 0;
}

int main(int ac, char **av)
{
	t_stack	stack;

	init_stack(&stack,av, ac);
	fill_stack(&stack);
	read_input(&stack);
	free(stack.stack_a);
}