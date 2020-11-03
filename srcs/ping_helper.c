#include "ft_ping.h"

unsigned short	icmp_checksum(unsigned short *data, int len)
{
	unsigned long checksum;

	checksum = 0;
	while (len > 1)
	{
		checksum = checksum + *data++;
		len = len - sizeof(unsigned short);
	}
	if (len)
		checksum = checksum + *(unsigned char*)data;
	checksum = (checksum >> 16) + (checksum & 0xffff);
	checksum = checksum + (checksum >> 16);
	return (unsigned short)(~checksum);
} 

unsigned short checksum(void *b, int len)
{
    unsigned short *buf;
    unsigned int sum;
    unsigned short result;

	buf = b;
	sum = 0;
    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;
    if ( len == 1 )
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

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

	if (getaddrinfo(env.hostname_dst, NULL, &hints, &res) < 0)
	{
		fprintf(stderr, "getaddrinfo: Unknown host\n");
		return NULL;
	}

	sa_in = (t_sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip_share, INET_ADDRSTRLEN);

	return (ip_share);
}

int		open_socket()
{
	int hincl;

	hincl = 1;
	ft_memset(&(env.hints), 0, sizeof(env.hints));
	env.hints.ai_family = AF_INET;
	env.hints.ai_socktype = SOCK_RAW;
	env.hints.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(env.host_dst, NULL, &(env.hints), &(env.res)) < 0)
	{
		printf("ping: unknown host\n");
		exit(EXIT_FAILURE);
	}
	if ((env.sock_fd = socket(env.res->ai_family, env.res->ai_socktype, env.res->ai_protocol)) < 0)
	{
		printf("Error socket opening\n");
		exit(EXIT_FAILURE);
	}
	// if (setsockopt(env.sock_fd, IPPROTO_IP, IP_HDRINCL, &hincl, sizeof(hincl)) < 0)
	// {
	// 	printf("Error setsocket\n");
	// 	exit(EXIT_FAILURE);
	// }
	return (env.sock_fd);
}

void	header_configuration()
{
	env.ip = (t_ip *)(env.buf);
	env.icmp = (t_icmp *)(env.ip + 1);
}