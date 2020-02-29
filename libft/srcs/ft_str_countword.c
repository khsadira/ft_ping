#include "libft.h"
#include <stdlib.h>

int	ft_str_countword(const char *s, char c)
{
	int		i;
	int		ret;
	char	*tmp;

	if (!(tmp = ft_strtrim_char(s, c)))
		return 0;
	i = 0;
	ret = 1;
	while (tmp[i])
	{
		if (tmp[i] == c)
		{
			ret++;
			while (tmp[i] && tmp[i] == c)
				i++;
		}
		else
			i++;
	}
	free(tmp);
	return ret;
}
