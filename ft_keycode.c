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
#include <stdio.h>
int			ft_key_events(int keycode, t_mlx *mlx)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = mlx->player->dir_x;
	old_dir_y = mlx->player->dir_y;
	old_plane_x = mlx->player->plane_x;
	old_plane_y = mlx->player->plane_y;
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
	{
		if (mlx->map->tab[(int)(mlx->player->pos_x + mlx->player->ray->dir_x * mlx->player->move)][(int)mlx->player->pos_y] == 0)
			mlx->player->pos_x += mlx->player->ray->dir_x * mlx->player->move;
		if (mlx->map->tab[(int)mlx->player->pos_x][(int)(mlx->player->pos_y + mlx->player->ray->dir_y * mlx->player->move)] == 0)
			mlx->player->pos_y += mlx->player->ray->dir_y * mlx->player->move;
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 125)
	{
		if (mlx->map->tab[(int)(mlx->player->pos_x - mlx->player->ray->dir_x * mlx->player->move)][(int)mlx->player->pos_y] == 0)
			mlx->player->pos_x -= mlx->player->ray->dir_x * mlx->player->move;
		if (mlx->map->tab[(int)mlx->player->pos_x][(int)(mlx->player->pos_y - mlx->player->ray->dir_y * mlx->player->move)] == 0)
			mlx->player->pos_y -= mlx->player->ray->dir_y * mlx->player->move;
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 123)
	{
		mlx->player->dir_x = mlx->player->dir_x * cos(mlx->player->turn) - mlx->player->dir_y * sin(mlx->player->turn);
		mlx->player->dir_y = old_dir_x * sin(mlx->player->turn) + mlx->player->dir_y * cos(mlx->player->turn);
		mlx->player->plane_x = mlx->player->plane_x * cos(mlx->player->turn) - mlx->player->plane_y * sin(mlx->player->turn);
		mlx->player->plane_y = old_plane_x * sin(mlx->player->turn) + mlx->player->plane_y * cos(mlx->player->turn);
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 124)
	{
		mlx->player->dir_x = mlx->player->dir_x * cos(-mlx->player->turn) - mlx->player->dir_y * sin(-mlx->player->turn);
		mlx->player->dir_y = old_dir_x * sin(-mlx->player->turn) + mlx->player->dir_y * cos(-mlx->player->turn);
		mlx->player->plane_x = mlx->player->plane_x * cos(-mlx->player->turn) - mlx->player->plane_y * sin(-mlx->player->turn);
		mlx->player->plane_y = old_plane_x * sin(-mlx->player->turn) + mlx->player->plane_y * cos(-mlx->player->turn);
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	return (0);
}
