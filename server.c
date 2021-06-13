#include "minitalk.h"

char	*mt_strcharjoin(char *s, char c)
{
	char *final;
	int i;

	i = 0;
	while (s[i])
		i++;
	final = (char*)malloc(i + 2);
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

void	receive(int sig)
{
	static int	pos;
	static char	c;
	static char	*msg;

	if (!msg)
	{
		msg = (char*)malloc(1);
		if (!msg)
			error("Allocation failure");
		msg[0] = '\0';
	}
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
		{
			mt_putstring(msg);
			free(msg);
			msg = NULL;
		}
		pos = 0;
		c = 0;
	}
	else
	{
		pos++;
	}
}

void	print_server_pid(void)
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

int			main(void)
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
