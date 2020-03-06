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

	header_configuration();

	g_stock.pck_send = 0;
	g_stock.pck_receive = 0;
	g_stock.seq = 0;

	while (g_stock.ping_loop)
	{

		printf("On send\n");
		pck_send_configuration();
		gettimeofday(&tv_start, NULL);

		if ((nb_send = sendto(g_stock.sock_fd, g_stock.buf, sizeof(g_stock.buf), 0, g_stock.res->ai_addr, g_stock.res->ai_addrlen)) < 0)
		{
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
