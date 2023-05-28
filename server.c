/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:28:51 by laugarci          #+#    #+#             */
/*   Updated: 2023/05/28 16:16:31 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_bits(int sig)
{
    static int bit = 1;
    static int i = 0;

    if (sig == SIGUSR1)
        i = i | bit;

    bit = bit << 1;
    if (bit == 128)
    {
        ft_printf("%c", i);
        bit = 1;
        i = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 1)
    {
        ft_printf("Error\n");
        return 1;
    }
    pid = getpid();
    ft_printf("%d\n", pid);
    while (1)
    {
        signal(SIGUSR1, ft_bits);
        signal(SIGUSR2, ft_bits);
        pause();
    }
    return 0;
}

