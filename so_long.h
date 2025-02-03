/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysouhail <ysouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:58:13 by ysouhail          #+#    #+#             */
/*   Updated: 2024/06/14 18:10:45 by ysouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "/Users/ysouhail/MLX42/include/MLX42/MLX42.h"
# include "./printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_long
{
	int				t_e;
	int				t_c;
	int				e;
	int				c;
	int				x;
	int				y;
	char			**read;
	char			**map;
	int				count;
	int				e_i;
	int				e_j;
	mlx_t			*game;
	mlx_texture_t	*e_texture;
	mlx_texture_t	*p_texture;
	mlx_texture_t	*c_texture;
	mlx_texture_t	*w_texture;
	mlx_texture_t	*b_texture;
	mlx_image_t		*e_image;
	mlx_image_t		*p_image;
	mlx_image_t		*c_image;
	mlx_image_t		*w_image;
	mlx_image_t		*b_image;
}			t_long;
int		map_name(char *s);
char	**ft_read_map(char *name);
void	player_place(char **map, t_long *data);
void	the_path(t_long *data);
void	check_path(t_long *data, int y, int x, int *e);
void	map_image(t_long *data);
void	img_to_window(t_long *data);
void	char_free(char **arr);
void	free_struct(void *data);
void	fix_key_hook(mlx_key_data_t keycode, void *param);
void	move_left(t_long *data);
void	move_right(t_long *data);
void	move_up(t_long *data);
void	move_dawn(t_long *data);
char	*red_from_fd(int fd);
void	first_last(char *line);
void	check_errors(t_long *data);
void	free_texture(t_long *data);
void	draw_images(t_long *data);
#endif