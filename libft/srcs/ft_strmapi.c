/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:04:18 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 12:28:46 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			fraiche[i] = f(i, s[i]);
			i++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	return (NULL);
}
