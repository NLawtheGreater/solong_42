/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:59:11 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/14 17:25:13 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_data *data)
{
	/*t_sprt	p;

	p = data->player;
	if (p.act == ACT_HURTING)
		player_hurting(data);
	else if (p.act == ACT_WALK)
	{
		player_walking(data);
	}
	else if (p.act == ACT_INTERACT)
		player_interacting(data);
	else if (p.act == ACT_STAND)
		player_standing(data);
	else if (p.act == ACT_COLLECTED)
		player_collecting(data);
	else
		player_switch_acting(data);*/
	player_move(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->player.img.ptr, data->player.v.x, data->player.v.y);
}

void	check_object_player(t_data *data, t_tile t)
{
	t_sprt	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->v.x == t.v.x && obj->v.y == t.v.y && t.type == 'C')
		{
			if (obj->img.ptr)
			{
				mlx_destroy_image(data->mlx, obj->img.ptr);
				obj->img.ptr = NULL;
				data->player.item++;
			}
			return ;
		}
		obj = obj->next;
	}
	if (t.type == 'E')
	{
		if (data->map.item == data->player.item)
			exit_game(data, EXIT_SUCCEED);
	}
}

void	moving_handling(t_data *data, int dir)
{
	t_tile	nt;
	t_vtr	mv;
	t_vtr	nv;

	data->player.face = dir;
	mv = get_move_vtr(data->player.face, 0);
	nv = add_vtr(data->player.v, mv);
	nt = get_tile(data, nv);
	if (nt.type == '1')
		return ;
	data->player.nv = nv;
	data->player.v = nv;
	data->player.moved++;
	check_object_player(data, nt);

	ft_printf("Move taken: %d\n", data->player.moved);
	update_score(data);
}

void	player_move(t_data *data)
{
	t_sprt	p;
	t_vtr	mv;

	p = data->player;
	mv = get_move_vtr(p.face, 1);
	data->player.v = add_vtr(data->player.v, mv);
}