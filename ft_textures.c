/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:14:42 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/11 10:14:44 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_texture(t_map *map, t_ray *ray)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	ray->nb_max_texture = 4;
	map->texture = (int **)malloc(sizeof(int *) * ray->nb_max_texture + 1);
	while (i < ray->nb_max_texture)
	{
		map->texture[i] = (int *)malloc(sizeof(int) * TEXTURE_WIDTH * TEXTURE_HEIGHT);
		i++;
	}
	while (x < TEXTURE_WIDTH)
	{
		while (y < TEXTURE_HEIGHT)
		{
			ray->tex_col->col_x = (x * 256 / TEXTURE_WIDTH) ^ (y * 256 / TEXTURE_HEIGHT);
			ray->tex_col->col_y = 256 / TEXTURE_HEIGHT;
			ray->tex_col->col_xy = y * 128 / TEXTURE_HEIGHT + x * 128 / TEXTURE_WIDTH;
			map->texture[0][TEXTURE_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEXTURE_WIDTH - y);
			map->texture[1][TEXTURE_WIDTH * y + x] = ray->tex_col->col_xy + 256 * ray->tex_col->col_xy + 65536 * ray->tex_col->col_xy;
			map->texture[2][TEXTURE_WIDTH * y + x] = 256 * ray->tex_col->col_xy + 65536 * ray->tex_col->col_xy;
			map->texture[3][TEXTURE_WIDTH * y + x] = ray->tex_col->col_x + 256 * ray->tex_col->col_x + 65536 * ray->tex_col->col_x;
			y++;
		}
		x++;
	}
}

void	ft_calc_pos_hit(t_ray *ray, t_map *map, t_player *player)
{
	ray->texture_num = map->tab[player->map_x][player->map_y] - 1;
	if (ray->side == 0)
		ray->wall_hit = ray->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = ray->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_hit -= floor(ray->wall_hit);
	ray->texture_coord = (int)(ray->wall_hit * (double)(TEXTURE_WIDTH));
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		ray->texture_coord = TEXTURE_WIDTH - ray->texture_coord - 1;
}
