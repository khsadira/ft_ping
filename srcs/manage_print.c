#include "ft_ping.h"

void	print_usage()
{
	printf("ping usage = ...\n");
}

void	print_resp(int nb_receive, double duration)
{
	char ip[INET_ADDRSTRLEN];

	inet_ntop(env.res->ai_family, &(env.ip->ip_src.s_addr), ip, sizeof(ip));
	printf("%ld bytes from %s: icmp_seq=%d ttl=%d time=%.3lf ms\n", sizeof(env.msg) + sizeof(env.ip), ip, env.seq, env.ttl, duration);
}

void	print_info()
{
	printf("PING %s (%s): %lu data bytes\n", env.hostname_dst, env.host_dst, sizeof(env.pck.msg));
}

void	print_stats()
{
	double	percentage_lost;
	double	avg;
	double	variant;

	percentage_lost = 0;
	avg = 0;
	variant = 0;
	if (env.pck_send != 0)
		percentage_lost = 100 - ((env.pck_receive * 100) / env.pck_send);
	if (env.ping_loop == 0)
		printf("\n");
	printf("--- %s ping statistics ---\n", env.hostname_dst);
	printf("%u packets transmitted, %u packets received, %.2f%% packet loss\n", env.pck_send, env.pck_receive, percentage_lost);
	if (env.pck_send != 0)
		avg = env.t_aggregate / env.pck_send;
	int smean = env.t_aggregate_s / env.pck_receive;
	int mean = env.t_aggregate / env.pck_receive;
	variant = (smean) - (mean * mean);
	if (env.pck_receive > 0)
		printf("round-trip min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f ms\n", env.t_min, avg, env.t_max, sqrt(variant));
}

void	print_timeout()
{
	printf("Request timeout for icmp_seq %d\n", env.seq);
}

void	ft_error(char *str)
{
	fprintf(stderr, "%s\n", str);
	free_env();
	exit(EXIT_FAILURE);
}