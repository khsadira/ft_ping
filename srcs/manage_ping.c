#include "ft_ping.h"

static t_bool	is_finish() {
	// printf("seq = %d || count = %d || ping = %d\n", env.seq, env.count, env.ping_loop);
	if ((env.seq == env.count && env.count != 0) || !env.ping_loop)
		return (FALSE);
	return (TRUE);
}

int 			ping_loop()
{
	int 		nb_send;
	t_timespec	time_start, time_end, tfs, tfe;
	t_timeval	tv_start, tv_end, tv_out;

	display_info();

	tv_out.tv_sec = RECV_TIMEOUT;
	tv_out.tv_usec = 0;

	clock_gettime(CLOCK_MONOTONIC, &tfs);

	if (setsockopt(env.sock_fd, 0, IP_TTL, &env.ttl, sizeof(env.ttl)) != 0) {
		fprintf(stderr, "Setting socket options to TTL failed!\n");
	} else {
		printf("Socket set to TTL...\n");
	}

	if (setsockopt(env.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
		fprintf(stderr, "Setting socket options to TIMEOUT failed!\n");
	} else {
		printf("Socket set to TIMEOUT...\n");
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
		env.pck.hdr.un.echo.sequence = env.count++;
		env.pck.hdr.checksum = checksum(&env.pck, sizeof(env.pck));

		usleep(PING_SLEEP_RATE);

		clock_gettime(CLOCK_MONOTONIC, &time_start);
		if (sendto(env.sock_fd, &env.pck, sizeof(env.pck), 0, env.res->ai_addr, env.res->ai_addrlen) < 0) {
			perror("sendto");
			fprintf(stderr, "sendto: Packet sending failed\n");
			env.flag = 0;
		} else {
			env.pck_send++;
		}

		env.r_addr_len = sizeof(env.r_addr);

		manage_ping_receive(tv_start, tv_end);
		// if (recvfrom(env.sock_fd, &env.pck, sizeof(env.pck), 0, (t_sockaddr *)&env.r_addr, sizeof(env.r_addr)) <= 0 && env.count > 0) {
		// 	perror("recvmsg");
		// 	fprintf(stderr, "recvmsg: Packet receive failed\n");
		// } else {
		// 	env.pck_receive++;
		// }











		// ///////////////////////////
		// pck_send_configuration();
		// gettimeofday(&tv_start, NULL);
		// printf("%ld\n", tv_start.tv_sec);
		// printf("%d|%d|%s|%d\n", env.sock_fd, env.res->ai_addr->sa_family, env.res->ai_addr->sa_data, env.res->ai_addrlen);

		// if ((nb_send = sendto(env.sock_fd, &env.buf, sizeof(env.buf), 0, env.res->ai_addr, sizeof(env.res->ai_addr))) < 0)
		// {
		// 	perror("sendto");
		// 	fprintf(stderr, "ping_loop: sendto error: %d\n", nb_send);
		// 	return -1;
		// } else {
        //     printf("SEND SUCCEEDED");
        // }

        // bzero(&env.pck, sizeof(env.pck));
        // env.pck.hdr.type = ICMP_ECHO;
        // env.pck.hdr.un.echo.id = env.pid;
	    // for ( i = 0; i < sizeof(env.pck.msg)-1; i++ )
        //     env.pck.msg[i] = i+'0';
        // env.pck.msg[i] = 0;
        // env.pck.hdr.un.echo.sequence = env.seq;
        // env.pck.hdr.checksum = checksum(&env.pck, sizeof(env.pck));

        // if ((nb_send = sendto(env.sock_fd, &env.buf, sizeof(env.buf), 0, env.res->ai_addr, env.res->ai_addrlen)) < 0) {
        //     perror("sendto");
        // }

		// if (nb_send >= 0)
		// 	env.pck_send++;
		// sleep(3);

		// manage_ping_receive(tv_start, tv_end);

	}
	printf("\nc'est la fin: %d | %d\n", env.pck_send, env.pck_receive);
	return 0;
}