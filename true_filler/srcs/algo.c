/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:35:19 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/29 21:35:19 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			valid_token(t_map *map, t_fig *fig, int x, int y)
{
	int j;
	int i;
	int put;

	if (fig->right + 1 + x - fig->left > map->cols ||
			fig->down + 1 - fig->up + y > map->rows)
		return (0);
	put = 0;
	j = -1 + fig->up;
	while (++j < fig->down + 1)
	{
		i = -1 + fig->left;
		while (++i < fig->right + 1)
		{
			if (fig->figure[j][i] == '*' && (map->map[y + j - fig->up]
			[x + i - fig->left] == map->en[0] || map->map[y + j - fig->up]
			[x + i - fig->left] == map->en[1]))
				return (0);
			else if (fig->figure[j][i] == '*' && (map->map[y + j - fig->up]
			[x + i - fig->left] == map->me[0] || map->map[y + j - fig->up]
			[x + i - fig->left] == map->me[1]))
				put++;
		}
	}
	return ((put == 1) ? 1 : 0);
}

static int			magic(t_map *map, t_fig *fig)
{
	int x;
	int y;
	int value;

	value = 777;
	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			if (valid_token(map, fig, x, y) && map->heat[y][x] <= value)
			{
				map->fin_x = x - fig->left;
				map->fin_y = y - fig->up;
				value = map->heat[y][x];
			}
		}
	}
	if (value == 777)
		return (0);
	return (1);
}

int					play(t_map *map, t_fig *fig)
{
	fig->down = 0;
	fig->right = 0;
	real_fig_size(fig);
	return (magic(map, fig));
}
