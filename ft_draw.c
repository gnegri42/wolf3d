/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:46:37 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/09 15:46:38 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			ft_fill_pixel(t_img *img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img->str_img[i] = color;
}

static unsigned int	ft_get_color(t_mlx *mlx)
{
	if (mlx->player->ray->side == 1)
	{
		if ((mlx->player->ray->step_x == -1 &&
			mlx->player->ray->step_y == -1) ||
			(mlx->player->ray->step_x == 1 && mlx->player->ray->step_y == -1))
			return (ORANGE);
		if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1) ||
			(mlx->player->ray->step_x == 1 && mlx->player->ray->step_y == 1))
			return (WHITE);
	}
	if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == -1) ||
		(mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1))
		return (GREEN);
	return (0x0441FF);
}

void				ft_draw_col(t_mlx *mlx, int x)
{
	int		i;
	int		color;

	color = ft_get_color(mlx);
	i = 0;
	while (i++ < mlx->map->pixel_start)
		ft_fill_pixel(mlx->img, x, i, BLUE);
	while (i++ <= mlx->map->pixel_last)
		ft_fill_pixel(mlx->img, x, i, color);
	while (i++ < WIN_HEIGHT)
		ft_fill_pixel(mlx->img, x, i, BLACK);
}
