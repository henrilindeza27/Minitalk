/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:28:03 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/07 12:02:37 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

void	send_bit(char *txt, int pid_id)
{
	int		i;
	int		base;
	char	ch;

	i = -1;
	while (txt[++i])
	{
		base = 128;
		ch = txt[i];
		while (base > 0)
		{
			if (ch >= base)
			{
				kill(pid_id, SIGUSR1);
				ch -= base;
			}
			else
				kill(pid_id, SIGUSR2);
			base = base >> 1;
			usleep(250);
		}
	}
}

int	main(int argc, char **argv)
{
	if (ft_itsdigit(argv[1]) == 0)
		ft_putstr("(Error) Put only numbers on PID ID\n");
	else
	{ 
		if (argc == 3)
			send_bit(argv[2], ft_atoi(argv[1]));
		else
			ft_putstr("(Error) Try ./client <PID> <MSG>\n");
	}
	return (0);
}
