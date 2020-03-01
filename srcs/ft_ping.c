#include "ft_ping.h"

int pingloop = 1;

static char *get_dns(char *hostname, t_sockaddr_in *sa_in)
{
	t_addrinfo	hints, *res;
	char 			*ip_share;


	memset(&hints, 0, sizeof(t_addrinfo));
	hints.ai_family = AF_INET;
//	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_flags = AI_PASSIVE;
//	hints.ai_protocol = 0;
//	hints.ai_canonname = NULL;
//	hints.ai_next = NULL;

	if ((ip_share = malloc(INET_ADDRSTRLEN)) < 0)
	{
		fprintf(stderr, "malloc: ...\n");
		return NULL;
	}

	if (getaddrinfo(hostname, NULL, &hints, &(res)) < 0 || !res)
	{
		fprintf(stderr, "getaddrinfo: ...\n");
		return NULL;
	}

	sa_in = (t_sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip_share, INET_ADDRSTRLEN);

	return (ip_share);
}


static void	send_ping(int sock_fd, char *ip_addr, char *hostname, t_sockaddr_in sockaddr_in)
{

	int ttl_val=64;
	int flag;
	struct timeval tv_out;

	printf("%d\n",setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &ttl_val, sizeof(ttl_val)));
//	if (!setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &ttl_val, sizeof(ttl_val)))
//	{
//		fprintf(stderr, "setsockopt: Setting socket options to TTL failed\n");
//		return;
//	}

	printf("%d\n", setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out)));
	while (pingloop)
	{
		flag = 1;
	}
}

static void intHandler()
{
	pingloop=0;
}

int ft_ping(char *hostname, t_flag flag)
{
	char 			*ip_addr;
	int 			sock_fd;
	t_sockaddr_in	sockaddr_in;

	if (!(ip_addr = get_dns(hostname, &sockaddr_in)))
	{
		fprintf(stderr, "DNS Lookup failed: Could not resolve hostname\n");
		return 1;
	}
	printf("%s\n", ip_addr);

	if (!(sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)))
	{
		fprintf(stderr, "socket: File descriptor corrupted\n");
		return 1;
	}

	signal(SIGINT, intHandler);
	send_ping(sock_fd, ip_addr, hostname, sockaddr_in);
	return 0;
}