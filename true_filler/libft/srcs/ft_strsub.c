/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 11:42:02 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/14 11:42:02 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}
