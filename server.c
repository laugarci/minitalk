/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:28:51 by laugarci          #+#    #+#             */
/*   Updated: 2023/05/28 12:52:25 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bits(int sig)
{
    static int bit;
    static int i;

    if (sig == SIGUSR1)
        i = i | (1 << bit);

    bit = bit << 1;
    if (bit == 128)
    {
        ft_printf("%c", i);
        bit = 1;
        i = 0;
    }
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_bits);
		signal(SIGUSR2, ft_bits);
		pause ();
	}
	return (0);
}
