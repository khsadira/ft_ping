#ifndef FT_PING_H
#define FT_PING_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>

#include <signal.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>

# include "../libft/includes/libft.h"

# define t_addrinfo		struct addrinfo
# define t_sockaddr_in	struct sockaddr_in
# define t_timeval		struct timeval
# define t_ip			struct ip
# define t_icmp			struct icmp
# define t_iovec			struct iovec
# define t_msghdr		struct msghdr
# define PACKETSIZE  64
# define TRUE 1
# define FALSE 0

typedef unsigned char	t_bool;

// struct icmphdr
// {
//   u_int8_t type;		/* message type */
//   u_int8_t code;		/* type sub-code */
//   u_int16_t checksum;
//   union
//   {
//     struct
//     {
//       u_int16_t	id;
//       u_int16_t	sequence;
//     } echo;			/* echo datagram */
//     u_int32_t	gateway;	/* gateway address */
//     struct
//     {
//       u_int16_t	mtu;
//     } frag;			/* path mtu discovery */
//   } un;
// };

// typedef struct	s_packet {
//     struct icmphdr	hdr;
//     char			msg[PACKETSIZE - sizeof(struct icmphdr)];
// }				t_packet;

typedef struct	s_flag {
	int h;
	int v;
}				t_flag;

typedef struct	s_stock {

	t_addrinfo	hints;
	t_addrinfo	*res;

	pid_t 		pid;

	// t_packet	pck;
	char		buf[76];
	char		buf_receive[76];
	char 		*hostname_dst;
	char 		*host_dst;
	char 		*host_src;

	t_ip		*ip;
	t_icmp		*icmp;

	t_flag		opts;

	t_iovec		iov[1];
	t_msghdr	msg;
	char		buf_control[1000];


	int 		sock_fd;
	int 		ping_loop;
	int 		flags;
	int			count;
	int 		timeout;
	int 		interval;
	int 		ttl;
	double		min;

	int			pck_send;
	int 		pck_receive;
	int 		seq;
	int 		df_flag;
}				t_stock;

t_stock 	g_stock;

char 			*get_dns();
void 			display_info();
void			header_configuration();
int				open_socket();
int				ft_ping();
int				fill_flag(int ac, char **av, t_flag *flag);
char			*get_ip(int ac, char **av);
void			print_usage();
void 			pck_send_configuration();
int				ping_loop();
unsigned short	icmp_checksum(unsigned short *data, int len);
void			manage_ping_receive(struct timeval tv_start, struct timeval tv_end);
void			print_resp(int nb_receive, double duration);

#endif