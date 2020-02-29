/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:44:27 by khsadira          #+#    #+#             */
/*   Updated: 2017/12/01 12:54:23 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isnum(str[i]))
	{
		nbr *= 10;
		nbr += ((int)str[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
}
