/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:37:30 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/21 19:27:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*char_to_bitarr(char c)
{
	char	*bit_arr;
	int		bit;
	int		i;

	bit_arr = malloc(9);
	if (!bit_arr)
		error("Allocation failure");
	bit_arr[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		bit = c & (1 << i);
		if (bit == 0)
			bit_arr[i] = '0';
		else
			bit_arr[i] = '1';
		i--;
	}
	return (bit_arr);
}

static void	send_termination_signal(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(SIGNAL_INTERVAL);
		i++;
	}
}

static void	send(int pid, const char *msg)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (msg[i])
	{
		tmp = char_to_bitarr(msg[i]);
		if (!tmp)
			error("Allocation failure");
		j = ft_strlen(tmp) - 1;
		while (j >= 0)
		{
			if (tmp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(SIGNAL_INTERVAL);
			j--;
		}
		free(tmp);
		i++;
	}
	send_termination_signal(pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		error("Usage: ./client pid message");
	pid = mt_atoi(argv[1]);
	if (pid == -1)
		error("Unable to convert pid to integer");
	send(pid, argv[2]);
	return (0);
}
