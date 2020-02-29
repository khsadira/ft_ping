#ifndef FT_PING_H
#define FT_PING_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_flag {
	int h;
	int v;
}				t_flag;

int ft_ping(int ac, char **av);
t_flag fill_flag(int ac, char **av);
char *get_ip(int ac, char **av);

#endif