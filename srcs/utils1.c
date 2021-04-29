/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:49:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/26 12:03:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	printf("%c\n", c);
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

long	ft_atoi(const char *nptr, t_stack *stack)
{
	int		i;
	int		isnegative;
	long	nbr;

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
	while (nptr[i])
	{
		if(ft_isdigit(nptr[i]) == 0)
			error(ERR_VALUE1, stack);
		i++;
	}
	return (isnegative * nbr);
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
	return (tab);
}
