/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:28:36 by laugarci          #+#    #+#             */
/*   Updated: 2023/07/06 13:23:49 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	check_signal(int signal)
{
	static int	rec;

	if (signal == SIGINT)
		rec = 1;
	return (rec);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = flag * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10;
		j = j + str[i] - 48;
		i++;
	}
	return (j * flag);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Incorrect PID\n", 14);
				exit(-1);
			}
		}
		else if (kill(pid, SIGUSR2) == -1)
		{
			{
				write(1, "Incorrect PID\n", 14);
				exit(-1);
			}
		}
		usleep(500);
		bit++;
	}
	return (check_signal(0));
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		write(1, "Arguments error. Abort\n", 24);
	if (ac != 3)
		return (0);
	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i++]))
		{
			write(1, "Error: invalid PID\n", 19);
			return (0);
		}
	}
	signal(SIGINT, (void *)&check_signal);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i] != '\0')
		if (ft_send_bits(pid, av[2][i++]))
			if (ft_send_bits(pid, '\0'))
				break ;
	return (0);
}
