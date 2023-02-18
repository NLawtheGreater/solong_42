/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:31:38 by niclaw            #+#    #+#             */
/*   Updated: 2023/02/18 23:40:12 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prefill(t_data *tmp, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	tmp->map.tiles = malloc(sizeof(t_tile *) * data->map.grid_y);
	while (y < data->map.grid_y)
	{
		x = 0;
		tmp->map.tiles[y] = malloc(sizeof(t_tile) * data->map.grid_x);
		while (x < data->map.grid_x)
		{
			tmp->map.tiles[y][x].type = data->map.tiles[y][x].type;
			x++;
		}
		y++;
	}
	tmp->map.grid_x = data->map.grid_x;
	tmp->map.grid_y = data->map.grid_y;
}

void	fill(t_data *tmp, int y, int x)
{
	if (tmp->map.tiles[y + 1][x].type != '1' && \
		tmp->map.tiles[y + 1][x].type != '2')
	{
		tmp->map.tiles[y + 1][x].type = '2';
		fill (tmp, y + 1, x);
	}
	if (tmp->map.tiles[y][x + 1].type != '1' && \
		tmp->map.tiles[y][x + 1].type != '2')
	{
		tmp->map.tiles[y][x + 1].type = '2';
		fill (tmp, y, x + 1);
	}
	if (tmp->map.tiles[y - 1][x].type != '1' && \
		tmp->map.tiles[y - 1][x].type != '2')
	{
		tmp->map.tiles[y - 1][x].type = '2';
		fill (tmp, y - 1, x);
	}
	if (tmp->map.tiles[y][x - 1].type != '1' && \
		tmp->map.tiles[y][x - 1].type != '2')
	{
		tmp->map.tiles[y][x - 1].type = '2';
		fill (tmp, y, x - 1);
	}
	return ;
}

int	fill_check(t_data *tmp, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map.grid_y)
	{
		x = 0;
		while (x < data->map.grid_x)
		{
			if (tmp->map.tiles[y][x].type == 'E' || \
				tmp->map.tiles[y][x].type == 'C')
				return (0);
			x++;
		}
		y++;
	}
	int		gy;
	return (1);
}
