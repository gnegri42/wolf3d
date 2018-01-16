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

static void	display_weapon(t_mlx *mlx, int state)
{
	int x;
	int y;
	int countx;
	int county;

	y = WIN_HEIGHT - 256;
	county = 0;
	while (y < WIN_HEIGHT)
	{
		countx = 0;
		x = WIN_WIDTH / 2 - 30;
		while (x < WIN_WIDTH / 2 + 256)
		{
			if (mlx->map->texture[state].str_img[countx + county * 128] != 0x980088)
			{
				ft_fill_pixel(mlx->img, x, y, mlx->map->texture[state].str_img[countx + county * 128]);
				ft_fill_pixel(mlx->img, x + 1, y, mlx->map->texture[state].str_img[countx + county * 128]);
				ft_fill_pixel(mlx->img, x, y + 1, mlx->map->texture[state].str_img[countx + county * 128]);
				ft_fill_pixel(mlx->img, x + 1, y + 1, mlx->map->texture[state].str_img[countx + county * 128]);
			}
			x += 2;
			countx++;
		}
		y += 2;
		county++;
	}
}

void	ft_weapon_handling(t_mlx *mlx)
{
	if (mlx->player->shoot == 1)
		mlx->player->wpstate++;
	if (mlx->player->wpstate > 4)
	{
		mlx->player->wpstate = 0;
		mlx->player->shoot = 0;
	}
	display_weapon(mlx, mlx->player->wpstate + 7);
}
