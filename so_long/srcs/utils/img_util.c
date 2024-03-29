/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclaw <niclaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:57:25 by tsomsa            #+#    #+#             */
/*   Updated: 2023/04/04 20:07:45 by niclaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	set_img(t_data *data, char *path)
{
	t_img	img;
	char	*dir;
	char	*fpath;

	if (TILE_SIZE == 32)
		dir = "asset/sprites_32/";
	else
		dir = "asset/sprites_64/";
	fpath = ft_strjoin(dir, path);
	img.ptr = mlx_xpm_file_to_image(data->mlx, fpath, &img.w, &img.h);
	if (!img.ptr)
		error_game(data, ERROR_WIN, "image error");
	free(fpath);
	return (img);
}

t_img	get_number_img(t_data *data, char c, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(data->mlx, img->ptr);
		img->ptr = NULL;
	}
	if (c == '1')
		return (set_img(data, TEXT_NUMBER_1));
	if (c == '2')
		return (set_img(data, TEXT_NUMBER_2));
	if (c == '3')
		return (set_img(data, TEXT_NUMBER_3));
	if (c == '4')
		return (set_img(data, TEXT_NUMBER_4));
	if (c == '5')
		return (set_img(data, TEXT_NUMBER_5));
	if (c == '6')
		return (set_img(data, TEXT_NUMBER_6));
	if (c == '7')
		return (set_img(data, TEXT_NUMBER_7));
	if (c == '8')
		return (set_img(data, TEXT_NUMBER_8));
	if (c == '9')
		return (set_img(data, TEXT_NUMBER_9));
	else
		return (set_img(data, TEXT_NUMBER_0));
}
