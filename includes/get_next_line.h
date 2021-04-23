/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:31:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/23 23:34:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include "push_swap.h"

#define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);

char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
int		ft_strlenc(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	ft_bzero(void *s, size_t n);

#endif