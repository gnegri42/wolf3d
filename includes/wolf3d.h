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
# include "../libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH		800
# define WIN_HEIGHT		600
# define TEXTURE_WIDTH	64
# define TEXTURE_HEIGHT	64

# define BLACK 0x000000
# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define RED 0xFF0000

typedef struct		s_color
{
	int				col_x;
	int				col_y;
	int				col_xy;
}					t_color;

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
	double			wall_hit;
	int				texture_num;
	int				texture_coord;
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
	double			camera_x;
	double			dist;
	double			current_dist;
	int				map_x;
	int				map_y;
	double			move;
	double			turn;
	int				weapon;
	int				shoot;
	int				pas;
	int				count_x;
	int				count_y;
	int				weapon_x;
	int				weapon_y;
	t_ray			*ray;
}					t_player;

typedef struct		s_img
{
	void			*img;
	int				*str_img;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

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
	int				switch_tex;
	int				resize;
	int				tex_hit;
	int				tex_change;
	int				show_map;
	int				color_minimap;
	int				show_help;
	int				modif_textures;
	t_img			*texture;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_map			*map;
	t_map			*destroyed_map;
	t_player		*player;
}					t_mlx;

int					ft_reader(int argc, char *argv, t_map *map);
int					ft_atoi_wolf(char *str, int *i);
int					ft_check_errors(char *str);
int					ft_move_events(int keycode, t_mlx *mlx);
int					ft_key_events(int keycode, t_mlx *mlx);
int					ft_init_player(t_mlx *mlx);
void				ft_calc(t_mlx *mlx, t_player *player);
void				ft_draw_col(t_mlx *mlx, int x);
int					ft_red_cross(t_mlx *mlx);
void				ft_calc_pos_hit(t_ray *ray, t_map *map, t_player *player);
void				ft_calc_weapon_hit(t_mlx *mlx, t_player *player);
void				ft_draw_texture(t_mlx *mlx, t_map *map);
void				ft_draw_sky(t_mlx *mlx);
int					ft_get_initial_color(t_mlx *mlx);
int					ft_find_position(t_mlx *mlx);
void				ft_weapon_handling(t_mlx *mlx);
void				ft_fill_pixel(t_img *img, int x, int y, int color);
int					ft_expose_hook(t_mlx *mlx);
int					ft_mouse_events(int button, int x, int y, t_mlx *mlx);
int					ft_draw_minimap(t_mlx *mlx);
int					ft_key_release(int keycode, t_mlx *mlx);
int					ft_exit_properly(t_mlx *mlx);
void				ft_fill_pixel(t_img *img, int x, int y, int color);
int					ft_init_dmg_walls(t_mlx *mlx);
int					ft_dmg_walls(t_mlx *mlx);
int					ft_big_int_error(t_mlx *mlx);
int					ft_expose_commands(t_mlx *mlx);
int					ft_switch_text_mode(t_mlx *mlx);
int					ft_modif_tex_color(t_mlx *mlx, int y);
int					ft_second_check(t_mlx *mlx);

#endif
