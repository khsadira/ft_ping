#include "ft_ping.h"

static void	header_configuration()
{
	g_stock.ip = (t_ip *)g_stock.buf;
	g_stock.icmp = (t_icmp *)(&(g_stock.ip) + 1);
}

static void	pck_send_configuration()
{
	ft_memset(g_stock.buf, 0, sizeof(g_stock.buf));
	g_stock.ip
}

int 	ping_loop()
{
	int 	nb_send;

	header_configuration();
	g_stock.ping_loop = 1;

	while (g_stock.ping_loop)
	{
		pck_send_configuration();
	}
	return 0;
}