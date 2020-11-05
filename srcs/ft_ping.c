#include "ft_ping.h"
#include <errno.h>

void			sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		env.ping_loop = 0;
		print_stats();
		free_env();
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGALRM)
		env.timeout_flag = TRUE;
}

int ft_ping()
{
	if (!(env.host_dst = get_dns()))
		ft_error("DNS Lookup failed: Could not resolve hostname\n");
	if (open_socket() == -1)
		ft_error("Failed to open a socket\n");
	header_configuration();
	// pck_send_configuration();
	signal(SIGALRM, sig_handler);
	signal(SIGINT, sig_handler);
	return ping_loop();
}