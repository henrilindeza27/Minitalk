#include "libminitalk.h"


void	send_bit(char *s, int pidserv)
{
	int		i;
	int		b;
	char	c;

	i = 0;
	while (s[i])
	{
		b = 128;
		c = s[i];
		while (b > 0)
		{
			if (c >= b)
			{
				kill(pidserv, SIGUSR1);
				c -= b;
			}
			else
				kill(pidserv, SIGUSR2);
			b = b >> 1;
			usleep(1000);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_bit(argv[2], ft_atoi(argv[1]));
	
}