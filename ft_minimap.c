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

	y = size * 2 + size * init_y;
	while (y < size * 2 + (size * (init_y + 1)))
	{
		x = size * 2 + size * init_x;
		while (x < size * 2 + (size * (init_x + 1)))
		{
			ft_fill_pixel(mlx->img, x, y, mlx->map->color_minimap);
			x++;
		}
		y++;
	}
}

static void	ft_draw_minimap2(t_mlx *mlx, int init_x, int init_y, int size)
{
	init_x = mlx->player->pos_x;
	init_y = mlx->player->pos_y + 0.5;
	mlx->map->color_minimap = ORANGE;
	if (mlx->map->tab[(int)mlx->player->pos_y][(int)mlx->player->pos_x] != 1)
		ft_draw_square(mlx, init_x, init_y, size);
	else
		ft_draw_square(mlx, init_x, init_y - 1, size);
}

int			ft_draw_minimap(t_mlx *mlx)
{
	int		init_x;
	int		init_y;
	int		size;

	size = WIN_WIDTH / 10 / mlx->map->nb_int;
	init_x = 0;
	while (init_x < mlx->map->nb_int)
	{
		init_y = 0;
		while (init_y < mlx->map->nb_line)
		{
			if (mlx->map->tab[init_y][init_x] > 0)
			{
				mlx->map->color_minimap = WHITE;
				ft_draw_square(mlx, init_y, init_x, size);
			}
			init_y++;
		}
		init_x++;
	}
	ft_draw_minimap2(mlx, init_x, init_y, size);
	return (0);
}
