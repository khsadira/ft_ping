#include "ft_ping.h"

static void	pck_receive_configuration()
{
	ft_memset(&(env.buf), 0, sizeof(env.buf));
	env.iov[0].iov_base = env.buf;
	env.iov[0].iov_len = sizeof(env.buf);
	env.msg.msg_name = env.res->ai_addr;
	env.msg.msg_namelen = env.res->ai_addrlen;
	env.msg.msg_iov = env.iov;
	env.msg.msg_iovlen = 1;
	env.msg.msg_control = &(env.buf_control);
	env.msg.msg_controllen = sizeof(env.buf_control);
	env.msg.msg_flags = 0;
}

static t_bool	check_timeout(int nb_recv)
{
	if (nb_recv == -1)
	{
		printf("Request timeout for icmp_seq %d\n", env.seq);
		alarm(0);
		env.timeout_flag = FALSE;
		env.seq++;
		return (FALSE);
	}
	return (TRUE);
}

t_bool		manage_ping_receive(struct timeval tv_start, struct timeval tv_end)
{
	double	duration = 0;
	int		nb_receive = 0;

	pck_receive_configuration();
	nb_receive = recvmsg(env.sock_fd, &(env.msg), MSG_WAITALL);
	gettimeofday(&tv_end, NULL);
	my_sleep(1);
	if (!check_timeout(nb_receive)) {
		return (TRUE);
	}
	else if (env.icmp->icmp_hun.ih_idseq.icd_id == env.pid)
	{
		env.pck_receive++;
		duration = (((double)tv_end.tv_sec * 1000000.0 + tv_end.tv_usec) - ((double)tv_start.tv_sec * 1000000.0 + tv_start.tv_usec)) / 1000;
		add_duration_stats(duration);
		print_resp(nb_receive, duration);
		alarm(0);
		env.timeout_flag = FALSE;
		env.seq++;
		return (TRUE);
	}
	return (FALSE);
}