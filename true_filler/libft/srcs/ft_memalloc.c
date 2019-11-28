/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:30:08 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/12 16:30:10 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*fresh;

	if (!(fresh = (unsigned char*)malloc(sizeof(*fresh) * size)))
		return (NULL);
	ft_bzero(fresh, size);
	return ((void*)(fresh));
}
