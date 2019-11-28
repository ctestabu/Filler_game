/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:37:11 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/06 17:37:12 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_help;

	b_help = b;
	i = 0;
	while (len > 0)
	{
		((unsigned char*)b_help)[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}
