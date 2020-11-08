#include "ft_ping.h"


static t_flag	init_flag()
{
	t_flag ret;

	ret.h = 0;
	ret.v = 0;

	return ret;
}

static int check_flag(char *s, t_flag *flag)
{
	int i;

	if (ft_strlen(s) < 2)
		return -1;
	i = 1;
	while (s[i])
	{
		if (s[i] == 'h') {
			print_usage();
			free_env();
			exit(EXIT_SUCCESS);
		}
		else if (s[i] == 'v')
			flag->v = 1;
		else
			return -1;
		i++;
	}
	return 0;
}

int		fill_flag(int ac, char **av, t_flag *flag)
{
	int		i;

	*flag = init_flag();
	i = 1;

	while (i < ac)
	{
		if (ft_strequ(av[i], "--"))
			return i + 1;
		else if (!ft_strnequ(av[i], "-", 1))
			return i;
		if (check_flag(av[i], flag))
			return -1;
		i++;
	}
	return -1;
}
