/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaw <nlaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:28:30 by tsomsa            #+#    #+#             */
/*   Updated: 2023/02/14 20:57:28 by nlaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render(t_data *data);
static int	keyhandler(int keycode, t_data *data);
static int	rkeyhandler(int keycode, t_data *data);
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
		error_game(data, ERROR_MLX, NULL);
	load_file(data, filename);
	load_map(data);
	/*check*/
	load_tiles(data);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "SO LONG");
	if (!data->win)
		error_game(data, ERROR_WIN, NULL);
	load_game(data);
}

static int	render(t_data *data)
{
	if (data->frame == FRAME_RATE)
	{
		data->frame = 0;
	}
	else
		data->frame += 1;
	render_game(data);
	return (0);
}

static int	keyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		moving_handling(data, DIRCT_LEFT);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		moving_handling(data, DIRCT_RIGHT);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		moving_handling(data, DIRCT_DOWN);
	if (keycode == KEY_UP || keycode == KEY_W)
		moving_handling(data, DIRCT_UP);
	if (keycode == KEY_ESC)
		exit_game(data, EXIT_SUCCEED);
	return (0);
}

/*static int	rkeyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_CTRL)
		ctrl_handling(data, 1);
	return (0);
}*/
