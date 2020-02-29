#ifndef FT_PING_H
#define FT_PING_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "../libft/includes/libft.h"

typedef struct	s_flag {
	int h;
	int v;
}				t_flag;

int		ft_ping(char *ip, t_flag flag);
int		fill_flag(int ac, char **av, t_flag *flag);
char	*get_ip(int ac, char **av);
void	print_usage();

#endif