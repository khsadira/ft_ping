/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:14:36 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/30 13:33:42 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*chardst;
	const char	*charsrc;
	size_t		size;

	if (!dst && !src)
		return (dst);
	chardst = dst;
	charsrc = src;
	size = 0;
	while (n)
	{
		chardst[size] = charsrc[size];
		size++;
		n--;
	}
	return (dst);
}
