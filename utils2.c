/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 01:01:03 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/14 19:45:31 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_free(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

void	free_texture(t_long *data)
{
	data->e_image = mlx_texture_to_image(data->game, data->e_texture);
	data->p_image = mlx_texture_to_image(data->game, data->p_texture);
	data->c_image = mlx_texture_to_image(data->game, data->c_texture);
	data->w_image = mlx_texture_to_image(data->game, data->w_texture);
	data->b_image = mlx_texture_to_image(data->game, data->b_texture);
	mlx_delete_texture(data->e_texture);
	mlx_delete_texture(data->p_texture);
	mlx_delete_texture(data->c_texture);
	mlx_delete_texture(data->w_texture);
	mlx_delete_texture(data->b_texture);
}

void	map_image(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->read[0][i])
		i++;
	while (data->read[j])
		j++;
	if (((i * 64) > 2560 || (j * 64) > 1440))
	{
		char_free(data->read);
		exit(write(2, "ERROR\ninvalid\n", 15));
	}
	data->game = mlx_init(i * 64, j * 64, "so_long", true);
	data->e_texture = mlx_load_png("./texture/E.png");
	data->p_texture = mlx_load_png("./texture/P.png");
	data->c_texture = mlx_load_png("./texture/C.png");
	data->w_texture = mlx_load_png("./texture/1.png");
	data->b_texture = mlx_load_png("./texture/0.png");
	if (!data->e_texture || !data->p_texture || !data->c_texture 
		|| !data->w_texture || !data->b_texture)
		exit(write (2, "ERROR\nImageserror", 17));
	free_texture(data);
}

void	img_to_window(t_long *data)
{
	data->e_i = 0;
	data->e_j = 0;
	if (!data->w_image || !data->b_image || !data->e_image || !data->c_image)
		exit(write(2, "ERROR\nerror", 11));
	draw_images(data);
	mlx_image_to_window(data->game, data->p_image, data->x * 64, data->y * 64);
}

void	free_struct(void *data)
{
	t_long	*tmp;

	tmp = data;
	if (tmp->game)
	{
		mlx_close_window(tmp->game);
	}
	free (tmp);
	char_free(tmp->read);
	exit(0);
}
