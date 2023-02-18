/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_Macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 01:46:10 by nlaw              #+#    #+#             */
/*   Updated: 2023/02/14 20:08:33 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game(t_data *data)
{
	data->objs = NULL;
	data->bg = NULL;
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
	ft_putendl_fd("\nExit Game", 1);
	free_sprts_util(data, data->bg);
	free_sprts_util(data, data->objs);
	free_sprts_util(data, data->panel.bg);
	free_sprts_util(data, data->panel.score);
	mlx_destroy_image(data->mlx, data->player.img.ptr);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	free(data->win);
	free_map_tiles(data);
	if (data->map.filedata)
		free(data->map.filedata);
	free(data->mlx);
	exit(code);
}

void	error_game(t_data *data, int code, char *msg)
{
	if (code == ERROR_FILE_OPEN || code == ERROR_MLX)
	{
		ft_putendl_fd("Error: %s\n", 1);
		ft_putstr_fd(msg, 1);
		free(data->mlx);
		data->mlx = NULL;
		exit(1);
	}
	else if (code == ERROR_MAP_INVALID || code == ERROR_IMG)
		ft_putendl_fd("Error: %s\n", 1);
	else if (code == ERROR_WIN)
	{
		ft_putendl_fd("Error: Cannot run MLX WIN\n", 1);
		/*mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);*/
		free(data->win);
		free_map_tiles(data);
	}
	free(data->mlx);
	data->mlx = NULL;
	free(data->map.filedata);
	exit(1);
}

int	close_game(t_data *data, int keycode)
{
	(void) data;
	(void) keycode;
	ft_putendl_fd("Close Game\n", 1);
	exit_game(data, EXIT_FAILURE);
	return (0);
}
