/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:16 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 11:01:58 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strsrc;
	char	*strdst;

	strsrc = (char *)src;
	strdst = (char *)dst;
	if (strsrc < strdst)
	{
		strsrc += len - 1;
		strdst += len - 1;
		while (len)
		{
			*strdst-- = *strsrc--;
			len--;
		}
	}
	else
	{
		while (len)
		{
			*strdst++ = *strsrc++;
			len--;
		}
	}
	return (dst);
}
