#include "ft_ping.h"

static t_bool	is_finish() {
	if ((env.seq == env.count && env.count != 0))
		return (FALSE);
	if (env.preload - 1 < env.pck_send)
		my_sleep(env.interval);
	return (TRUE);
}

int 			ping_loop()
{
	int 		nb_send;
	t_timeval	tv_start, tv_end;

	print_info();

	while (is_finish())
	{
		pck_send_configuration();
		gettimeofday(&tv_start, NULL);

		if ((nb_send = sendto(env.sock_fd, &env.pck, sizeof(env.pck), 0, env.res->ai_addr, env.res->ai_addrlen)) < 0)
			ft_error("sendto: Packet sending failed.\n");

		env.pck_send++;
		alarm(env.timeout);
		while (manage_ping_receive(tv_start, tv_end))
			;
	}
	print_stats();
	free_env();
	return 0;
}