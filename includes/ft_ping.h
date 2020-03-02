#ifndef FT_PING_H
#define FT_PING_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <signal.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#include "../libft/includes/libft.h"

#define t_addrinfo		struct addrinfo
#define t_sockaddr_in	struct sockaddr_in
#define t_timeval		struct timeval
#define t_ip			struct ip
#define t_icmp			struct icmp

typedef struct	s_flag {
	int h;
	int v;
}				t_flag;

typedef struct	s_stock {

	t_addrinfo	hints;
	t_addrinfo	*res;

	pid_t 		pid;

	char		buf[76];
	char 		*hostname_dst;
	char 		*host_dst;
	char 		*host_src;

	t_ip		*ip;
	t_icmp		*icmp;

	t_flag		opts;

	int 		sock_fd;
	int 		ping_loop;
	int 		flags;
	int			count;
	int 		timeout;
	int 		interval;
	int 		ttl;
	double		min;

	int			pck_send;
	int 		pck_receve;
	int 		seq;
	int 		df_flag;
}				t_stock;

t_stock 	g_stock;

int		ft_ping();
int		fill_flag(int ac, char **av, t_flag *flag);
char	*get_ip(int ac, char **av);
void	print_usage();
int		ping_loop();

#endif