/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:28:30 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/18 20:36:45 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render(t_data *data);
static int	keyhandler(int keycode, t_data *data);
static void	initiate(t_data *data, char *filename);

int	main(int argc, char **argv)
{
	t_data	data;
	char	*filename;

	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = argv[1];
	data.bsize = TILE_SIZE;
	initiate(&data, filename);
	mlx_loop_hook(data.mlx, &render, &data);
	/*check*/
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 1L << 0, &close_game, &data);
	mlx_loop(data.mlx);
	return (0);
}

static void	initiate(t_data *data, char *filename)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_game(data, ERROR_MLX, "Cannot load MLX");
	load_file(data, filename);
	load_map(data);
	load_tiles(data);
	if (valid_path(data) == 0)
	{
		free_map_tiles(data);
		error_game(data, ERROR_MAP_INVALID, "Map has invalid path");
	}
	data->win = mlx_new_window(data->mlx, data->w, data->h, "SO LONG");
	if (!data->win)
		error_game(data, ERROR_WIN, NULL);
	load_game(data);
}

static int	render(t_data *data)
{
	render_game(data);
	return (0);
}

static int	keyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		moving_handling(data, DIR_LEFT);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		moving_handling(data, DIR_RIGHT);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		moving_handling(data, DIR_DOWN);
	if (keycode == KEY_UP || keycode == KEY_W)
		moving_handling(data, DIR_UP);
	if (keycode == KEY_ESC)
		exit_game(data, EXIT_SUCCEED);
	return (0);
}
