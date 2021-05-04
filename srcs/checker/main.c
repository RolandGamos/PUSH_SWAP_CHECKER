/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:43:56 by user42            #+#    #+#             */
/*   Updated: 2021/05/04 16:09:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	read_input(t_stack *stack)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret != 0 && ft_strlen(line) != 0)
			do_instruction(stack,line);
		printf("line %s\n", line);
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
	free(line);
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
	read_input(&stack);
	if (check_sorting(stack.stack_a, stack.stack_a_len) == 1)// faudra check que b est vide aussi
		printf("OK\n");
	else
		printf("KO\n");
	free(stack.stack_a);
	return (0);
}