/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:01:58 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/27 15:01:58 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			end_game(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->rows)
	{
		free(map->map[i]);
		map->map[i] = NULL;
	}
	while (--i > -1)
	{
		free(map->heat[i]);
	}
	free(map->map);
	free(map->heat);
	map->map = NULL;
	ft_putstr("0 0\n");
	exit(1);
}

void			send_coord(t_map *map, t_fig *fig)
{
	int i;

	i = -1;
	ft_putnbr(map->fin_y);
	ft_putchar(' ');
	ft_putnbr(map->fin_x);
	ft_putchar('\n');
	while (++i < fig->rows)
		ft_strdel(&fig->figure[i]);
	free(fig->figure);
	fig->figure = NULL;
}

static void		size_of_map(char *line, t_map *map)
{
	int		i;
	char	*helper;

	i = 0;
	helper = line + 8;
	map->rows = ft_atoi(helper);
	while (helper[i] >= '0' && helper[i] <= '9')
		i++;
	map->cols = ft_atoi(helper + i);
}

void			ft_map(t_map *map)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "p1 : [./ctestabu.filler"))
			map->player = 1;
		else if (ft_strstr(line, "Plateau"))
		{
			size_of_map(line, map);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	map->map = (char**)malloc(sizeof(char *) * map->rows);
	i = -1;
	while (++i < map->rows)
		map->map[i] = (char *)malloc(sizeof(char) * map->cols + 1);
	map->heat = (int **)malloc(sizeof(int *) * map->rows);
	while (--i > -1)
		map->heat[i] = malloc(sizeof(int) * map->cols);
	map->me = (map->player) ? "Oo" : "Xx";
	map->en = (map->player) ? "Xx" : "Oo";
}
