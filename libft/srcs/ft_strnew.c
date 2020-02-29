/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:46:01 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/13 14:02:44 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*chaine;
	size_t	i;

	i = 0;
	if (!(chaine = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		chaine[i] = '\0';
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
