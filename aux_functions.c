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

int ft_strlen(char *str)
{
	int i = -1;
	while(str[++i]);
	return i;
}