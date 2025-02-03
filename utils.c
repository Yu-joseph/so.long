/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 13:06:23 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/14 18:00:39 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(char *s)
{
	int	size;

	size = ft_strlen(s) - 4;
	if (ft_strncmp(&s[size], ".ber", 4) != 0 || s[size + 4] != '\0')
		exit(write(2, "Error\nMap Error", 15));
	return (0);
}

void	player_place(char **map, t_long *data)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				data->x = i;
				data->y = j;
			}
			i++;
		}
		j++;
	}
}

void	the_path(t_long *data)
{
	int	e;

	e = 0;
	data->t_c = 0;
	check_path(data, data->y, data->x, &e);
	if (data->t_c != data->c || e != 1)
		exit(write(2, "Error\nthere is a wrong path\n", 22));
}

void	check_path(t_long *data, int y, int x, int *e)
{
	if (data->map[y][x] == '1')
		return ;
	else if (data->map[y][x] == 'C')
	{
		(data->t_c)++;
		data->map[y][x] = '1';
	}
	else if (data->map[y][x] == 'E')
	{
		data->map[y][x] = '1';
		*e = 1;
	}
	data->map[y][x] = '1';
	check_path(data, y, x + 1, e);
	check_path(data, y + 1, x, e);
	check_path(data, y, x - 1, e);
	check_path(data, y - 1, x, e);
}
