/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:25:06 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/07 16:25:07 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_overflow(const char *str, long int i)
{
	if (str[0] == '-' && i > 0)
		return (0);
	else if ((str[0] == '+' || (str[0] <= '9' && str[0] >= '0')) && i < 0)
		return (-1);
	return ((int)i);
}

int				ft_atoi(const char *str)
{
	int			i;
	long int	j;

	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i++] - '0';
	}
	else if (str[i] == '-')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i++] - '0';
		j = -j;
	}
	else
		while (str[i] >= '0' && str[i] <= '9')
			j = j * 10 + str[i++] - '0';
	return (ft_overflow(str, j));
}
