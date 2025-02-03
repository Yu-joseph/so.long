/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:32:05 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/14 18:55:56 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*red_from_fd(int fd)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	line = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	if (!line)
		exit(write(2, "Error\nemthy map", 15));
	return (line);
}

void	first_last(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		exit(write(2, "Error\nempthy line", 17));
	else if (line[ft_strlen(line) - 1] == '\n' && line[ft_strlen(line)] == '\0')
		exit(write(2, "Error\nempthy line", 17));
}

void	check_errors(t_long *data)
{
	int	i;
	int	count;
	int	x;

	i = 0;
	count = 0;
	x = -1;
	while (data->map[count])
		count++;
	while (++x < count)
	{
		i = 0;
		while (data->map[x][++i])
		{
			if (data->map[x][i] != '1' && (x == 0 || x == count - 1))
				exit(write(2, "ERROR\nMAP NOT VALID!!\n", 22));
			else if (data->map[x][0] != '1' || data->map[x]
			[ft_strlen(data->map[x]) - 1] != '1')
				exit(write (2, "ERROR\nMAP NOT VALID xH and xL!!\n", 32));
			else if (data->map[x][i] != '0' && data->map[x][i] != '1'
			&& data->map[x][i] != 'E' && data->map[x][i] != 'C' 
			&& data->map[x][i] != 'P')
				exit(write (2, "ERROR\nINVALID CHARCTRER FOR MAPS\n", 27));
		}
	}
}

void	draw_images(t_long *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->read[++j])
	{
		i = -1;
		while (data->read[j][++i])
		{
			if (data->read[j][i] == '1')
				mlx_image_to_window(data->game, data->w_image, i * 64, j * 64);
			else if (data->read[j][i] == '0')
				mlx_image_to_window(data->game, data->b_image, i * 64, j * 64);
			else if (data->read[j][i] == 'C')
				mlx_image_to_window(data->game, data->c_image, i * 64, j * 64);
			else if (data->read[j][i] == 'P')
				mlx_image_to_window(data->game, data->b_image, i * 64, j * 64);
			else if (data->read[j][i] == 'E')
			{
				mlx_image_to_window(data->game, data->e_image, i * 64, j * 64);
				data->e_i = i * 64;
				data->e_j = j * 64;
			}
		}
	}
}

void	fix_key_hook(mlx_key_data_t keycode, void *param)
{
	t_long	*data;

	data = (t_long *)param;
	if (keycode.key == MLX_KEY_ESCAPE || keycode.key == MLX_KEY_Q)
		free_struct(data);
	else if ((keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_A)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
	{
		move_left(data);
	}
	else if ((keycode.key == MLX_KEY_RIGHT || keycode.key == MLX_KEY_D)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
	{
		move_right(data);
	}
	else if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
	{
		move_up(data);
	}
	else if ((keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S)
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
	{
		move_dawn(data);
	}
}
