/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:28:05 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/07 11:51:47 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

static int	g_bin[8] = {0};

void	convert_to_txt(int *bin)
{
	int		i;
	int		base;
	int		convert;
	char	letra;

	base = 1;
	i = 7;
	convert = 0;
	while (i > 0)
	{
		convert += (base * bin[i--]);
		base = base << 1;
	}
	letra = (char)convert;
	ft_putchar(letra);
}

void	save_bin(int bit)
{
	static int	i;

	if (bit == SIGUSR1)
		g_bin[i++] = 1;
	else if (bit == SIGUSR2)
		g_bin[i++] = 0;
	if (i == 8)
	{
		convert_to_txt(g_bin);
		i = 0;
	}
}

int	main(void)
{
	ft_putstr("PID ID -> ");
	ft_putnubr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, save_bin);
	signal(SIGUSR2, save_bin);
	while (1)
		pause();
}
