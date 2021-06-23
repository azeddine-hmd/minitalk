#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SIGNAL_INTERVAL 50

void	mt_putchar(char c);
void	mt_putstring(const char *s);
char	*mt_itoa(long n);
int		mt_atoi(const char *str);
void	mt_bzero(void *s, size_t n);
void	error(const char *err_msg);
int		ft_strlen(const char *s);

#endif
