#include "ft_ping.h"

void	pck_send_configuration() {
	ft_memset(&(g_stock.buf), 0, sizeof(g_stock.buf));
	g_stock.ip->ip_v = 4;
	g_stock.ip->ip_hl = sizeof(*(g_stock.ip)) >> 2;
	g_stock.ip->ip_tos = 0;
	g_stock.ip->ip_len = htons(sizeof(g_stock.buf));
	g_stock.ip->ip_id = htons(321);
	g_stock.ip->ip_off |= g_stock.df_flag ? htons(IP_DF) : 0;
	g_stock.ip->ip_ttl = g_stock.ttl;
	g_stock.ip->ip_p = g_stock.res->ai_protocol;
	g_stock.ip->ip_sum = 0;
	if (inet_pton(g_stock.res->ai_family, g_stock.host_src, &(g_stock.ip->ip_src.s_addr)) < 0 || inet_pton(g_stock.res->ai_family, g_stock.host_dst, &(g_stock.ip->ip_dst.s_addr)) < 0) {
		fprintf(stderr, "pck_send_configuration: inet_pton failed\n");
		exit(EXIT_FAILURE);
	}
	g_stock.icmp->icmp_type = ICMP_ECHO;
	g_stock.icmp->icmp_code = 0;
	g_stock.icmp->icmp_hun.ih_idseq.icd_id = g_stock.pid;
	g_stock.icmp->icmp_hun.ih_idseq.icd_seq = g_stock.seq;
	g_stock.icmp->icmp_cksum = icmp_checksum((unsigned short *) (g_stock.icmp), sizeof(g_stock.icmp));
}