/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:39:04 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/16 14:39:04 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*helper;

	helper = *alst;
	while (helper != NULL)
	{
		tmp = helper;
		del(helper->content, helper->content_size);
		free(helper);
		helper = tmp->next;
	}
	*alst = NULL;
}
