/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:31:35 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/15 20:31:35 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	char	*tmp;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	if (!(tmp = malloc(sizeof(content) * content_size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(tmp, content, content_size);
	new->content = (void *)tmp;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
