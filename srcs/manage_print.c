#include "ft_ping.h"

void	print_usage()
{
	printf("ping usage = ...\n");
}

void	print_resp(int nb_receive, double duration)
{
	char ip[INET_ADDRSTRLEN];

	inet_ntop(g_stock.res->ai_family, &(g_stock.ip->ip_src.s_addr), ip, sizeof(ip));
	printf("%lu bytes from %s: icmp_seq=%d ttl=%d time=%.3lf ms\n", nb_receive - sizeof(*(g_stock.ip)), ip, g_stock.seq, g_stock.ip->ip_ttl, duration);
}

void display_info()
{
	printf("PING %s (%s): %lu data bytes\n", g_stock.hostname_dst, g_stock.host_dst, sizeof(g_stock.buf) - sizeof(*(g_stock.icmp)));
}