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

/*
void		ft_calc_floor(t_mlx *mlx, t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
	{
		ray->floor_pos_x = mlx->player->map_x;	
		ray->floor_pos_y = mlx->player->map_y + ray->wall_hit;
	}
	else if (ray->side == 0 && ray->dir_x < 0)
	{
		ray->floor_pos_x = mlx->player->map_x + 1.0;	
		ray->floor_pos_y = mlx->player->map_y + ray->wall_hit;
	}
	else if (ray->side == 1 && ray->dir_y > 0)
	{
		ray->floor_pos_x = mlx->player->map_x + ray->wall_hit;	
		ray->floor_pos_y = mlx->player->map_y;
	}
	else
	{
		ray->floor_pos_x = mlx->player->map_x + ray->wall_hit;	
		ray->floor_pos_y = mlx->player->map_y + 1.0;
	}
	ray->wall_dist_bottom = ray->wall_dist;
	mlx->player->dist = 0;
	if (mlx->map->pixel_last < 0)
		mlx->map->pixel_last = WIN_HEIGHT;
}
*/
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

static void	ft_draw_texture3(t_mlx *mlx, t_map *map, int a, int b)
{
	a = 128;
	b = 128;
	map->texture[7].img = mlx_xpm_file_to_image(mlx->mlx, "textures/pistol1.xpm", &a, &b);
	map->texture[7].str_img = (int *)mlx_get_data_addr(map->texture[7].img, &map->texture[7].bpp,
			&map->texture[7].s_l, &map->texture[7].endian);
	map->texture[8].img = mlx_xpm_file_to_image(mlx->mlx, "textures/pistol2.xpm", &a, &b);
	map->texture[8].str_img = (int *)mlx_get_data_addr(map->texture[8].img, &map->texture[8].bpp,
			&map->texture[8].s_l, &map->texture[8].endian);
	map->texture[9].img = mlx_xpm_file_to_image(mlx->mlx, "textures/pistol3.xpm", &a, &b);
	map->texture[9].str_img = (int *)mlx_get_data_addr(map->texture[9].img, &map->texture[9].bpp,
			&map->texture[9].s_l, &map->texture[9].endian);
	map->texture[10].img = mlx_xpm_file_to_image(mlx->mlx, "textures/pistol4.xpm", &a, &b);
	map->texture[10].str_img = (int *)mlx_get_data_addr(map->texture[10].img, &map->texture[10].bpp,
			&map->texture[10].s_l, &map->texture[10].endian);
	map->texture[11].img = mlx_xpm_file_to_image(mlx->mlx, "textures/pistol5.xpm", &a, &b);
	map->texture[11].str_img = (int *)mlx_get_data_addr(map->texture[11].img, &map->texture[11].bpp,
			&map->texture[11].s_l, &map->texture[11].endian);
}

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
	map->texture[0].img = mlx_xpm_file_to_image(mlx->mlx, "textures/emerald_block.xpm", &a, &b);
	map->texture[0].str_img = (int *)mlx_get_data_addr(map->texture[0].img, &map->texture[0].bpp,
			&map->texture[0].s_l, &map->texture[0].endian);
	map->texture[1].img = mlx_xpm_file_to_image(mlx->mlx, "textures/bookshelf.xpm", &a, &b);
	map->texture[1].str_img = (int *)mlx_get_data_addr(map->texture[1].img, &map->texture[1].bpp,
			&map->texture[1].s_l, &map->texture[1].endian);
	map->texture[2].img = mlx_xpm_file_to_image(mlx->mlx, "textures/daylight_detector_top.xpm", &a, &b);
	map->texture[2].str_img = (int *)mlx_get_data_addr(map->texture[2].img, &map->texture[2].bpp,
			&map->texture[2].s_l, &map->texture[2].endian);
	map->texture[3].img = mlx_xpm_file_to_image(mlx->mlx,
			"textures/door_iron_lower.xpm", &a, &b);
	map->texture[3].str_img = (int *)mlx_get_data_addr(map->texture[3].img, &map->texture[3].bpp,
			&map->texture[3].s_l, &map->texture[3].endian);
	map->texture[4].img = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &a, &b);
	map->texture[4].str_img = (int *)mlx_get_data_addr(map->texture[4].img, &map->texture[4].bpp,
			&map->texture[4].s_l, &map->texture[4].endian);
	ft_draw_texture2(mlx, map, a, b);
	ft_draw_texture3(mlx, map, a, b);
}
