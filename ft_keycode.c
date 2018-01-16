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

int		ft_expose_hook(t_mlx *mlx)
{
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}

static int ft_switch_tex(t_mlx *mlx)
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

static void    ft_reset(t_mlx *mlx)
{
       ft_find_position(mlx);
       mlx->player->dir_x = 1;
       mlx->player->dir_y = 0;
       mlx->player->plane_x = 0;
       mlx->player->plane_y = 0.66;
       ft_calc(mlx, mlx->player);
       mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

int		ft_red_cross(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	exit(0);
	return (0);
}

int		ft_key_events(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->img);
		exit(1);
	}
	if (keycode == 17)
		ft_switch_tex(mlx);
	if (keycode == 51)
		ft_reset(mlx);
	if (keycode == 257)
		{
			mlx->player->move = 0.5;
			mlx->player->turn = 0.25;
		}
	return (0);
}
