/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:44:16 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/09 14:44:17 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ray_draw(t_mlx *mlx, int x)
{
	mlx->map->line_height = (int)(WIN_HEIGHT / mlx->player->ray->wall_dist);
	mlx->map->pixel_start = -mlx->map->line_height / 2 + WIN_HEIGHT / 2;
	if (mlx->map->pixel_start < 0)
		mlx->map->pixel_start = 0;
	mlx->map->pixel_last = mlx->map->line_height / 2 + WIN_HEIGHT / 2;
	if (mlx->map->pixel_last >= WIN_HEIGHT)
		mlx->map->pixel_last = WIN_HEIGHT - 1;
	ft_calc_pos_hit(mlx->player->ray, mlx->map, mlx->player);
	ft_draw_col(mlx, x);
}

static void	ray_cal_dist(t_player *player, t_ray *ray, t_map *map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			player->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			player->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->tab[player->map_x][player->map_y] > 0)
		{
			ray->hit = 1;
			if (ray->side == 0)
				ray->wall_dist = (player->map_x - ray->pos_x + (1 - ray->step_x)
						/ 2) / ray->dir_x;
			else
				ray->wall_dist = (player->map_y - ray->pos_y + (1 - ray->step_y)
						/ 2) / ray->dir_y;
		}
	}
}

static void	ray_cal_step_side(t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - (int)ray->pos_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)ray->pos_x + 1 - ray->pos_x)
		* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - (int)ray->pos_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)ray->pos_y + 1 - ray->pos_y)
		* ray->delta_dist_y;
	}
}

static void	ray_init(t_player *player, t_ray *ray, int x)
{
	player->map_x = (int)ray->pos_x;
	player->map_y = (int)ray->pos_y;
	player->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * player->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * player->camera_x;
	ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) /
			(ray->dir_x * ray->dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) /
			(ray->dir_y * ray->dir_y));
	ray->hit = 0;
	ray->side = -1;
}

void		ft_calc(t_mlx *mlx, t_player *player)
{
	int		x;

	x = -1;
	mlx->player->ray->pos_x = player->pos_x;
	mlx->player->ray->pos_y = player->pos_y;
	if (mlx->map->switch_tex == 0)
		ft_draw_sky(mlx);
	while (++x < WIN_WIDTH)
	{
		ray_init(player, mlx->player->ray, x);
		ray_cal_step_side(mlx->player->ray);
		ray_cal_dist(player, mlx->player->ray, mlx->map);
		ray_draw(mlx, x);
	}
	ft_weapon_handling(mlx);
}
