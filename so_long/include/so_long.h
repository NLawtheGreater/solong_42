/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:38:30 by niclaw            #+#    #+#             */
/*   Updated: 2023/02/18 22:39:15 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "game.h"
# include "keys.h"
# include "sprite.h"
# include "files.h"

# ifdef __linux__
#  define IS_LINUX 1
#  define OS "LINUX"
# else
#  define IS_LINUX 0
#  define OS "MAC"
# endif

# define EXIT_SUCCEED		0
# define EXIT_FAILURE		1
# define ERROR_MLX 			1
# define ERROR_WIN			2
# define ERROR_FILE_OPEN	10
# define ERROR_FILE_TYPE	11
# define ERROR_MAP_INVALID	20
# define ERROR_IMG			21

typedef struct s_vtr
{
	int		x;
	int		y;
}	t_vtr;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	char	*name;
	int		w;
	int		h;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tile
{
	char	type;
	t_vtr	v;
}	t_tile;

typedef struct s_sprt
{
	t_vtr			v;
	t_vtr			nv;
	t_img			img;
	char			type;
	int				face;
	int				item;
	int				moved;
	struct s_sprt	*next;
}	t_sprt;

typedef struct s_map
{
	char	*filedata;
	int		width;
	int		height;
	int		grid_x;
	int		grid_y;
	int		grid_test;
	int		item;
	int		exit;
	int		player;
	t_tile	**tiles;
}	t_map;

typedef struct s_panel
{
	int		w;
	int		h;
	t_vtr	v;
	t_sprt	*bg;
	t_sprt	*score;
}	t_panel;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		bsize;
	t_sprt	*bg;
	t_sprt	player;
	t_sprt	*objs;
	t_map	map;
	t_panel	panel;
}	t_data;

t_tile	get_tile(t_data *data, t_vtr v);
t_tile	new_tile(char type, int x, int y);

t_vtr	set_vtr(int x, int y);
t_vtr	add_vtr(t_vtr v1, t_vtr v2);
t_vtr	get_move_vtr(int drct, int msize);

t_img	set_img(t_data *data, char *path);
t_img	get_number_img(t_data *data, char c, t_img *img);

void	grid_loop_util(t_data *data, void (*f)(t_data*, t_tile));
void	add_sprt_list(t_sprt *list, t_sprt *new);
void	render_sprts_util(t_data *data, t_sprt *s);
void	render_sprts_fnc_util(t_data *data, t_sprt *s,
			void (*f)(t_data*, t_sprt*));
void	free_sprts_util(t_data *data, t_sprt *s);

void	load_file(t_data *data, char *filename);
void	load_map(t_data *data);
void	load_tiles(t_data *data);
void	load_panel(t_data *data);
void	load_score(t_data *data);

void	validate_map(t_data *data);
int		validate_file_ext(char *filename);
void	free_map_tiles(t_data *data);
int		valid_path(t_data *data);

void	prefill(t_data *tmp, t_data *data);
void	fill(t_data *tmp, int y, int x);
int		fill_check(t_data *tmp, t_data *data);

void	load_game(t_data *data);
void	render_game(t_data *data);
int		close_game(t_data *data, int keycode);
void	exit_game(t_data *data, int code);
void	error_game(t_data *data, int code, char *msg);

void	new_player(t_data *data, t_tile t);
void	new_obj(t_data *data, t_tile t);
void	new_bg(t_data *data, t_tile t);

void	render_player(t_data *data);
void	check_player(t_data *data, t_tile t);
void	moving_handling(t_data *data, int dirct);

void	update_score(t_data *data);

#endif
