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

static void	header_configuration()
{
	g_stock.ip = (t_ip *)g_stock.buf;
	g_stock.icmp = (t_icmp *)(g_stock.ip + 1);
}

int 	ping_loop()
{
	int 		nb_send;
	t_timeval	tv_start;
	t_timeval	tv_end;
	t_timeval	tv_out;

	tv_out.tv_sec = 60000;
	tv_out.tv_usec = 0;

	if (setsockopt(g_stock.sock_fd, SOL_IP, IP_TTL, &g_stock.ttl, sizeof(g_stock.ttl)) != 0) {
		fprintf(stderr, "Setting socket options to TTL failed!\n");
	} else {
		printf("Socket set to TTL...\n");
	}

	if (setsockopt(g_stock.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
		perror("TIMEOUT SET");
	}

	header_configuration();

	g_stock.pck_send = 0;
	g_stock.pck_receive = 0;
	g_stock.seq = 0;

	printf("src_host: %s\ndst_name: %s\ndst_host: %s\n", g_stock.host_src, g_stock.hostname_dst, g_stock.host_dst);

	while (g_stock.ping_loop)
	{

		printf("On send\n");
		pck_send_configuration();
		printf("src: %d\ndst: %d\n", g_stock.ip->ip_src.s_addr, g_stock.ip->ip_dst.s_addr);
		
		gettimeofday(&tv_start, NULL);
		printf("%ld\n", tv_start.tv_sec);
		printf("%d|%d|%s|%d\n", g_stock.sock_fd, g_stock.res->ai_addr->sa_family, g_stock.res->ai_addr->sa_data, g_stock.res->ai_addrlen);

		if ((nb_send = sendto(g_stock.sock_fd, g_stock.buf, sizeof(g_stock.buf), 0, g_stock.res->ai_addr, g_stock.res->ai_addrlen)) < 0)
		{
			perror("sendto");
			fprintf(stderr, "ping_loop: sendto error: %d\n", nb_send);
			return 1;
		}

		if (nb_send >= 0)
			g_stock.pck_send++;
		sleep(3);
	}
	printf("\nc'est la fin: %d\n", g_stock.count);
	return 0;
}