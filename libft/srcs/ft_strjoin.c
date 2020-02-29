/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:00:15 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 12:32:14 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fraiche;

	if (!s1 || !s2)
		return (NULL);
	fraiche = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (fraiche)
	{
		ft_strcpy(fraiche, s1);
		ft_strcat(fraiche, s2);
		return (fraiche);
	}
	return (NULL);
}
