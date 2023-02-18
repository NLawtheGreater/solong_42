/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:08:24 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/18 19:46:30 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_sprt_list(t_sprt *list, t_sprt *new)
{
	t_sprt	*tmp;

	if (!list)
		list = new;
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	render_sprts_util(t_data *data, t_sprt *tmp)
{
	while (tmp)
	{
		if (tmp->img.ptr)
			mlx_put_image_to_window(
				data->mlx, data->win, tmp->img.ptr, tmp->v.x, tmp->v.y);
		tmp = tmp->next;
	}
}

void	render_sprts_fnc_util(t_data *data, t_sprt *tmp,
	void (*f)(t_data*, t_sprt*))
{
	while (tmp)
	{
		f(data, tmp);
		if (tmp->img.ptr)
			mlx_put_image_to_window(
				data->mlx, data->win, tmp->img.ptr, tmp->v.x, tmp->v.y);
		tmp = tmp->next;
	}
}

void	free_sprts_util(t_data *data, t_sprt *s)
{
	t_sprt	*tmp;

	tmp = s;
	while (tmp)
	{
		if (tmp->img.ptr)
			mlx_destroy_image(data->mlx, tmp->img.ptr);
		tmp = tmp->next;
	}
}

void	grid_loop_util(t_data *data, void (*f)(t_data*, t_tile))
{
	t_tile	t;
	int		gx;
	int		gy;

	gy = 0;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			t = data->map.tiles[gy][gx];
			f(data, t);
			gx++;
		}
		gy++;
	}
}
