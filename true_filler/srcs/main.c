/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:35:53 by ctestabu          #+#    #+#             */
/*   Updated: 2019/07/29 21:35:53 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					main(void)
{
	t_fig		fig;
	t_map		map;

	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&fig, sizeof(t_fig));
	ft_map(&map);
	while (42)
	{
		pars_fig(&map, &fig);
		heat_map(&map);
		if (play(&map, &fig))
			send_coord(&map, &fig);
		else
			end_game(&map);
	}
	return (0);
}
