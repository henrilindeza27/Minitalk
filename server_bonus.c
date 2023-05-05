/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:28:05 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/05 11:11:27 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"


void	handler_sig(int signal, siginfo_t *info, void *context)
{
	static unsigned int	c;
	static int			bit;

	(void)context;
	c = (signal == SIGUSR1) << bit | c;
	bit++;
	if (bit == 8)
	{
		
		if(!c)
			kill(info->si_pid, SIGUSR2);
		else
			ft_putchar(c);
	
		bit = 0;
		c = 0;
	}
}


int	main(void)
{
    struct sigaction	act;

	ft_putstr("PID ID -> ");
	ft_putnubr(getpid());
	ft_putchar('\n');
	act.sa_sigaction = handler_sig;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
}
