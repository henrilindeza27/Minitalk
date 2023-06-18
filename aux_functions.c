/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:51:58 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/07 11:51:58 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnubr(long int num)
{
	if (num < 0)
		num *= -1;
	if (num > 9)
	{
		ft_putnubr(num / 10);
		ft_putnubr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

int	ft_atoi(char *num)
{
	int i;
	int res;

	i = 0;
	res = 0;

	while (num[i] >= '0' && num[i] <= '9')
		res = res * 10 + num[i++] - '0';
	return (res);
}

int ft_itsdigit(char *num)
{
	int i;
	i = 0;
	while(num[i])
	{
		if(num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return 0;
	}
	return 1;
}