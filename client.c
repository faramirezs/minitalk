/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:17:32 by alramire          #+#    #+#             */
/*   Updated: 2024/09/13 09:44:17 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	send_char_as_bits(pid_t server_pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			kill(server_pid, SIGUSR1);
		}
		else if (bit == 0)
		{
			kill(server_pid, SIGUSR2);
		}
		usleep(2000);
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	int		i;
	char	c;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Error");
		return (-1);
	}
	server_pid = (pid_t)ft_atoi(av[1]);
	while (av[2][i])
	{
		c = av[2][i];
		send_char_as_bits(server_pid, c);
		i++;
	}
	send_char_as_bits(server_pid, av[2][i]);
	return (0);
}
