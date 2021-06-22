/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:36:44 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/21 19:24:32 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	error(const char *err_msg)
{
	mt_putstring("Error\n");
	mt_putstring(err_msg);
	mt_putchar('\n');
	exit(1);
}

void	mt_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_tmp;

	if (n == 0)
		return ;
	s_tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		s_tmp[i] = '\0';
		i++;
	}
}

void	mt_putchar(char c)
{
	write(1, &c, 1);
}

void	mt_putstring(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}
