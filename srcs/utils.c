/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:49:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 18:24:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *nptr)
{
	int	i;
	long	nbr;
	int	isnegative;

	nbr = 0;
	isnegative = 1;
	i = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			isnegative = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (isnegative * nbr);
}

int ft_count_arg(char **list)
{
	int i;

	i = 0;
	while (list[i])
		i++;
	i--;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


int		*ft_strdupint(int *t)
{
	int		i;
	int		size;
	int		*tab;

	i = 0;
	size = 0;
	while (t[size])
		size++;
	if (!(tab = malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		tab[i] = t[i];
		i++;
	}
	//tab[i] = '\0';
	return (tab);
}

void	put_in_stack(t_stack *stack)
{
	free(stack->stack_a);
	stack->stack_a = NULL;
	stack->stack_a = ft_strdupint(stack->tmp_stack_a);
	free(stack->tmp_stack_a);
	stack->tmp_stack_a = NULL;
	if (stack->stack_b != NULL)
	{
		free(stack->stack_b);
		stack->stack_b = NULL;
	}
	stack->stack_b = ft_strdupint(stack->tmp_stack_b);
	free(stack->tmp_stack_b);
	stack->tmp_stack_b = NULL;
}
