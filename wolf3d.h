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

# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500

typedef struct		s_map
{
	int				nb_line;
	int				nb_int;
	char			*str;
	char			**content;
	int				**tab;
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
}					t_mlx;

int			ft_reader(int argc, char *argv, t_map *map);
int			ft_atoi_wolf(char *str, int *i);
int			ft_check_errors(char *str);
int			ft_key_events(int keycode);

#endif
