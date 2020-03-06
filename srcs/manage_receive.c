#include "ft_ping.h"

void	pck_configure_receive()
{
	ft_memset(&(g_stock.buf), 0, sizeof(g_stock.buf));
	g_stock.iov[0].iov_base = g_stock.buf;
	g_stock.iov[0].iov_len = sizeof(g_stock.buf);
	g_stock.msg.msg_name = g_stock.res->ai_addr;
	g_stock.msg.msg_namelen = g_stock.res->ai_addrlen;
	g_stock.msg.msg_iov = g_stock.iov;
	g_stock.msg.msg_iovlen = 1;
	g_stock.msg.msg_control = &(g_stock.buf_control);
	g_stock.msg.msg_controllen = sizeof(g_stock.buf_control);
	g_stock.msg.msg_flags = 0;
}