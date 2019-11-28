/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:08:16 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/14 15:08:16 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*fresh;
	size_t			len;
	long int		n_helper;
	int				index;

	n_helper = n;
	index = n < 0 ? 1 : 0;
	len = ft_intlen(n_helper);
	len += index ? 1 : 0;
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	fresh[len--] = '\0';
	if (index)
	{
		fresh[0] = '-';
		n_helper *= (-1);
	}
	while (n_helper / 10 != 0 && len)
	{
		fresh[len] = n_helper % 10 + '0';
		n_helper = n_helper / 10;
		len--;
	}
	fresh[len] = n_helper % 10 + '0';
	return (fresh);
}
