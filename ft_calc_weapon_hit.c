/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_weapon_hit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:36:33 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/16 17:36:35 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ray_cal_dist_weapon_hit2(t_player *player, t_ray *ray, t_map *map)
{
	ray->hit = 1;
	if (ray->side == 0)
		ray->wall_dist = (player->map_x - ray->pos_x + (1 - ray->step_x)
				/ 2) / ray->dir_x;
	else
		ray->wall_dist = (player->map_y - ray->pos_y + (1 - ray->step_y)
				/ 2) / ray->dir_y;
	map->tex_hit = map->tab[player->map_x][player->map_y];
}

static void	ray_cal_dist_weapon_hit(t_player *player, t_ray *ray, t_map *map)
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
			ray_cal_dist_weapon_hit2(player, ray, map);
		}
	}
}

static void	ray_cal_step_side_weapon_hit(t_ray *ray)
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

static void	ray_init_weapon_hit(t_player *player, t_ray *ray, int x)
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

void		ft_calc_weapon_hit(t_mlx *mlx, t_player *player)
{
	int		x;

	x = 0;
	if (player && mlx)
		x = WIN_WIDTH / 2;
	ray_init_weapon_hit(player, mlx->player->ray, x);
	ray_cal_step_side_weapon_hit(mlx->player->ray);
	ray_cal_dist_weapon_hit(player, mlx->player->ray, mlx->map);
}
