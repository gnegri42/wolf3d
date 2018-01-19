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

static void	display_weapon_loop(t_mlx *mlx, int state)
{
	if (WIN_WIDTH > 500 && WIN_HEIGHT > 250)
	{
		ft_fill_pixel(mlx->img, mlx->player->weapon_x,
			mlx->player->weapon_y, mlx->map->texture[state].
			str_img[mlx->player->count_x + mlx->player->count_y * 128]);
		ft_fill_pixel(mlx->img, mlx->player->weapon_x + 1,
			mlx->player->weapon_y, mlx->map->texture[state].str_img
			[mlx->player->count_x + mlx->player->count_y * 128]);
		ft_fill_pixel(mlx->img, mlx->player->weapon_x,
			mlx->player->weapon_y + 1, mlx->map->texture[state].
			str_img[mlx->player->count_x +
				mlx->player->count_y * 128]);
		ft_fill_pixel(mlx->img, mlx->player->weapon_x + 1,
			mlx->player->weapon_y + 1, mlx->map->texture[state].
			str_img[mlx->player->count_x +
				mlx->player->count_y * 128]);
	}
}

static void	display_weapon(t_mlx *mlx, int state)
{
	mlx->player->weapon_y = WIN_HEIGHT - (256 / mlx->map->resize);
	mlx->player->count_y = 0;
	while (mlx->player->weapon_y < WIN_HEIGHT)
	{
		mlx->player->count_x = 0;
		mlx->player->weapon_x = WIN_WIDTH / 2 - 30;
		while (mlx->player->weapon_x < WIN_WIDTH / 2 + (256 / mlx->map->resize))
		{
			if (mlx->map->texture[state].str_img[mlx->player->count_x +
				mlx->player->count_y * 128] != 0x980088)
			{
				display_weapon_loop(mlx, state);
			}
			mlx->player->weapon_x += mlx->player->pas;
			mlx->player->count_x++;
		}
		mlx->player->weapon_y += mlx->player->pas;
		mlx->player->count_y++;
	}
}

static void	display_init_weapon(t_mlx *mlx, int state)
{
	int pas;

	pas = 0;
	if (WIN_WIDTH > 500 && WIN_HEIGHT > 250)
		mlx->player->pas = 2;
	else
		mlx->player->pas = 1;
	display_weapon(mlx, state);
}

void		ft_weapon_handling(t_mlx *mlx)
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
	display_init_weapon(mlx, mlx->player->weapon + 7);
}
