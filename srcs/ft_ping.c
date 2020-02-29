#include "ft_ping.h"

int ft_ping(int ac, char **av)
{
	t_flag	flag;
	char 	*ip;
	int 	i;

	if ((i = fill_flag(ac, av, &flag)) == -1)
		return 1;

	printf("arg = %s\nh = %d\nv = %d\n", av[i], flag.h, flag.v);
	return 0;
}