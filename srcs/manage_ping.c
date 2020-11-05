#include "ft_ping.h"

static t_bool	is_finish() {
	if ((env.seq == env.count && env.count != 0))
		return (FALSE);
	return (TRUE);
}

int 			ping_loop()
{
	int 		nb_send;
	t_timeval	tv_start, tv_end; //tv_out

	print_info();

	// tv_out.tv_sec = RECV_TIMEOUT;
	// tv_out.tv_usec = 0;

	// if (setsockopt(env.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
	// 	ft_error("Setting socket options to TIMEOUT failed!\n");
	// }

	int i = 0;

	if (env.flags.v == 1) {
		printf("V FLAGS = 1\n\n");
	}
	while (is_finish())
	{
		ft_bzero(&(env.pck), sizeof(env.pck));

		env.pck.hdr.type = ICMP_ECHO;
		env.pck.hdr.un.echo.id = env.pid;

		for (i = 0; i < sizeof(env.pck.msg) - 1; i++) {
			env.pck.msg[i] = i+'0';
		}

		env.pck.msg[i] = '\0';
		env.pck.hdr.un.echo.sequence = env.seq;
		env.pck.hdr.checksum = checksum(&env.pck, sizeof(env.pck));

		gettimeofday(&tv_start, NULL);

		if ((nb_send = sendto(env.sock_fd, &env.pck, sizeof(env.pck), 0, env.res->ai_addr, env.res->ai_addrlen)) < 0)
			ft_error("sendto: Packet sending failed.\n");

		env.pck_send++;
		// env.r_addr_len = sizeof(env.r_addr);
		alarm(env.timeout);
		while (manage_ping_receive(tv_start, tv_end))
			;
		my_sleep(1);
	}
	print_stats();
	free_env();
	return 0;
}