/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 09:54:37 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/04 09:54:38 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define BLACK 0x000000
# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500

typedef struct		s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				fov;
	double			camera_x;
	int				map_x;
	int				map_y;
	double			move;
	double			turn;
	t_ray			*ray;
}					t_player;

typedef struct		s_map
{
	int				nb_line;
	int				nb_int;
	char			*str;
	char			**content;
	int				**tab;
	int				line_height;
	int				pixel_start;
	int				pixel_last;
}					t_map;

typedef struct		s_img
{
	void			*img;
	int				*str_img;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_map			*map;
	t_player		*player;
}					t_mlx;

int					ft_reader(int argc, char *argv, t_map *map);
int					ft_atoi_wolf(char *str, int *i);
int					ft_check_errors(char *str);
int					ft_key_events(int keycode, t_mlx *mlx);
int					ft_init_player(t_mlx *mlx);
void				ft_calc(t_mlx *mlx, t_player *player);
void				ft_draw_col(t_mlx *mlx, int x, int color);

#endif
