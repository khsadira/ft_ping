#include "ft_ping.h"

void	print_usage()
{
	printf("ping usage = ...\n");
}

void	print_resp(int nb_receive, double duration)
{
	char ip[INET_ADDRSTRLEN];

	inet_ntop(env.res->ai_family, &(env.ip->ip_src.s_addr), ip, sizeof(ip));
	printf("%lu bytes from %s: icmp_seq=%d ttl=%d time=%.3lf ms\n", nb_receive - sizeof(env.ip), ip, env.seq, env.ip->ip_ttl, duration);
}

void display_info()
{
	printf("PING %s (%s): %lu data bytes\n", env.hostname_dst, env.host_dst, sizeof(env.buf) - sizeof(*env.icmp));
}