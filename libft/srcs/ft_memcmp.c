/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:57:44 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/16 12:14:13 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*strs1;
	unsigned char	*strs2;

	if (s1 == s2 || n == 0)
		return (0);
	strs1 = (unsigned char *)s1;
	strs2 = (unsigned char *)s2;
	while (n)
	{
		if (*strs1 != *strs2)
			return (*strs1 - *strs2);
		if (n)
		{
			strs1++;
			strs2++;
		}
		n--;
	}
	return (0);
}
