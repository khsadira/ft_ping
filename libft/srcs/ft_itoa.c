/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:00:28 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 13:41:17 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizeint(int nb, int neg)
{
	int	count;

	count = 0;
	if (neg == 1)
		count = 1;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*newstr(char *str, int i, int j)
{
	char	temp;

	while (i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

char		*ft_itoa2(int i, int j, unsigned int n, int neg)
{
	char	*str;

	if (!(str = ft_strnew(sizeint(n, neg))))
		return (NULL);
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	if (neg)
	{
		str[i++] = '-';
		j = 1;
	}
	while (n > 0)
	{
		str[i++] = n % 10 + 48;
		n /= 10;
	}
	str[i--] = '\0';
	str = newstr(str, i, j);
	return (str);
}

char		*ft_itoa(int n)
{
	int				i;
	int				j;
	unsigned int	a;
	char			*new;

	i = 0;
	j = 0;
	if (n < 0)
	{
		a = -n;
		new = ft_itoa2(i, j, a, 1);
	}
	else
	{
		a = n;
		new = ft_itoa2(i, j, a, 0);
	}
	return (new);
}
