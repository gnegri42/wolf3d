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
		if (mlx->map->tab[(int)(mlx->player->pos_x + mlx->player->ray->dir_x)][(int)mlx->player->pos_y] == 0)
			mlx->player->pos_x += mlx->player->ray->dir_x;
		if (mlx->map->tab[(int)mlx->player->pos_x][(int)(mlx->player->pos_y + mlx->player->ray->dir_y)] == 0)
			mlx->player->pos_y += mlx->player->ray->dir_y;
		printf("x :%f\n", mlx->player->pos_x);
		printf("y :%f\n", mlx->player->pos_y);
		printf("ray x :%f\n", mlx->player->ray->dir_x);
		printf("ray y :%f\n", mlx->player->ray->dir_y);
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 125)
	{
		if (mlx->map->tab[(int)(mlx->player->pos_x - mlx->player->ray->dir_x)][(int)mlx->player->pos_y] == 0)
			mlx->player->pos_x -= mlx->player->ray->dir_x;
		if (mlx->map->tab[(int)mlx->player->pos_x][(int)(mlx->player->pos_y - mlx->player->ray->dir_y)] == 0)
			mlx->player->pos_y -= mlx->player->ray->dir_y;
		printf("x :%f\n", mlx->player->pos_x);
		printf("y :%f\n", mlx->player->pos_y);
		printf("ray x :%f\n", mlx->player->ray->dir_x);
		printf("ray y :%f\n", mlx->player->ray->dir_y);
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 123)
	{
		mlx->player->dir_x = mlx->player->dir_x * cos(1.5708) - mlx->player->dir_y * sin(1.5708);
		mlx->player->dir_y = old_dir_x * sin(1.5708) + mlx->player->dir_y * cos(1.5708);
		mlx->player->plane_x = mlx->player->plane_x * cos(1.5708) - mlx->player->plane_y * sin(1.5708);
		mlx->player->plane_y = old_plane_x * sin(1.5708) + mlx->player->plane_y * cos(1.5708);
		printf("x :%f\n", mlx->player->pos_x);
		printf("y :%f\n", mlx->player->pos_y);
		printf("ray x :%f\n", mlx->player->ray->dir_x);
		printf("ray y :%f\n", mlx->player->ray->dir_y);
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	if (keycode == 124)
	{
		mlx->player->dir_x = mlx->player->dir_x * cos(-1.5708) - mlx->player->dir_y * sin(-1.5708);
		mlx->player->dir_y = old_dir_x * sin(-1.5708) + mlx->player->dir_y * cos(-1.5708);
		mlx->player->plane_x = mlx->player->plane_x * cos(-1.5708) - mlx->player->plane_y * sin(-1.5708);
		mlx->player->plane_y = old_plane_x * sin(-1.5708) + mlx->player->plane_y * cos(-1.5708);
		printf("x :%f\n", mlx->player->pos_x);
		printf("y :%f\n", mlx->player->pos_y);
		printf("ray x :%f\n", mlx->player->ray->dir_x);
		printf("ray y :%f\n", mlx->player->ray->dir_y);
		ft_calc(mlx, mlx->player);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	}
	return (0);
}
