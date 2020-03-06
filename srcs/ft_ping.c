#include "ft_ping.h"


static char *get_dns(t_sockaddr_in *sa_in)
{
	t_addrinfo		hints;
	t_addrinfo		*res;
	char 			*ip_share;

	memset(&hints, 0, sizeof(t_addrinfo));
	hints.ai_family = AF_INET;

	if (!(ip_share = malloc(INET_ADDRSTRLEN)))
	{
		fprintf(stderr, "malloc: ...\n");
		return NULL;
	}

	if (getaddrinfo(g_stock.hostname_dst, NULL, &hints, &res) != 0 || !res)
	{
		fprintf(stderr, "getaddrinfo: ...\n");
		return NULL;
	}

	sa_in = (t_sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip_share, INET_ADDRSTRLEN);

	return (ip_share);
}

static int	open_socket()
{
	int hincl;

	hincl = 1;

	ft_memset(&(g_stock.hints), 0, sizeof(g_stock.hints));
	g_stock.hints.ai_family = AF_INET;
	g_stock.hints.ai_socktype = SOCK_RAW;
	g_stock.hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(g_stock.host_dst, NULL, &(g_stock.hints), &(g_stock.res)) < 0)
	{
		fprintf(stderr, "getaddrinfo: ...");
		return -1;
	}

	printf("%d|%d|%d\n", g_stock.res->ai_family, g_stock.res->ai_socktype, g_stock.res->ai_protocol);
	if ((g_stock.sock_fd = socket(g_stock.res->ai_family, g_stock.res->ai_socktype, g_stock.res->ai_protocol)) < 0)
	{
		fprintf(stderr, "socket: Could not get fd: %d\n", g_stock.sock_fd);
		return -1;
	}

	if (setsockopt(g_stock.sock_fd, IPPROTO_IP, IP_HDRINCL, &hincl, sizeof(hincl)) < 0)
	{
		fprintf(stderr, "setsockopt: ...");
		return -1;
	}

	return (0);
}


static void intHandler()
{
	g_stock.ping_loop = 0;
}

int ft_ping()
{
	t_sockaddr_in	sockaddr_in;

	g_stock.host_src = "0.0.0.0";
	if (!(g_stock.host_dst = get_dns(&sockaddr_in)))
	{
		fprintf(stderr, "DNS Lookup failed: Could not resolve hostname\n");
		return 1;
	}

	if (open_socket() == -1)
		return 1;
	signal(SIGINT, intHandler);

	return ping_loop();
}