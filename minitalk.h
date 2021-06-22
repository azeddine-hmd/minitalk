/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:37:18 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/06/21 18:39:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SIGNAL_INTERVAL 200

void	mt_putchar(char c);
void	mt_putstring(const char *s);
char	*mt_itoa(long n);
int		mt_atoi(const char *str);
void	mt_bzero(void *s, size_t n);
void	error(const char *err_msg);
void	mt_strlen(const char *s);
int		ft_strlen(const char *s);

#endif
