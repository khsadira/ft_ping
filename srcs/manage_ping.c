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
	if ((g_stock.seq == g_stock.count && g_stock.count != 0) || !g_stock.ping_loop)
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

	// if (setsockopt(g_stock.sock_fd, SOL_SOCKET, IP_TTL, &g_stock.ttl, sizeof(g_stock.ttl)) != 0) {
	// 	fprintf(stderr, "Setting socket options to TTL failed!\n");
	// } else {
	// 	printf("Socket set to TTL...\n");
	// }

	// if (setsockopt(g_stock.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
	// 	perror("TIMEOUT SET");
	// }

	// printf("src_host: %s\ndst_name: %s\ndst_host: %s\n", g_stock.host_src, g_stock.hostname_dst, g_stock.host_dst);

	// struct hostent *hname;
	// struct sockaddr_in addr_ping,*addr;
	
	// hname = gethostbyname("www.google.fr");
    // bzero(&addr_ping, sizeof(addr_ping));
    // addr_ping.sin_family = hname->h_addrtype;
    // addr_ping.sin_port = 0;
    // addr_ping.sin_addr.s_addr = *(long*)hname->h_addr;

    // addr = &addr_ping;

	// int i;
	// int nb_recv;

	while (is_finish())
	{
		pck_send_configuration();
		gettimeofday(&tv_start, NULL);
		// printf("%ld\n", tv_start.tv_sec);
		// printf("%d|%d|%s|%d\n", g_stock.sock_fd, g_stock.res->ai_addr->sa_family, g_stock.res->ai_addr->sa_data, g_stock.res->ai_addrlen);

		// if ((nb_send = sendto(g_stock.sock_fd, &g_stock.buf, sizeof(g_stock.buf), 0, g_stock.res->ai_addr, sizeof(g_stock.res->ai_addr))) < 0)
		// {
		// 	perror("sendto");
		// 	fprintf(stderr, "ping_loop: sendto error: %d\n", nb_send);
		// 	return -1
		// } else {
        //     printf("SEND SUCCEEDED");
        // }

        // bzero(&g_stock.pck, sizeof(g_stock.pck));
        // g_stock.pck.hdr.type = ICMP_ECHO;
        // g_stock.pck.hdr.un.echo.id = g_stock.pid;
        // for ( i = 0; i < sizeof(g_stock.pck.msg)-1; i++ )
        //     g_stock.pck.msg[i] = i+'0';
        // g_stock.pck.msg[i] = 0;
        // g_stock.pck.hdr.un.echo.sequence = g_stock.seq;
        // g_stock.pck.hdr.checksum = checksum(&g_stock.pck, sizeof(g_stock.pck));

		printf("before sendto\n");
        if ((nb_send = sendto(g_stock.sock_fd, &g_stock.buf, sizeof(g_stock.buf), 0, g_stock.res->ai_addr, g_stock.res->ai_addrlen)) <= 0) {
            perror("sendto");
        }

		printf("after sendto\n");
		if (nb_send >= 0)
			g_stock.pck_send++;
		sleep(3);

		manage_ping_receive(tv_start, tv_end);

	}
	printf("\nc'est la fin: %d\n", g_stock.pck_send);
	return 0;
}