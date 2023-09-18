/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:07:40 by asenel            #+#    #+#             */
/*   Updated: 2023/09/18 18:45:42 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int a)
{
	if (a > 9)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
}

void	ft_print_bits(int sig)
{
	static char	a = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		a = ((a << 1) | 1);
	else
		a = ((a << 1) | 0);
	if (i == 7)
		write(1, &a, 1);
	i++;
	if (i == 8)
		i = 0;
}

int	main(void)
{
	write(1, "GETPID ID : ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_print_bits);
	signal(SIGUSR2, ft_print_bits);
	while (42)
		pause();
	return (0);
}
