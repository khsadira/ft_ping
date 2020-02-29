/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:21:26 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 13:19:56 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char const *s, int a)
{
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a++;
	return (a);
}

static int	end(char const *s, int b)
{
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b--;
	return (b);
}

char		*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		i;
	char	*fraiche;

	if (!s)
		return (NULL);
	a = start(s, 0);
	i = 0;
	if (s[a] == '\0')
	{
		if (!(fraiche = ft_strnew(1)))
			return (NULL);
		return (fraiche);
	}
	b = end(s, (ft_strlen(s) - 1));
	if ((fraiche = ft_strnew(b - a + 1)))
	{
		while (a <= b)
			fraiche[i++] = s[a++];
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (NULL);
}
