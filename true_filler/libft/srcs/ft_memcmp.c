/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:05:16 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/12 17:29:51 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
		{
			return ((int)((unsigned const char *)s1)[i] -
				((unsigned const char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
