/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:49:05 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 18:11:31 by user42           ###   ########.fr       */
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