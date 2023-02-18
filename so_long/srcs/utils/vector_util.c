/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:06:44 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/18 19:44:04 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vtr	get_move_vtr(int dir, int msize)
{
	t_vtr	v;
	int		m;

	v.x = 0;
	v.y = 0;
	if (msize == 0)
		m = TILE_SIZE;
	else
		m = msize * TILE_SIZE / 32;
	if (dir == DIR_LEFT)
		v.x = m * -1;
	if (dir == DIR_RIGHT)
		v.x = m;
	if (dir == DIR_UP)
		v.y = m * -1;
	if (dir == DIR_DOWN)
		v.y = m;
	return (v);
}

t_vtr	add_vtr(t_vtr v1, t_vtr v2)
{
	t_vtr	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	return (v3);
}

t_vtr	set_vtr(int x, int y)
{
	t_vtr	v;

	v.x = x;
	v.y = y;
	return (v);
}
