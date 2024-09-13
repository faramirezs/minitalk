/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:20:30 by alejandrora       #+#    #+#             */
/*   Updated: 2024/09/13 10:33:28 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>

int		ft_unsigned_int(unsigned int n);
int		ft_putnbr(int n);
int		ft_hexa_helper(unsigned int n, char format);
int		ft_hexa(unsigned int n, char format);
int		ft_pointer_helper(unsigned long n);
int		ft_pointer(unsigned long n);
size_t	ft_strlen(char const *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_write_options(va_list val, char c);
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);

#endif
