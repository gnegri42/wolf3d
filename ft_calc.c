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

static void	ft_find_wall(t_mlx *mlx, t_map *map, t_player *player, t_ray *ray)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray->hit = 0;
		player->camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray->pos_x = player->pos_x;
		ray->pos_y = player->pos_y;
		ray->dir_x = player->dir_x + player->plane_x * player->camera_x;
		ray->dir_y = player->dir_y + player->plane_y * player->camera_x;
		player->map_x = (int)ray->pos_x;
		player->map_y = (int)ray->pos_y;
		ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) / (ray->dir_x * ray->dir_x));
		ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) / (ray->dir_y * ray->dir_y));
		if (ray->dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (ray->pos_x - player->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (player->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
		}
		if (ray->dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (ray->pos_y - player->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (player->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
		}
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
					ray->wall_dist = (player->map_x - ray->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
				else
					ray->wall_dist = (player->map_y - ray->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
			}
			map->line_height = WIN_HEIGHT / (double)ray->wall_dist;
			map->pixel_start = -map->line_height / 2 + WIN_HEIGHT / 2;
			if (map->pixel_start < 0)
				map->pixel_start = 0;
			map->pixel_last = map->line_height / 2 + WIN_HEIGHT / 2;
			if (map->pixel_last >= WIN_HEIGHT)
				map->pixel_last = WIN_HEIGHT - 1;
			ft_draw_col(mlx, x, ORANGE);
		}
		x++;
	}
}

void		ft_calc(t_mlx *mlx, t_player *player)
{
	ft_find_wall(mlx, mlx->map, mlx->player, player->ray);
}
