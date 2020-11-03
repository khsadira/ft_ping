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

unsigned short checksum(void *b, int len)
{
    unsigned short *buf;
    unsigned int sum;
    unsigned short result;

	buf = b;
	sum = 0;
    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;
    if ( len == 1 )
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

static t_bool	is_finish() {
	// printf("seq = %d || count = %d || ping = %d\n", env.seq, env.count, env.ping_loop);
	if ((env.seq == env.count && env.count != 0) || !env.ping_loop)
		return (FALSE);
	return (TRUE);
}

int 			ping_loop()
{
	int 		nb_send;
	t_timeval	tv_start;
	t_timeval	tv_end;
	// t_timeval	tv_out;

	display_info();

	// tv_out.tv_sec = 60000;
	// tv_out.tv_usec = 0;

	// if (setsockopt(env.sock_fd, SOL_SOCKET, IP_TTL, &env.ttl, sizeof(env.ttl)) != 0) {
	// 	fprintf(stderr, "Setting socket options to TTL failed!\n");
	// } else {
	// 	printf("Socket set to TTL...\n");
	// }

	// if (setsockopt(env.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
	// 	perror("TIMEOUT SET");
	// }

	// printf("src_host: %s\ndst_name: %s\ndst_host: %s\n", env.host_src, env.hostname_dst, env.host_dst);

	int i;

	while (is_finish())
	{
		pck_send_configuration();
		gettimeofday(&tv_start, NULL);
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

        if ((nb_send = sendto(env.sock_fd, &env.buf, sizeof(env.buf), 0, env.res->ai_addr, env.res->ai_addrlen)) < 0) {
            perror("sendto");
        }

		if (nb_send >= 0)
			env.pck_send++;
		sleep(3);

		manage_ping_receive(tv_start, tv_end);

	}
	printf("\nc'est la fin: %d\n", env.pck_send);
	return 0;
}