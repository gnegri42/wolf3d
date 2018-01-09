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

static void		ft_fill_pixel(t_img *img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img->str_img[i] = color;
}

void			ft_draw_col(t_mlx *mlx, int x, int color)
{
	int		i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		if (i >= mlx->map->pixel_start && i <= mlx->map->pixel_last)
			ft_fill_pixel(mlx->img, x, i, color);
		else
			ft_fill_pixel(mlx->img, x, i, BLACK);
		i++;
	}
}
