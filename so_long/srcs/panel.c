/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:59:32 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/18 20:54:06 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_number(t_data *data, int i);

void	load_panel(t_data *data)
{
	int		gx;
	int		gy;
	t_sprt	*bg;

	gx = 5;
	gy = data->map.grid_y;
	bg = data->panel.bg;
	data->panel.h = data->bsize;
	data->panel.w = data->map.width;
	data->panel.v.x = 0;
	data->panel.v.y = data->map.height;
	data->panel.bg = NULL;
	mlx_string_put(data->mlx, data->win, data->panel.v.x + 10, \
		data->panel.v.y + 20, 0x8B008B, "Sprites by trevor-pupkin.itch.io");
}

void	load_score(t_data *data)
{
	int		i;

	data->panel.score = NULL;
	i = 0;
	while (i < 4)
		init_number(data, i++);
}

static void	init_number(t_data *data, int i)
{
	int		sx;
	t_sprt	*s;

	sx = data->w - SCORE_LEN * data->bsize;
	s = malloc(sizeof(t_sprt));
	s->v.x = sx + i * data->bsize;
	s->v.y = data->map.height;
	s->img = set_img(data, TEXT_NUMBER_0);
	s->next = NULL;
	if (!data->panel.score)
		data->panel.score = s;
	else
		add_sprt_list(data->panel.score, s);
}

void	update_score(t_data *data)
{
	char	*txt;
	int		len;
	int		i;
	t_sprt	*s;

	txt = ft_itoa(data->player.moved);
	len = ft_strlen(txt);
	s = data->panel.score;
	i = 0;
	while (i < SCORE_LEN)
	{
		if (i == 3 && len >= 1)
			s->img = get_number_img(data, txt[len - 1], &s->img);
		else if (i == 2 && len >= 2)
			s->img = get_number_img(data, txt[len - 2], &s->img);
		else if (i == 1 && len >= 3)
			s->img = get_number_img(data, txt[len - 3], &s->img);
		else if (i == 0 && len == 4)
			s->img = get_number_img(data, txt[len - 4], &s->img);
		i++;
		s = s->next;
	}
	free(txt);
}
