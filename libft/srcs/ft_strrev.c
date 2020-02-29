/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:34:19 by khsadira          #+#    #+#             */
/*   Updated: 2017/12/05 10:34:24 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		str_size;
	char	tmp;

	i = 0;
	str_size = ft_strlen(str) - 1;
	while (i < str_size)
	{
		tmp = str[i];
		str[i] = str[str_size];
		str[str_size] = tmp;
		str_size--;
		i++;
	}
	return (str);
}
