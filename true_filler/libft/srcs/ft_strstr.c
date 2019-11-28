/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:08:47 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/10 20:08:47 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	len = ft_strlen(needle);
	if (!len)
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && needle[j])
		{
			j++;
		}
		if (j == len)
		{
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
