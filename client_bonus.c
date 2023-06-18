/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:28:03 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/07 11:55:10 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

void	send_bit(unsigned int c, int pid_id)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if (c >> bit & 1)
			kill(pid_id, SIGUSR1);
		else
			kill(pid_id, SIGUSR2);
		usleep(200);
	}
}

void	handler(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_putstr("Message recieved\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (ft_itsdigit(argv[1]) == 0)
		ft_putstr("(Error) Put only numbers on PID ID\n");
	else
	{
		if (argc == 3)
		{
			signal(SIGUSR2, handler);
			while (argv[2][++i])
				send_bit(argv[2][i], ft_atoi(argv[1]));
			send_bit(argv[2][i], ft_atoi(argv[1]));
			while (1)
				pause();
		}
		else
			ft_putstr("(Error) Try ./client <PID> <MSG>\n");
	}
	return (0);
}
