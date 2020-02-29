/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:39:40 by khsadira          #+#    #+#             */
/*   Updated: 2017/12/05 10:34:54 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	str = ft_strupcase(str);
	while (str[i])
	{
		if (ft_isalpha(str[i]) && ft_isalnum(str[i - 1]))
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
