/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:00:25 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/12 17:25:28 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char			*s;
	unsigned char		*d;
	unsigned char		*lastsrc;
	unsigned char		*lastdst;

	s = src;
	d = dst;
	if (dst == src)
		return (dst);
	if (d < (unsigned char*)s)
		while (len--)
			*d++ = *s++;
	else
	{
		lastsrc = (unsigned char*)s + (len - 1);
		lastdst = d + (len - 1);
		while (len--)
			*lastdst-- = *lastsrc--;
	}
	return (dst);
}
