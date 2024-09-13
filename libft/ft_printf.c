/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:20:27 by alramire          #+#    #+#             */
/*   Updated: 2024/09/13 10:34:59 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_write_options(va_list val, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(val, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(val, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(val, int)));
	else if (c == 'x' || c == 'X')
		return (ft_hexa((long)va_arg(val, char *), c));
	else if (c == 'p')
		return (ft_pointer((long)va_arg(val, char *)));
	else if (c == 'u')
		return (ft_unsigned_int(va_arg(val, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	val;
	int		len;

	i = 0;
	len = 0;
	va_start(val, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_write_options(val, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar((format[i]));
		i++;
	}
	va_end(val);
	return (len);
}
