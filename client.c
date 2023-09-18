/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:47:11 by asenel            #+#    #+#             */
/*   Updated: 2023/09/18 15:57:35 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;
	int	total;

	i = 0;
	while (s[i])
	{
		total = (s[i] - 48) + (total * 10);
		i++;
	}
	return (total);
}

void	ft_sendbit(int pid, char *str)
{
	size_t	i;
	int		shift;
	char	char_print;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] <= 127)
		{
			shift = 7;
			char_print = str[i];
			while (shift != -1)
			{
				if ((char_print >> shift) & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				shift--;
				usleep(100);
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_sendbit(ft_atoi(av[1]), av[2]);
	}
	else
		write (1, "ARGUMENT ERROR!", 16);
	return (0);
}
