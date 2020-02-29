#include "ft_ping.h"

int ft_ping(int ac, char **av)
{
	t_flag	flag;
	char 	*ip;

	flag = fill_flag(ac, av);
	printf("%d | %d\n", flag.h, flag.v);
	return 0;
}