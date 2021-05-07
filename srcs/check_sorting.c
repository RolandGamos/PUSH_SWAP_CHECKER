/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:30:02 by user42            #+#    #+#             */
/*   Updated: 2021/05/07 18:51:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int		check_sorting(int *stack, int len)
{

  int a = 1, d = 1, i = 0;

		//	printf("taille i: %d\n", len);
//	for (int j = 0; j < len; j++)
	//	printf("stack_i[%d] %d\n",j , stack[j]);
//	printf("\n");
  while ((a == 1 || d == 1) && i < len - 1) {
    if (stack[i] < stack[i+1])
      d = 0;
    else if (stack[i] > stack[i+1])
      a = 0;
    i++;
}
  if (a == 1)
    return 1;
  else if (d == 1)
    return 2;
  else
    return 0;
}


int		check_sorting2(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = i;
		while(stack[j])
		{
			if (stack[i] < stack[j] && j < len)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
