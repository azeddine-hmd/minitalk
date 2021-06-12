#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// utils
void	mt_putchar(char c);
void	mt_putstring(const char *s);
char	*mt_itoa(long n);
int		mt_atoi(const char *str);
void	mt_bzero(void *s, size_t n);
void	error(const char *err_msg);
void	mt_strlen(const char *s);

#endif
