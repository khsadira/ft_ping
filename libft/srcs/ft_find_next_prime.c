/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:35:29 by khsadira          #+#    #+#             */
/*   Updated: 2017/12/05 10:35:33 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (!ft_is_prime(nb))
		return (ft_find_next_prime(nb + 1));
	return (nb);
}
