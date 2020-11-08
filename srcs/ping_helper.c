#include "ft_ping.h"

unsigned short	checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
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

char			*get_dns() {
	t_addrinfo		hints;
	t_addrinfo		*res;
	t_sockaddr_in	*sa_in;
	char 			*ip_share = NULL;

	ft_memset(&hints, 0, sizeof(t_addrinfo));
	hints.ai_family = AF_INET;
	if (!(ip_share = (char *)malloc(sizeof(char) * INET_ADDRSTRLEN)))
		ft_error("malloc: Error to allowed memory.\n");
	if (getaddrinfo(env.hostname_dst, NULL, &hints, &res) != 0) {
		fprintf(stderr, "ping: cannot resolve %s: unknown host.\n", env.hostname_dst);
		free_env();
		exit(EXIT_FAILURE);
	}
	sa_in = (t_sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip_share, INET_ADDRSTRLEN);

	return (ip_share);
}

int				open_socket() {
	int hincl = 1;

	ft_memset(&(env.hints), 0, sizeof(env.hints));
	env.hints.ai_family = AF_INET;
	env.hints.ai_socktype = SOCK_RAW;
	env.hints.ai_protocol = IPPROTO_ICMP;

	if (getaddrinfo(env.host_dst, NULL, &(env.hints), &(env.res)) != 0) {
		fprintf(stderr, "ping: cannot resolve %s: unknown host.\n", env.host_dst);
		free_env();
		exit(EXIT_FAILURE);
	}

	if ((env.sock_fd = socket(env.res->ai_family, env.res->ai_socktype, env.res->ai_protocol)) < 0)
		ft_error("Error socket opening\n");
	return (env.sock_fd);
}

void			header_configuration() {
	env.ip = (t_ip *)(env.pck.msg);
	env.icmp = (t_icmp *)(env.ip + 1);
}

void			add_duration_stats(double duration) {
	if (duration > env.t_max)
		env.t_max = duration;
	if (duration < env.t_min)
		env.t_min = duration;
	env.t_aggregate += duration;
	env.t_aggregate_s += duration * duration;
}

void			my_sleep(int time)
{
	int			interval = 0;
	t_timeval	tv_start, tv_end;

	gettimeofday(&tv_start, 0);
	while (interval < time)
	{
		gettimeofday(&tv_end, 0);
		interval = tv_end.tv_sec - tv_start.tv_sec;
	}
}