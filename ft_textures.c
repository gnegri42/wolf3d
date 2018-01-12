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

static void	ft_draw_texture2(t_mlx *mlx, t_map *map, int a, int b)
{
	map->texture[5].img = mlx_xpm_file_to_image(mlx->mlx, "textures/sand.xpm", &a, &b);
	map->texture[5].str_img = (int *)mlx_get_data_addr(map->texture[5].img, &map->texture[5].bpp,
			&map->texture[5].s_l, &map->texture[5].endian);
	a = 512;
	b = 512;
	map->texture[6].img = mlx_xpm_file_to_image(mlx->mlx, "textures/sky.xpm", &a, &b);
	map->texture[6].str_img = (int *)mlx_get_data_addr(map->texture[6].img, &map->texture[6].bpp,
			&map->texture[6].s_l, &map->texture[6].endian);
}

void		ft_draw_texture(t_mlx *mlx, t_map *map)
{
	int 	a;
	int		b;

	a = 64;
	b = 64;
	map->texture[0].img = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &a, &b);
	map->texture[0].str_img = (int *)mlx_get_data_addr(map->texture[0].img, &map->texture[0].bpp,
			&map->texture[0].s_l, &map->texture[0].endian);
	map->texture[1].img = mlx_xpm_file_to_image(mlx->mlx, "textures/stone.xpm", &a, &b);
	map->texture[1].str_img = (int *)mlx_get_data_addr(map->texture[1].img, &map->texture[1].bpp,
			&map->texture[1].s_l, &map->texture[1].endian);
	map->texture[2].img = mlx_xpm_file_to_image(mlx->mlx, "textures/mossy.xpm", &a, &b);
	map->texture[2].str_img = (int *)mlx_get_data_addr(map->texture[2].img, &map->texture[2].bpp,
			&map->texture[2].s_l, &map->texture[2].endian);
	map->texture[3].img = mlx_xpm_file_to_image(mlx->mlx,
			"textures/redbrick.xpm", &a, &b);
	map->texture[3].str_img = (int *)mlx_get_data_addr(map->texture[3].img, &map->texture[3].bpp,
			&map->texture[3].s_l, &map->texture[3].endian);
	map->texture[4].img = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &a, &b);
	map->texture[4].str_img = (int *)mlx_get_data_addr(map->texture[4].img, &map->texture[4].bpp,
			&map->texture[4].s_l, &map->texture[4].endian);
	ft_draw_texture2(mlx, map, a, b);
}

void		ft_calc_pos_hit(t_ray *ray, t_map *map, t_player *player)
{
	ray->texture_num = map->tab[player->map_x][player->map_y] - 1;
	if (ray->side == 0)
		ray->wall_hit = ray->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = ray->pos_x + ray->wall_dist * ray->dir_x;
	ray->texture_coord = (int)(ray->wall_hit * (double)(TEXTURE_WIDTH));
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		ray->texture_coord = TEXTURE_WIDTH - ray->texture_coord - 1;
	ray->texture_coord = abs(ray->texture_coord);
}
