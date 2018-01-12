/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:34:29 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/10 18:34:32 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_move_up(t_mlx *mlx)
{
	if (mlx->map->tab[(int)(mlx->player->pos_x + mlx->player->dir_x *
		mlx->player->move)][(int)mlx->player->pos_y] == 0)
		mlx->player->pos_x += mlx->player->dir_x * mlx->player->move;
	if (mlx->map->tab[(int)mlx->player->pos_x][(int)(mlx->player->pos_y +
		mlx->player->dir_y * mlx->player->move)] == 0)
		mlx->player->pos_y += mlx->player->dir_y * mlx->player->move;
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

static void	ft_move_down(t_mlx *mlx)
{
	if (mlx->map->tab[(int)(mlx->player->pos_x - mlx->player->dir_x *
		mlx->player->move)][(int)mlx->player->pos_y] == 0)
		mlx->player->pos_x -= mlx->player->dir_x * mlx->player->move;
	if (mlx->map->tab[(int)mlx->player->pos_x][(int)(mlx->player->pos_y
		- mlx->player->dir_y * mlx->player->move)] == 0)
		mlx->player->pos_y -= mlx->player->dir_y * mlx->player->move;
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

static void	ft_rotate_right(t_mlx *mlx)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = mlx->player->dir_x;
	old_plane_x = mlx->player->plane_x;
	mlx->player->dir_x = mlx->player->dir_x * cos(mlx->player->turn) -
	mlx->player->dir_y * sin(mlx->player->turn);
	mlx->player->dir_y = old_dir_x * sin(mlx->player->turn) +
	mlx->player->dir_y * cos(mlx->player->turn);
	mlx->player->plane_x = mlx->player->plane_x * cos(mlx->player->turn)
	- mlx->player->plane_y * sin(mlx->player->turn);
	mlx->player->plane_y = old_plane_x * sin(mlx->player->turn) +
	mlx->player->plane_y * cos(mlx->player->turn);
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

static void	ft_rotate_left(t_mlx *mlx)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = mlx->player->dir_x;
	old_plane_x = mlx->player->plane_x;
	mlx->player->dir_x = mlx->player->dir_x * cos(-mlx->player->turn) -
	mlx->player->dir_y * sin(-mlx->player->turn);
	mlx->player->dir_y = old_dir_x * sin(-mlx->player->turn) +
	mlx->player->dir_y * cos(-mlx->player->turn);
	mlx->player->plane_x = mlx->player->plane_x * cos(-mlx->player->turn) -
	mlx->player->plane_y * sin(-mlx->player->turn);
	mlx->player->plane_y = old_plane_x * sin(-mlx->player->turn) +
	mlx->player->plane_y * cos(-mlx->player->turn);
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

int			ft_move_events(int keycode, t_mlx *mlx)
{
	if (keycode == 126 || keycode == 13)
		ft_move_up(mlx);
	if (keycode == 125 || keycode == 1)
		ft_move_down(mlx);
	if (keycode == 124 || keycode == 2)
		ft_rotate_right(mlx);
	if (keycode == 123 || keycode == 0)
		ft_rotate_left(mlx);
	return (0);
}
