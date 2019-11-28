/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:45:58 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/22 17:45:58 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**map;
	int			**heat;
	char		player;
	char		*me;
	char		*en;
	int			rows;
	int			cols;
	int			fin_y;
	int			fin_x;

}				t_map;

typedef struct	s_fig
{
	char		**figure;
	int			rows;
	int			cols;
	int			up;
	int			left;
	int			down;
	int			right;

}				t_fig;

void			ft_map(t_map *map);
void			pars_fig(t_map *map, t_fig *fig);
void			send_coord(t_map *map, t_fig *fig);
void			end_game(t_map *map);
void			real_fig_size(t_fig *fig);
void			heat_map(t_map *map);
int				play(t_map *map, t_fig *fig);

#endif
