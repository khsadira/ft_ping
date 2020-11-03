#include "ft_ping.h"

int main(int ac, char **av)
{
	int 		i;

	if ((i = fill_flag(ac, av, &(env.opts))) == -1 || !av[i]) {
		print_usage();
		return 1;
	}

	if (getuid() != 0) {
		fprintf(stderr, "ft_ping: Operation not permitted\n");
		return 1;
	}

	env.ping_loop = 1;
	env.flag = 0;
	env.count = 0;
	env.interval = 1;
	env.timeout = 1;
	env.ttl = 116;
	env.hostname_dst = av[i];
	env.host_src = "0.0.0.0";
	env.min = DBL_MAX;	
	env.pid = getpid();
	// env.ip = malloc(sizeof(t_ip) * 1);

	return (ft_ping());
}