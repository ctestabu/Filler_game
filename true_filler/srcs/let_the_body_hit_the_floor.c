/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_body_hit_the_floor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:28:12 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/30 14:28:12 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void				u_lala(t_map *map, int y, int x, int value)
{
	if (x > 0 && !ft_strstr(map->en, &map->map[y + 1][x - 1]) &&
			!map->heat[y + 1][x - 1])
		map->heat[y + 1][x - 1] = value;
	if (!ft_strstr(map->en, &map->map[y + 1][x]) &&
			!map->heat[y + 1][x])
		map->heat[y + 1][x] = value;
	if (!ft_strstr(map->en, &map->map[y + 1][x + 1]) &&
			!map->heat[y + 1][x + 1])
		map->heat[y + 1][x + 1] = value;
}

static void				heat_coord(t_map *map, int y, int x, int value)
{
	if (y > 0 && x > 0)
	{
		if (!ft_strstr(map->en, &map->map[y - 1][x - 1]) &&
				!map->heat[y - 1][x - 1])
			map->heat[y - 1][x - 1] = value;
		if (!ft_strstr(map->en, &map->map[y - 1][x]) &&
				!map->heat[y - 1][x])
			map->heat[y - 1][x] = value;
		if (!ft_strstr(map->en, &map->map[y - 1][x + 1]) &&
				!map->heat[y - 1][x + 1])
			map->heat[y - 1][x + 1] = value;
	}
	if (x > 0 && !ft_strstr(map->en, &map->map[y][x - 1]) &&
			!map->heat[y][x - 1])
		map->heat[y][x - 1] = value;
	if (!ft_strstr(map->en, &map->map[y][x + 1]) &&
			!map->heat[y][x + 1])
		map->heat[y][x + 1] = value;
	if (y < map->rows - 1)
	{
		u_lala(map, y, x, value);
	}
}

static void				init_heat(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			map->heat[y][x] = 0;
		}
	}
}

void					heat_map(t_map *map)
{
	int y;
	int x;
	int value;

	value = -1;
	init_heat(map);
	while (++value < map->cols)
	{
		y = -1;
		while (++y < map->rows)
		{
			x = -1;
			while (++x < map->cols)
			{
				if ((map->map[y][x] == map->en[0] ||
				map->map[y][x] == map->en[1]) && map->heat[y][x] != -1)
				{
					map->heat[y][x] = -1;
					heat_coord(map, y, x, value + 1);
				}
				else if (map->heat[y][x] == value && value)
					heat_coord(map, y, x, value + 1);
			}
		}
	}
}
