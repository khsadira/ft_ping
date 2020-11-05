#include "ft_ping.h"

int main(int ac, char **av)
{
	int 		i;

	env.flags.h = 0;
	env.flags.v = 0;
	env.flags.d = 0;
	env.count = 0; // TO FLAG -c
	env.interval = 1; // TO FLAG -i
	env.timeout = 1; // TO FLAG -W
	env.ttl = 116; // TO FLAG -m

	if ((i = fill_flag(ac, av, &(env.flags))) == -1 || !av[i]) {
		print_usage();
		return 1;
	}

	if (getuid() != 0) {
		fprintf(stderr, "ft_ping: Operation not permitted\n");
		return 1;
	}

	env.ping_loop = 1;
	env.hostname_dst = av[i];
	env.host_src = "0.0.0.0";
	env.host_dst = NULL;
	env.t_min = DBL_MAX;
	env.t_max = 0;
	env.t_aggregate = 0;
	env.t_aggregate_s = 0;	
	env.pid = getpid();
	env.res = NULL;



	return (ft_ping());
}