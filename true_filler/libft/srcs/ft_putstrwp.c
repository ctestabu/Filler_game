/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrwp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:30:24 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/11 16:30:24 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrwp(char *str, int precision)
{
	if ((precision != -1) && ((size_t)precision < ft_strlen(str)))
	{
		while (precision--)
		{
			ft_putchar(*str);
			str++;
		}
	}
	else
		ft_putstr(str);
}
