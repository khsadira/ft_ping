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
	g_stock.icmp = (t_icmp *)(&(g_stock.ip) + 1);
}


int 	ping_loop()
{
	int		flag;
	int 	nb_send;

	header_configuration();
	g_stock.ping_loop = 1;
	g_stock.count = 0;

	while (g_stock.ping_loop)
	{
		flag = 1;
		printf("On send\n");
		pck_send_configuration();
		printf("on recoit\n");
		g_stock.count++;
		sleep(3);
	}
	printf("\nc'est la fin: %d\n", g_stock.count);
	return 0;
}