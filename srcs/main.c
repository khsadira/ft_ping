#include "ft_ping.h"

int main(int ac, char **av)
{
	t_flag	flag;
	int 	i;

	if ((i = fill_flag(ac, av, &flag)) == -1 || !av[i])
	{
		print_usage();
		return 1;
	}

	return ft_ping(av[i], flag);
}