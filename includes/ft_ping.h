#ifndef FT_PING_H
#define FT_PING_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
# include <math.h>

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
# define t_sockaddr		struct sockaddr
# define t_timespec		struct timespec
# define t_timeval		struct timeval
# define t_ip			struct ip
# define t_icmp			struct icmp
# define t_iovec			struct iovec
# define t_msghdr		struct msghdr

# define RECV_TIMEOUT		1
# define PACKETSIZE 		64
# define TRUE				1
# define FALSE				0
# define PING_SLEEP_RATE	1000000

typedef unsigned char	t_bool;

struct icmphdr
{
  u_int8_t type;		/* message type */
  u_int8_t code;		/* type sub-code */
  u_int16_t checksum;
  union
  {
    struct
    {
      u_int16_t	id;
      u_int16_t	sequence;
    } echo;			/* echo datagram */
    u_int32_t	gateway;	/* gateway address */
    struct
    {
      u_int16_t	mtu;
    } frag;			/* path mtu discovery */
  } un;
};

typedef struct	s_packet {
    struct icmphdr	hdr;
    char			msg[PACKETSIZE - sizeof(struct icmphdr)];
}				t_packet;

typedef struct	s_flag {
	int h;
	int v;
}				t_flag;

typedef struct	s_env {

	t_addrinfo	hints;
	t_addrinfo	*res;

	t_sockaddr_in	r_addr;
	int			r_addr_len;

	pid_t 		pid;

	t_packet	pck;
	char		buf[76];
	t_msghdr	msg_receive;
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
	int 		flag;
	int			count;
	int 		timeout;
	int 		interval;
	int 		ttl;

	double		t_min;
	double		t_max;
	double		t_aggregate;
	double		t_aggregate_s;

	int			pck_send;
	int 		pck_receive;
	int 		seq;
	int 		df_flag;
}				t_env;

t_env 	env;

void			ft_error(char *str);
char 			*get_dns();
void 			print_info();
void			header_configuration();
int				open_socket();
int				ft_ping();
int				fill_flag(int ac, char **av, t_flag *flag);
char			*get_ip(int ac, char **av);
void			print_usage();
void 			pck_send_configuration();
int				ping_loop();
unsigned short	icmp_checksum(unsigned short *data, int len);
t_bool			manage_ping_receive(struct timeval tv_start, struct timeval tv_end);
void			print_resp(int nb_receive, double duration);
unsigned short	checksum(void *b, int len);
void			add_duration_stats(double duration);
void			print_stats();


#endif