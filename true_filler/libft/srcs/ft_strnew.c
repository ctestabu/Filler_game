/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:49:45 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/12 16:49:46 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if (size + 1 == 0)
		return (NULL);
	if (!(fresh = (char *)ft_memalloc(sizeof(*fresh) * size + 1)))
		return (NULL);
	ft_memset(fresh, '\0', size + 1);
	return (fresh);
}
