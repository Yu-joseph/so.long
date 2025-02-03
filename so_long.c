/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:55:11 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/14 19:34:24 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_long *data)
{
	int	x;
	int	p;
	int	i;
	int	e;

	x = 0;
	p = 0;
	i = 0;
	e = 0;
	data->c = 0;
	while (data->map[++x])
	{
		i = 0;
		while (data->map[x][++i])
		{
			if (data->map[x][i] == 'P')
				p++;
			else if (data->map[x][i] == 'E')
				e++;
			else if (data->map[x][i] == 'C')
				data->c++;
		}
	}
	if (!(p == 1 && e == 1 && data->c >= 1))
		exit(write (2, "ERROR\nTHERE IS NO PLAYER OR EXIT DOOR\n", 32));
}

void	check_lenth_map(char **map, size_t len)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (ft_strlen(map[x]) != len)
			exit(write(2, "ERROR\nLINES HAS DEFERETNS LENTH\n", 25));
		x++;
	}
}

void	check_map(t_long *data)
{
	int	x;

	x = 0;
	check_lenth_map(data->map, ft_strlen(data->map[x]));
	check_errors(data);
	check_player(data);
}

char	**ft_read_map(char *name)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	line = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit(write(2, "ERROR\ninvalid folder", 20));
	line = red_from_fd(fd);
	first_last(line);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			exit(write(2, "Error\nemtpyline", 15));
		i++;
	}
	map = ft_split(line, '\n');
	return (free(line), map);
}

int	main(int ac, char **av)
{
	t_long	*data;

	if (ac == 1)
		return (write(2, "ERROR\nxxxxx", 11));
	if ((map_name(av[1])))
		return (write (2, "ERROR\nMap error\n", 16));
	data = malloc(sizeof(t_long));
	if (!data)
		return (1);
	data->count = 1;
	data->map = ft_read_map(av[1]);
	data->read = ft_read_map(av[1]);
	if (!data->map)
		return (write(2, "ERROR\nMAP IS EMTHY\n", 19));
	check_map(data);
	player_place(data->map, data);
	the_path(data);
	char_free(data->map);
	map_image(data);
	img_to_window(data);
	mlx_key_hook(data->game, fix_key_hook, data);
	mlx_close_hook(data->game, &free_struct, data);
	mlx_loop(data->game);
	return (0);
}
