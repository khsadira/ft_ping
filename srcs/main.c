#include "ft_ping.h"

int main(int ac, char **av)
{
	int 	i;

	if ((i = fill_flag(ac, av, &(g_stock.opts))) == -1 || !av[i])
	{
		print_usage();
		return 1;
	}

	if (getuid() != 0)
	{
		fprintf(stderr, "ft_ping: Operation not permitted\n");
	//	return 1;
	}
	g_stock.pid = getpid();
	g_stock.hostname_dst = av[i];
	g_stock.ttl = 64;
	return ft_ping();
}