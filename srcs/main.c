#include "ft_ping.h"

int main(int ac, char **av)
{
	int 		i;

	if ((i = fill_flag(ac, av, &(g_stock.opts))) == -1 || !av[i])
	{
		print_usage();
		return 1;
	}

	if (getuid() != 0)
	{
		fprintf(stderr, "ft_ping: Operation not permitted\n");
		return 1;
	}

	g_stock.ping_loop = 1;
	g_stock.flags = 0;
	g_stock.count = 0;
	g_stock.interval = 1;
	g_stock.timeout = 1;
	g_stock.ttl = 64;
	g_stock.hostname_dst = av[i];
	g_stock.host_src = "0.0.0.0";
	g_stock.min = DBL_MAX;
	g_stock.pid = getpid();
	// g_stock.ip = malloc(sizeof(t_ip) * 1);

	return (ft_ping());
}