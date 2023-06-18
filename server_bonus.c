/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:28:05 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/07 11:53:03 by hlindeza         ###   ########.fr       */
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
    struct sigaction	sig;

	ft_putstr("PID ID -> ");
	ft_putnubr(getpid());
	ft_putchar('\n');
	sig.sa_sigaction = handler_sig;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}
