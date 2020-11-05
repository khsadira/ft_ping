#include "ft_ping.h"

// void	pck_send_configuration_2() {
// 	ft_memset(&(env.buf), 0, sizeof(env.buf));
// 	env.ip->ip_v = 4;
// 	env.ip->ip_hl = sizeof(*(env.ip)) >> 2;
// 	env.ip->ip_tos = 0;
// 	env.ip->ip_len = htons(sizeof(env.buf));
// 	env.ip->ip_id = 0;
// 	env.ip->ip_off |= env.flags.d ? htons(IP_DF) : 0;
// 	env.ip->ip_ttl = env.ttl;
// 	env.ip->ip_p = env.res->ai_protocol;
// 	env.ip->ip_sum = 0;
	
// 	if (inet_pton(env.res->ai_family, env.host_src, &(env.ip->ip_src.s_addr)) < 0 || inet_pton(env.res->ai_family, env.host_dst, &(env.ip->ip_dst.s_addr)) < 0) 
// 		ft_error("pck_send_configuration: inet_pton failed\n");

// 	env.icmp->icmp_type = ICMP_ECHO;
// 	env.icmp->icmp_code = 0;
// 	env.icmp->icmp_hun.ih_idseq.icd_id = env.pid;
// 	env.icmp->icmp_hun.ih_idseq.icd_seq = env.seq;
// 	env.icmp->icmp_cksum = icmp_checksum((unsigned short *)(env.icmp), sizeof(env.icmp));

// 	if (setsockopt(env.sock_fd, 0, IP_TTL, &env.ttl, sizeof(env.ttl)) != 0) {
// 		ft_error("Setting socket options to TTL failed!\n");
// 	}
// }

void pck_send_configuration() {
	int	i = 0;
	
	if (setsockopt(env.sock_fd, 0, IP_TTL, &env.ttl, sizeof(env.ttl)) != 0) {
		ft_error("Setting socket options to TTL failed!\n");
	}

	ft_bzero(&(env.pck), sizeof(env.pck));

	env.pck.hdr.type = ICMP_ECHO;
	env.pck.hdr.un.echo.id = env.pid;

	for (i = 0; i < sizeof(env.pck.msg) - 1; i++) {
	env.pck.msg[i] = i+'0';
	}

	env.pck.msg[i] = '\0';
	env.pck.hdr.un.echo.sequence = env.seq;
	env.pck.hdr.checksum = checksum(&env.pck, sizeof(env.pck));
}
