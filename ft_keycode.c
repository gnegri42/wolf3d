/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:54:34 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/09 11:54:42 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_expose_hook(t_mlx *mlx)
{
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

static int	ft_switch_tex(t_mlx *mlx)
{
	if (mlx->map->switch_tex == 0)
	{
		mlx->map->switch_tex = 1;
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
		return (0);
	}
	else
		mlx->map->switch_tex = 0;
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

static void	ft_reset_and_map(int keycode, t_mlx *mlx)
{
	if (keycode == 51)
	{
		ft_find_position(mlx);
		mlx->player->dir_x = 1;
		mlx->player->dir_y = 0;
		mlx->player->plane_x = 0;
		mlx->player->plane_y = 0.66;
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 46)
	{
		if (mlx->map->show_map == 0)
			mlx->map->show_map = 1;
		else
			mlx->map->show_map = 0;
	}
}

int			ft_red_cross(t_mlx *mlx)
{
	ft_exit_properly(mlx);
	exit(0);
	return (0);
}

int			ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		ft_exit_properly(mlx);
		exit(1);
	}
	if (keycode == 126 || keycode == 13 || keycode == 125 ||
		keycode == 1 || keycode == 124 || keycode == 2 ||
		keycode == 123 || keycode == 0)
		ft_move_events(keycode, mlx);
	if (keycode == 17)
		ft_switch_tex(mlx);
	if (keycode == 51 || keycode == 46)
		ft_reset_and_map(keycode, mlx);
	if (keycode == 257)
	{
		mlx->player->move = 0.5;
		mlx->player->turn = 0.25;
	}
	return (0);
}
