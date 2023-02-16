/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_Linux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:46:10 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/14 20:07:49 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game(t_data *data)
{
	data->objs = NULL;
	data->bg = NULL;
	data->enemies = NULL;
	data->frame = 0;
	grid_loop_util(data, &new_bg);
	load_panel(data);
	load_score(data);
	grid_loop_util(data, &new_obj);
	grid_loop_util(data, &new_player);
}

void	render_game(t_data *data)
{
	render_sprts_util(data, data->bg);
	render_sprts_util(data, data->panel.bg);
	render_sprts_util(data, data->panel.score);
	render_sprts_util(data, data->objs);
	render_player(data);
}

void	exit_game(t_data *data, int code)
{
	ft_printf("Exit Game\n");
	free_sprts_util(data, data->bg);
	free_sprts_util(data, data->objs);
	free_sprts_util(data, data->panel.bg);
	free_sprts_util(data, data->panel.score);
	if (data->map.filedata)
		free(data->map.filedata);
	if (IS_LINUX)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	exit(code);
}

void	error_game(t_data *data, int code, char *msg)
{
	if (code == ERROR_FILE_OPEN || code == ERROR_MAP_INVALID)
		ft_printf("Error: %s\n", msg);
	else if (code == ERROR_MLX)
	{
		ft_printf("Error: MLX lib cannot operation\n");
		free(data->mlx);
	}
	else if (code == ERROR_WIN)
	{
		ft_printf("Error: MLX WIN lib cannoot operation\n");
		free(data->mlx);
		free(data->win);
	}
	free(data->map.filedata);
	exit(1);
}

int	close_game(int keycode, t_data *data)
{
	ft_printf("Close Game\n");
	(void) data;
	(void) keycode;
	exit(0);
	return (0);
}
