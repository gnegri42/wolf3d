/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:30:42 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/12 12:30:44 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_draw_square(t_mlx *mlx, int init_x, int init_y, int size)
{
	int x;
	int y;

	y = size * init_y;
	while (y < (size * (init_y + 1)))
	{
		x = size * init_x;
		while (x < (size * (init_x + 1)))
		{
			ft_fill_pixel(mlx->img, x, y, mlx->map->color_minimap);
			x++;
		}
		y++;
	}
}

static void	ft_draw_player_pos(t_mlx *mlx, int init_x, int init_y, int size)
{
	init_x = mlx->player->pos_x;
	init_y = mlx->player->pos_y;
	init_x = init_x % 20;
	init_y = init_y % 20;
	mlx->map->color_minimap = ORANGE;
	ft_draw_square(mlx, init_x, init_y, size);
}

static void	ft_draw_minimap3(t_mlx *mlx, int init_y, int size)
{
	int x1;
	int y1;

	if (mlx->player->pos_x > 20 || mlx->player->pos_y > 20)
	{
		x1 = 0;
		while (x1 < mlx->map->nb_int && x1 < 20)
		{
			y1 = 0;
			while (y1 + init_y < mlx->map->nb_line && y1 < 20)
			{
				if (mlx->map->tab[init_y + y1][x1] > 0)
				{
					mlx->map->color_minimap = WHITE;
					ft_draw_square(mlx, y1, x1, size);
				}
				y1++;
			}
			x1++;
		}
	}
}

static void	ft_draw_minimap2(t_mlx *mlx, int init_x, int size)
{
	int x1;
	int y1;

	if (mlx->player->pos_x > 20 || mlx->player->pos_y > 20)
	{
		x1 = 0;
		while (x1 + init_x < mlx->map->nb_int && x1 < 20)
		{
			y1 = 0;
			while (y1 < mlx->map->nb_line && y1 < 20)
			{
				if (mlx->map->tab[y1][init_x + x1] > 0)
				{
					mlx->map->color_minimap = WHITE;
					ft_draw_square(mlx, y1, x1, size);
				}
				y1++;
			}
			x1++;
		}
	}
}

int			ft_draw_minimap(t_mlx *mlx)
{
	int		init_x;
	int		init_y;
	int		size;

	size = WIN_WIDTH / 5 / mlx->map->nb_int;
	init_x = 0;
	init_y = 0;
	while (init_x < mlx->map->nb_int && init_x < 20)
	{
		init_y = 0;
		while (init_y < mlx->map->nb_line && init_y < 20)
		{
			if (mlx->map->tab[init_y][init_x] > 0)
			{
				if (mlx->player->pos_x < 20 && mlx->player->pos_y < 20)
				{
					mlx->map->color_minimap = WHITE;
					ft_draw_square(mlx, init_y, init_x, size);
				}					
			}
			init_y++;
		}
		init_x++;
	}
	if (init_y >= mlx->map->nb_line && init_x <= mlx->map->nb_int)
		ft_draw_minimap2(mlx, init_x, size);
	else if (init_x >= mlx->map->nb_int && init_y <= mlx->map->nb_line)
		ft_draw_minimap3(mlx, init_y, size);
	ft_draw_player_pos(mlx, init_x, init_y, size);
	return (0);
}
