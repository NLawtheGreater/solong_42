/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:37:20 by niclaw            #+#    #+#             */
/*   Updated: 2023/02/18 22:37:26 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	get_tile(t_data *data, t_vtr v)
{
	int	gx;
	int	gy;

	gx = v.x / data->bsize;
	gy = v.y / data->bsize;
	return (data->map.tiles[gy][gx]);
}

t_tile	new_tile(char type, int x, int y)
{
	t_tile	tile;

	tile.type = type;
	tile.v.x = x;
	tile.v.y = y;
	return (tile);
}
