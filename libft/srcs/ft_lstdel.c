/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:05:24 by khsadira          #+#    #+#             */
/*   Updated: 2017/11/30 12:05:40 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*lst;

	if (alst == NULL)
		return ;
	lst = *alst;
	while (lst != NULL)
	{
		tmp = lst->next;
		ft_lstdelone(&lst, del);
		lst = tmp;
	}
	*alst = NULL;
}
