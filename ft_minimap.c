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

static void	ft_draw_square(t_mlx *mlx, int init_x, int init_y, int size, int color)
{
	int x;
	int y;

	y = size * 2 + size * init_y;
	while (y < size * 2 + (size * (init_y + 1)))
	{
		x = size * 2 + size * init_x;
		while (x < size * 2 + (size * (init_x + 1)))
		{
			ft_fill_pixel(mlx->img, x, y, color);
			x++;
		}
		y++;
	}
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
				ft_draw_square(mlx, init_y, init_x, size, WHITE);
			init_y++;
		}
		init_x++;
	}
	init_x = mlx->player->pos_x;
	init_y = mlx->player->pos_y + 0.5;
	if (mlx->map->tab[(int)mlx->player->pos_y][(int)mlx->player->pos_x] != 1)
		ft_draw_square(mlx, init_x, init_y, size, ORANGE);
	else
		ft_draw_square(mlx, init_x, init_y - 1, size, ORANGE);
	return (0);
}
