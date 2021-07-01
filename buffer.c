/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:13:27 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/26 17:21:27 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_buf	**getbuf(void)
{
	static t_buf	*buf;

	return (&buf);
}

void	buffer_delete(t_buf **buf)
{
	free((*buf)->buffer);
	free(*buf);
}

void	buffer_add(t_buf **buf, char c)
{
	(*buf)->buffer[(*buf)->pos] = c;
	(*buf)->pos++;
}

void	buffer_reset(t_buf **buf)
{
	mt_bzero((*buf)->buffer, (*buf)->pos + 1);
	(*buf)->pos = 0;
}

void	buffer_init(t_buf **buf)
{
	*buf = (t_buf *)malloc(sizeof(t_buf));
	if (!(*buf))
		error("Allocation failure");
	(*buf)->pos = 0;
	(*buf)->buffer = (char *)malloc(BUFFER_SIZE);
	if ((*buf)->buffer == NULL)
		error("Allocation failure");
	mt_bzero((*buf)->buffer, BUFFER_SIZE - 1);
}
