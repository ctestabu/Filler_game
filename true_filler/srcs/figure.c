/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:08:46 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/27 17:08:46 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		real_fig_size(t_fig *fig)
{
	int i;
	int j;

	fig->left = fig->cols;
	fig->up = fig->rows;
	i = -1;
	while (++i < fig->rows)
	{
		j = -1;
		while (++j < fig->cols)
		{
			if (fig->figure[i][j] == '*')
			{
				if (j < fig->left)
					fig->left = j;
				if (j > fig->right)
					fig->right = j;
				if (i < fig->up)
					fig->up = i;
				if (i > fig->down)
					fig->down = i;
			}
		}
	}
}

static void	size_of_fig(char *line, t_fig *fig)
{
	int		i;
	char	*helper;

	i = 0;
	helper = line + 6;
	fig->rows = ft_atoi(helper);
	while (helper[i] >= '0' && helper[i] <= '9')
		i++;
	fig->cols = ft_atoi(helper + i);
	fig->figure = (char **)malloc(sizeof(char *) * fig->rows);
	i = -1;
	while (++i < fig->rows)
		fig->figure[i] = (char *)malloc(sizeof(char) * fig->cols + 2);
}

void		pars_fig(t_map *map, t_fig *fig)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '0')
			ft_strcpy(map->map[++i], line + 4);
		else if (ft_strstr(line, "Piece"))
			size_of_fig(line, fig);
		else if (line[0] == '.' || line[0] == '*')
		{
			ft_strcpy(fig->figure[++j], line);
			if (j == fig->rows - 1)
			{
				ft_strdel(&line);
				break ;
			}
		}
		ft_strdel(&line);
	}
}
