/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:18:31 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/16 15:18:31 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*helper;

	if (!lst || !f)
		return (NULL);
	helper = f(lst);
	fresh = helper;
	while (lst->next)
	{
		lst = lst->next;
		if (!(helper->next = f(lst)))
		{
			free(helper->next);
			return (NULL);
		}
		helper = helper->next;
	}
	return (fresh);
}
