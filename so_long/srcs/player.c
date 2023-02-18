/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:51:04 by niclaw            #+#    #+#             */
/*   Updated: 2023/02/18 22:27:23 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	check_player(data, nt);
	ft_putstr_fd("Move taken:", 1);
	ft_putendl_fd(data->player.moved, 1);
	update_score(data);
}

void	render_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->player.img.ptr, data->player.v.x, data->player.v.y);
}

void	check_player(t_data *data, t_tile t)
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
