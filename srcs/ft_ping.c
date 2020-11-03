#include "ft_ping.h"
#include <errno.h>

char *get_dns()
{
	t_addrinfo		hints;
	t_addrinfo		*res;
	t_sockaddr_in	*sa_in;
	char 			*ip_share;

	ft_memset(&hints, 0, sizeof(t_addrinfo));
	hints.ai_family = AF_INET;

	if (!(ip_share = malloc(INET_ADDRSTRLEN)))
	{
		fprintf(stderr, "malloc: Error to allowed memory.\n");
		return NULL;
	}

	if (getaddrinfo(g_stock.hostname_dst, NULL, &hints, &res) < 0)
	{
		fprintf(stderr, "getaddrinfo: Unknown host\n");
		return NULL;
	}

	sa_in = (t_sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip_share, INET_ADDRSTRLEN);

	return (ip_share);
}

static void intHandler()
{
	g_stock.ping_loop = 0;
}

int ft_ping()
{
	if (!(g_stock.host_dst = get_dns()))
	{
		fprintf(stderr, "DNS Lookup failed: Could not resolve hostname\n");
		return 1;
	}
	if (open_socket() == -1)
		return 1;
	header_configuration();
	signal(SIGINT, intHandler);
	return ping_loop();
}