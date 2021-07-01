/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:32:19 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/26 17:32:27 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

static void	display_message(t_buf **buf)
{
	mt_putstring((*buf)->buffer);
	mt_putchar('\n');
	buffer_reset(buf);
}

static void	receive(int sig)
{
	static int		pos;
	static char		c;

	if (sig == SIGUSR2)
	{
		c = c << 1;
		c += 1;
	}
	else if (sig == SIGUSR1)
	{
		c = c << 1;
	}
	if (pos == 7)
	{
		buffer_add(getbuf(), c);
		if (c == '\0')
			display_message(getbuf());
		pos = 0;
		c = 0;
	}
	else
		pos++;
}

static void	print_server_pid(void)
{
	char	*pid_str;

	mt_putstring("server PID: ");
	pid_str = mt_itoa((long)getpid());
	if (!pid_str)
		error("Allocation failure");
	mt_putstring(pid_str);
	mt_putstring("\n");
	free(pid_str);
}

int	main(void)
{
	print_server_pid();
	buffer_init(getbuf());
	signal(SIGUSR1, &receive);
	signal(SIGUSR2, &receive);
	while (1)
	{
		pause();
	}
	buffer_delete(getbuf());
	return (0);
}
