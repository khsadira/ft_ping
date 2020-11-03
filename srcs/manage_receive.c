#include "ft_ping.h"

static void	pck_receive_configuration()
{
	ft_memset(&(g_stock.buf_receive), 0, sizeof(g_stock.buf_receive));
	g_stock.iov[0].iov_base = g_stock.buf_receive;
	g_stock.iov[0].iov_len = sizeof(g_stock.buf_receive);
	g_stock.msg.msg_name = g_stock.res->ai_addr;
	g_stock.msg.msg_namelen = g_stock.res->ai_addrlen;
	g_stock.msg.msg_iov = g_stock.iov;
	g_stock.msg.msg_iovlen = 1;
	g_stock.msg.msg_control = &(g_stock.buf_control);
	g_stock.msg.msg_controllen = sizeof(g_stock.buf_control);
	g_stock.msg.msg_flags = 0;
}

void		manage_ping_receive(struct timeval tv_start, struct timeval tv_end)
{
	double	duration;
	int		nb_receive;

	duration = 0;
	nb_receive = 0;
	pck_receive_configuration();	
	nb_receive = recvmsg(g_stock.sock_fd, &(g_stock.msg), MSG_DONTWAIT);
	gettimeofday(&tv_end, NULL);
	if (g_stock.icmp->icmp_hun.ih_idseq.icd_id == g_stock.pid)
	{
		duration = (((double)tv_end.tv_sec * 1000000.0 + tv_end.tv_usec) - ((double)tv_start.tv_sec * 1000000.0 + tv_start.tv_usec)) / 1000;
		print_resp(nb_receive, duration);
		alarm(0);
		g_stock.timeout = FALSE;
		g_stock.seq++;
	}
}