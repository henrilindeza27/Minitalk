#include "libminitalk.h"

void	ft_convert(int bin[])
{
	int		i;
	int		base;
	int		convert;
	char	c;

	base = 1;
	i = 7;
	convert = 0;
	while (i > 0)
	{
		convert = convert + (base * bin[i]);
		i--;
		base = base << 1;
	}
	c = convert;
	write(1, &c, 1);
}

void	getsignal(int i)
{
	int			binario[9];
	static int	j;

	if (i == SIGUSR1)
		binario[j] = 1;
	if (i == SIGUSR2)
		binario[j] = 0;
	j++;
	if (j > 7)
	{
		ft_convert(binario);
		j = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	int		i;

	i = 1;
	pid = getpid();
	signal(SIGUSR1, getsignal);
	signal(SIGUSR2, getsignal);
	ft_putnubr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}