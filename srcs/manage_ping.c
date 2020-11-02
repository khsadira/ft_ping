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

static void	header_configuration()
{
	g_stock.ip = (t_ip *)g_stock.buf;
	g_stock.icmp = (t_icmp *)(g_stock.ip + 1);
}

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;
    if ( len == 1 )
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int 	ping_loop()
{
	int 		nb_send;
	t_timeval	tv_start;
	t_timeval	tv_end;
	t_timeval	tv_out;

	tv_out.tv_sec = 60000;
	tv_out.tv_usec = 0;

	if (setsockopt(g_stock.sock_fd, SOL_IP, IP_TTL, &g_stock.ttl, sizeof(g_stock.ttl)) != 0) {
		fprintf(stderr, "Setting socket options to TTL failed!\n");
	} else {
		printf("Socket set to TTL...\n");
	}

	if (setsockopt(g_stock.sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof(tv_out)) != 0) {
		perror("TIMEOUT SET");
	}

	header_configuration();

	g_stock.pck_send = 0;
	g_stock.pck_receive = 0;
	g_stock.seq = 0;

	printf("src_host: %s\ndst_name: %s\ndst_host: %s\n", g_stock.host_src, g_stock.hostname_dst, g_stock.host_dst);

	struct hostent *hname;
	struct sockaddr_in addr_ping,*addr;
	
	hname = gethostbyname("www.google.fr");
    bzero(&addr_ping, sizeof(addr_ping));
    addr_ping.sin_family = hname->h_addrtype;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = *(long*)hname->h_addr;

    addr = &addr_ping;

	int i;
	int nb_recv;

	while (g_stock.ping_loop)
	{
		pck_send_configuration();
		// printf("src: %d\ndst: %d\n", g_stock.ip->ip_src.s_addr, g_stock.ip->ip_dst.s_addr);
		
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

        bzero(&g_stock.pck, sizeof(g_stock.pck));
        g_stock.pck.hdr.type = ICMP_ECHO;
        g_stock.pck.hdr.un.echo.id = g_stock.pid;
        for ( i = 0; i < sizeof(g_stock.pck.msg)-1; i++ )
            g_stock.pck.msg[i] = i+'0';
        g_stock.pck.msg[i] = 0;
        g_stock.pck.hdr.un.echo.sequence = g_stock.count++;
        g_stock.pck.hdr.checksum = icmp_checksum(&g_stock.pck, sizeof(g_stock.pck));
        if ((nb_send = sendto(g_stock.sock_fd, &g_stock.pck, sizeof(g_stock.pck), 0, g_stock.res->ai_addr, g_stock.res->ai_addrlen)) <= 0) {
            perror("sendto");
        } else {
            printf("SEND SUCCEEDED");
			printf("nb: %d\n", nb_send);
        }

		if (nb_send >= 0)
			g_stock.pck_send++;
		sleep(3);

        if ((nb_recv = recvmsg(g_stock.sock_fd, &g_stock.msg, MSG_DONTWAIT)) >= 0) {
            printf("PCK RCV\n");
        } else {
			perror("recv");
			printf("ERROR: %d\n", nb_recv);
		}
	}
	printf("\nc'est la fin: %d\n", g_stock.pck_send);
	return 0;
}