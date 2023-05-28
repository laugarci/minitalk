/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:28:51 by laugarci          #+#    #+#             */
/*   Updated: 2023/05/28 18:18:04 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void ft_bits(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i = i | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int main(int ac, char **argv)
{
    int pid;

    if (ac != 1)
    {
        printf("Error\n");
        return 1;
    }
    pid = getpid();
    printf("%d\n", pid);
	while(ac == 1)
	{	
		signal(SIGUSR1, ft_bits);
		signal(SIGUSR2, ft_bits);
		pause();
	}
    return 0;
}
