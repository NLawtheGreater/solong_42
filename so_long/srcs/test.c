#include "so_long.h"

int main (int argc, char **argv)
{
	t_data	data;

	data.w = 256;
	data.h = 256;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.w, data.h, "SO LONG");
	mlx_string_put(data.mlx, data.win, 0, data.h/2, 0x8B08B,"Sprites by trevor-pupkin.itch.io");
	return (0);
}