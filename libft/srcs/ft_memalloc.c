/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:22:02 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/16 10:41:56 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (size > 0)
	{
		zone = (void*)malloc(size);
		if (zone)
		{
			ft_bzero(zone, size);
			return (zone);
		}
	}
	return (NULL);
}
