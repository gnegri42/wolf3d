/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:59:03 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/15 16:59:05 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	display_weapon(t_mlx *mlx, int state)
{
	int x;
	int y;
	int countx;
	int county;
	int resize;

	if (WIN_WIDTH > 500 && WIN_HEIGHT > 250)
		resize = 1;
	else
		resize = 2;
	y = WIN_HEIGHT - (256 / resize);
	county = 0;
	while (y < WIN_HEIGHT)
	{
		countx = 0;
		x = WIN_WIDTH / 2 - 30;
		while (x < WIN_WIDTH / 2 + (256 / resize))
		{
			if (mlx->map->texture[state].str_img[countx + county * 128] != 0x980088)
			{
				ft_fill_pixel(mlx->img, x, y, mlx->map->texture[state].str_img[countx + county * 128]);
				if (WIN_WIDTH > 500 && WIN_HEIGHT > 250)
				{
					ft_fill_pixel(mlx->img, x + 1, y, mlx->map->texture[state].str_img[countx + county * 128]);
					ft_fill_pixel(mlx->img, x, y + 1, mlx->map->texture[state].str_img[countx + county * 128]);
					ft_fill_pixel(mlx->img, x + 1, y + 1, mlx->map->texture[state].str_img[countx + county * 128]);
				}
			}
			if (WIN_WIDTH > 500 && WIN_HEIGHT > 250)
				x += 2;
			else
				x++;
			countx++;
		}
		if (WIN_WIDTH > 500 && WIN_HEIGHT > 250)
			y += 2;
		else
			y++;
		county++;
	}
}

void	ft_weapon_handling(t_mlx *mlx)
{
	if (mlx->player->shoot == 1)
	{
		mlx->player->weapon++;
		ft_calc_weapon_hit(mlx, mlx->player);
	}
	if (mlx->player->weapon > 4)
	{
		mlx->player->weapon = 0;
		mlx->player->shoot = 0;
	}
	if (mlx->map->tex_hit > 1 && mlx->player->ray->texture_num < 7 && mlx->player->weapon == 1)
	{
			mlx->map->tex_change += 1;
			printf("%d\n", mlx->map->tex_hit);
	}
	display_weapon(mlx, mlx->player->weapon + 7);
}
