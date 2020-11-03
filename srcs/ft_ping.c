#include "ft_ping.h"
#include <errno.h>

static void intHandler()
{
	env.ping_loop = 0;
}

int ft_ping()
{
	if (!(env.host_dst = get_dns()))
	{
		fprintf(stderr, "DNS Lookup failed: Could not resolve hostname\n");
		return 1;
	}
	if (open_socket() == -1)
		return 1;
	// header_configuration();
	signal(SIGINT, intHandler);
	return ping_loop();
}