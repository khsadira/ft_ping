/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:29:05 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/16 12:13:59 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*strsrc;
	char	*strdst;

	strsrc = (char *)src;
	strdst = (char *)dst;
	c = (char)c;
	while (n && *strsrc != c)
	{
		n--;
		*strdst++ = *strsrc++;
	}
	if (n)
	{
		*strdst++ = *strsrc++;
		return ((void*)strdst);
	}
	else
		return (NULL);
}
