/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:45:51 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 12:28:34 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraiche;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	fraiche = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (fraiche)
	{
		while (s[i])
		{
			fraiche[i] = f(s[i]);
			i++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (NULL);
}
