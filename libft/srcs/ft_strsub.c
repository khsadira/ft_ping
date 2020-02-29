/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:20:48 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 12:31:55 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	fraiche = ft_strnew(len);
	if (fraiche == NULL)
		return (NULL);
	while (i < len)
	{
		fraiche[i] = s[start + i];
		i++;
	}
	return (fraiche);
}
