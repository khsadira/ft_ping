#include "ft_ping.h"

static t_bool	is_finish() {
	if ((env.seq == env.count && env.count != 0))
		return (FALSE);
	return (TRUE);
}

int 			ping_loop()
{
	int 		nb_send;
	t_timeval	tv_start, tv_end, tv_out;

	print_info();

	tv_out.tv_sec = RECV_TIMEOUT;
	tv_out.tv_usec = 0;

	if (setsockopt(env.sock_fd, 0, IP_TTL, &env.ttl, sizeof(env.ttl)) != 0) {
		ft_error("Setting socket options to TTL failed!\n");
	}

	if (setsockopt(env.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
		ft_error("Setting socket options to TIMEOUT failed!\n");
	}

	int i = 0;

	while (is_finish())
	{
		env.flag = 1;
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

		if ((nb_send = sendto(env.sock_fd, &env.pck, sizeof(env.pck), 0, env.res->ai_addr, env.res->ai_addrlen)) < 0) {
			fprintf(stderr, "sendto: Packet sending failed.\n");
			my_sleep(1);
			continue;
		}

		env.pck_send++;
		env.r_addr_len = sizeof(env.r_addr);
		alarm(env.timeout);
		while (!manage_ping_receive(tv_start, tv_end))
			;
	}
	print_stats();
	free_env();
	return 0;
}