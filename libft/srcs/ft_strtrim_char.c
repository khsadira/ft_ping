#include "libft.h"

char	*ft_strtrim_char(const char *s, char c)
{
	int		i;
	int		j;
	
	if (!s || !s[0])
		return NULL;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = ft_strlen(s) - 1;
	while (j > 0 && s[j] == c)
		j--;

	return ft_strsub(s, i, j-i);
}
