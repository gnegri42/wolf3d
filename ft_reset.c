/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:22:20 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/12 14:22:23 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_reset(t_mlx *mlx)
{
	ft_find_position(mlx);
	mlx->player->dir_x = 1;
	mlx->player->dir_y = 0;
	mlx->player->plane_x = 0;
	mlx->player->plane_y = 0.66;
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

static void ft_reset_offset(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x40FFFFFF);
		while (y < WIN_HEIGHT)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x40FFFFFF);
			y++;
		}
		x++;
	}
	x = 150;
	while (x < WIN_WIDTH / 4 * 3 - 10)
	{
		y = 290;
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x4010448A);
		while (y < WIN_HEIGHT / 2 + 60)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x4010448A);
			y++;
		}
		x++;
	}
	if (i == 0)
		mlx_string_put(mlx->mlx, mlx->win, WIN_WIDTH / 4 + 250, WIN_HEIGHT / 2 + 35, 0xDE5024, "__");
	mlx_string_put(mlx->mlx, mlx->win, WIN_WIDTH / 5, WIN_HEIGHT / 2, 0xDE5024, "ARE YOU SURE YOU WANT TO RESET THE LEVEL ?");
	mlx_string_put(mlx->mlx, mlx->win, WIN_WIDTH / 4 + 60, WIN_HEIGHT / 2 + 30, 0xDE5024, "YES");
	mlx_string_put(mlx->mlx, mlx->win, WIN_WIDTH / 4 + 250, WIN_HEIGHT / 2 + 30, 0xDE5024, "NO");
}

static int	ft_reset_key2(int keycode, t_mlx *mlx)
{
	if (keycode == 36 && mlx->map->reset_validation == 1)
	{
		ft_reset(mlx);
		mlx->map->switch_reset = 0;
		mlx_key_hook(mlx->win, ft_key_events, mlx);
		mlx_hook(mlx->win, 2, 1L << 0, ft_move_events, mlx);
		mlx_hook(mlx->win, 17, 1L << 17, ft_red_cross, mlx);
		return (0);
	}
	if (keycode == 36 && mlx->map->reset_validation == 0)
	{
		mlx->map->switch_reset = 0;
		mlx->map->reset_validation = 0;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		mlx_key_hook(mlx->win, ft_key_events, mlx);
		mlx_hook(mlx->win, 2, 1L << 0, ft_move_events, mlx);
		mlx_hook(mlx->win, 17, 1L << 17, ft_red_cross, mlx);
		return (0);
	}
	return (0);
}

static int	ft_reset_key(int keycode, t_mlx *mlx)
{
	if (keycode == 123 || keycode == 0)
	{
		ft_reset_offset(mlx, 1);
		mlx->map->reset_validation = 1;
		mlx_string_put(mlx->mlx, mlx->win, WIN_WIDTH / 4 + 60, WIN_HEIGHT / 2 + 35, 0xDE5024, "___");
	}
	if (keycode == 124 || keycode == 2)
	{
		ft_reset_offset(mlx, 0);
		mlx->map->reset_validation = 0;
	}
	ft_reset_key2(keycode, mlx);
	return (0);
}

void	ft_ask_reset(t_mlx *mlx)
{
	ft_reset_offset(mlx, 0);
	mlx->map->switch_reset = 1;
	mlx_key_hook(mlx->win, ft_reset_key, mlx);
}