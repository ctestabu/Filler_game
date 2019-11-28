/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcatfoetards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:58:35 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/19 13:58:35 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_length;
	size_t	dst_length;

	i = 0;
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length >= size)
		return (src_length + size);
	while (dst[i] != '\0' && i < size - 1)
		i++;
	while (i < size - 1 && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_length + src_length);
}
