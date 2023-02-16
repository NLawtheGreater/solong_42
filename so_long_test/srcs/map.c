/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:43:10 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/14 16:42:34 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map_data(t_data *data, int is_init);

static t_tile	new_tile(char type, int x, int y)
{
	t_tile	tile;

	tile.type = type;
	/*check*/
	tile.v.x = x;
	tile.v.y = y;
	return (tile);
}

void	load_map(t_data *data)
{
	char	*f;

	f = data->map.filedata;
	init_map_data(data, 1);
	while (*f)
	{
		data->map.grid_test = 0;
		while (*f && *f != '\n')
		{
			if (*f != 'C' || *f != 'E' || *f != 'P' || *f != '1' || *f != '0')
				error_game(data, ERROR_MAP_INVALID, "map invalid");
			if (data->map.grid_y == 0)
				data->map.grid_x++;
			if (*f == 'C')
				data->map.item++;
			else if (*f == 'E')
				data->map.exit++;
			else if (*f == 'P')
				data->map.player++;
			data->map.grid_test++;
			f++;
		}
		if (data->map.grid_test != data->map.grid_x)
			error_game(data, ERROR_MAP_INVALID, "map not a grid");
		data->map.grid_y++;
		f++;
	}
	init_map_data(data, 0);
	
	validate_map(data);
}

void	load_tiles(t_data *data)
{
	char	*str;
	int		gx;
	int		gy;

	data->map.tiles = malloc(sizeof(t_tile *) * data->map.grid_y);
	gy = 0;
	str = data->map.filedata;
	while (*str)
	{
		gx = 0;
		data->map.tiles[gy] = malloc(sizeof(t_tile) * data->map.grid_x);
		while (*str != '\n' && *str)
		{
			data->map.tiles[gy][gx] = new_tile(
					*str, gx * data->bsize, gy * data->bsize);
			gx++;
			str++;
		}
		str++;
		gy++;
	}
}

void	free_map_tiles(t_data *data)
{
	int		gy;

	gy = 0;
	while (gy < data->map.grid_y)
	{
		free(data->map.tiles[gy]);
		gy++;
	}
	free(data->map.tiles);
}

static void	init_map_data(t_data *data, int is_init)
{
	if (is_init)
	{
		data->map.grid_x = 0;
		data->map.grid_y = 0;
		data->map.item = 0;
		data->map.exit = 0;
		data->map.player = 0;
	}
	else
	{
		data->map.width = data->map.grid_x * data->bsize;
		data->map.height = data->map.grid_y * data->bsize;
		data->w = data->map.width;
		data->h = data->map.height + data->bsize;
	}
}
