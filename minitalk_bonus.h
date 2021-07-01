/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:31:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/26 17:34:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

# define BUFFER_SIZE INT_MAX
# define SIGNAL_INTERVAL 50

typedef struct s_buf
{
	int		pos;
	char	*buffer;
}t_buf;

void	mt_putchar(char c);
void	mt_putstring(const char *s);
char	*mt_itoa(long n);
int		mt_atoi(const char *str);
void	mt_bzero(void *s, size_t n);
void	error(const char *err_msg);
int		ft_strlen(const char *s);
void	buffer_init(t_buf **buffer);
void	buffer_reset(t_buf **buf);
void	buffer_add(t_buf **buf, char c);
void	buffer_delete(t_buf **buf);
t_buf	**getbuf(void);

#endif
