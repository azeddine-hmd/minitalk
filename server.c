/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:37:38 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/21 19:26:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*mt_strcharjoin(char *s, char c)
{
	char	*final;
	int		i;

	if (!s)
	{
		s = (char *)malloc(1);
		if (!s)
			error("Allocation failure");
		s[0] = '\0';
	}
	i = 0;
	while (s[i])
		i++;
	final = (char *)malloc(i + 2);
	if (!final)
		error("Allocation failure");
	i = -1;
	while (s[++i])
		final[i] = s[i];
	final[i] = c;
	final[i + 1] = 0;
	free(s);
	return (final);
}

static void	msg_concantenation_finished(char **msg)
{
	mt_putstring(*msg);
	mt_putchar('\n');
	free(*msg);
	*msg = NULL;
}

static void	receive(int sig)
{
	static int	pos;
	static char	c;
	static char	*msg;

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
		msg = mt_strcharjoin(msg, c);
		if (c == '\0')
			msg_concantenation_finished(&msg);
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
	signal(SIGUSR1, &receive);
	signal(SIGUSR2, &receive);
	while (1)
	{
		pause();
	}
	return (0);
}
