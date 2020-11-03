#include "ft_ping.h"

void	pck_send_configuration() {
	ft_memset(&(env.buf), 0, sizeof(env.buf));
	env.ip->ip_v = 4;
	env.ip->ip_hl = sizeof(*(env.ip)) >> 2;
	env.ip->ip_tos = 0;
	env.ip->ip_len = htons(sizeof(env.buf));
	env.ip->ip_id = htons(321);
	env.ip->ip_off |= env.df_flag ? htons(IP_DF) : 0;
	env.ip->ip_ttl = env.ttl;
	env.ip->ip_p = env.res->ai_protocol;
	env.ip->ip_sum = 0;
	if (inet_pton(env.res->ai_family, env.host_src, &(env.ip->ip_src.s_addr)) < 0 || inet_pton(env.res->ai_family, env.host_dst, &(env.ip->ip_dst.s_addr)) < 0) {
		fprintf(stderr, "pck_send_configuration: inet_pton failed\n");
		exit(EXIT_FAILURE);
	}
	env.icmp->icmp_type = ICMP_ECHO;
	env.icmp->icmp_code = 0;
	env.icmp->icmp_hun.ih_idseq.icd_id = env.pid;
	env.icmp->icmp_hun.ih_idseq.icd_seq = env.seq;
	env.icmp->icmp_cksum = icmp_checksum((unsigned short *) (env.icmp), sizeof(env.icmp));
}
