/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_Macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:46:10 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/14 20:08:33 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game(t_data *data)
{
	data->objs = NULL;
	data->bg = NULL;
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
	/*check*/
	mlx_string_put(data->mlx, data->win, 0, 0, 0x0FFF, "SO_LONG");
}

void	exit_game(t_data *data, int code)
{
	ft_putendl_fd("Exit Game", 1);
	free_sprts_util(data, data->bg);
	free_sprts_util(data, data->objs);
	free_sprts_util(data, data->panel.bg);
	free_sprts_util(data, data->panel.score);
	mlx_destroy_image(data->mlx, data->player.img.ptr);
	free_map_tiles(data);
	if (data->map.filedata)
		free(data->map.filedata);
	exit(code);
}

void	error_game(t_data *data, int code, char *msg)
{
	ft_putstr_fd(msg, 15);
	if (code == ERROR_FILE_OPEN || code == ERROR_MLX)
	{
		ft_putendl_fd("Error: %s\n", 1);
		free(data->mlx);
		data->mlx = NULL;
		exit(1);
	}
	else if (code == ERROR_MAP_INVALID)
		ft_putendl_fd("Error: %s\n", 1);
	else if (code == ERROR_WIN)
	{
		ft_putendl_fd("Error: Cannot run MLX WIN\n", 1);
		free(data->win);
		free_map_tiles(data);
	}
	free(data->mlx);
	data->mlx = NULL;
	free(data->map.filedata);
	exit(1);
}

int	close_game(int keycode, t_data *data)
{
	ft_putendl_fd("Close mainGame\n", 1);
	(void) data;
	(void) keycode;
	exit(0);
	return (0);
}
