/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:35:14 by khsadira          #+#    #+#             */
/*   Updated: 2017/12/05 10:35:24 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_prime(int nb)
{
	int	i;

	i = 7;
	if (nb < 2)
		return (0);
	else if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)
		return (0);
	else
	{
		while (nb / 2 >= i)
		{
			if (nb % i == 0)
				return (0);
			i += 2;
		}
	}
	return (1);
}
