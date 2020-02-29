/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:20:32 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/23 11:03:26 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static const char	*next_word(const char *str, char c, int i)
{
	if (i == 1)
		while (*str && *str == c)
			str++;
	else
		while (*str && *str != c)
			str++;
	return (str);
}

static int			nb_words(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		str = next_word(str, c, 1);
		if (*str)
		{
			i++;
			str = next_word(str, c, 0);
		}
	}
	return (i);
}

static char			**cleantable(char **tab, int i)
{
	int	a;

	a = 0;
	while (a < i)
		free(tab[a]);
	free(tab);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**tab;
	const char	*word;
	int			i;

	i = 0;
	if (str == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (nb_words(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (*str)
	{
		str = next_word(str, c, 1);
		if (*str)
		{
			word = next_word(str, c, 0);
			tab[i] = ft_strsub(str, 0, word - str);
			if (tab[i] == NULL)
				return (cleantable(tab, i));
			i++;
			str = word;
		}
	}
	tab[i] = 0;
	return (tab);
}
