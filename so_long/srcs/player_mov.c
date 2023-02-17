/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 23:48:35 by araiva            #+#    #+#             */
/*   Updated: 2023/02/14 17:25:14 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	player_interacting(t_data *data)
{
	t_sprt	p;
	t_tile	t;

	p = data->player;
	mlx_destroy_image(data->mlx, data->player.img.ptr);
	data->player.act = ACT_INTERACT;
	data->player.img = set_img(data, SPRITE_INTERACT_PATH);
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_STAND;
		data->player.animating = 0;
		t = get_tile(data, data->player.v);
		p = data->player;
		if (t.type == 'E')
		{
			if (data->map.item == p.item)
				exit_game(data, EXIT_SUCCEED);
		}
	}
}*/