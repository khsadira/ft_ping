#include "ft_ping.h"

static t_flag	init_flag()
{
	t_flag ret;

	ret.h = 0;
	ret.v = 0;
	return ret;
}

t_flag 	fill_flag(int ac, char **av)
{
	t_flag	ret;
	int		i;

	ret = init_flag();
	return ret;
}
