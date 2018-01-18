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

static void	ft_draw_texture_crackel_2(t_mlx *mlx, t_map *map, int a, int b)
{
	map->texture[18].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_6.xpm", &a, &b);
	map->texture[18].str_img = (int *)mlx_get_data_addr(map->texture[18].img,
		&map->texture[18].bpp, &map->texture[18].s_l, &map->texture[18].endian);
	map->texture[19].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_7.xpm", &a, &b);
	map->texture[19].str_img = (int *)mlx_get_data_addr(map->texture[19].img,
		&map->texture[19].bpp, &map->texture[19].s_l, &map->texture[19].endian);
	map->texture[20].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_8.xpm", &a, &b);
	map->texture[20].str_img = (int *)mlx_get_data_addr(map->texture[20].img,
		&map->texture[20].bpp, &map->texture[20].s_l, &map->texture[20].endian);
	map->texture[21].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_9.xpm", &a, &b);
	map->texture[21].str_img = (int *)mlx_get_data_addr(map->texture[21].img,
		&map->texture[21].bpp, &map->texture[21].s_l, &map->texture[21].endian);
}

static void	ft_draw_texture_crackel(t_mlx *mlx, t_map *map, int a, int b)
{
	map->texture[12].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_0.xpm", &a, &b);
	map->texture[12].str_img = (int *)mlx_get_data_addr(map->texture[12].img,
		&map->texture[12].bpp, &map->texture[12].s_l, &map->texture[12].endian);
	map->texture[13].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_1.xpm", &a, &b);
	map->texture[13].str_img = (int *)mlx_get_data_addr(map->texture[13].img,
		&map->texture[13].bpp, &map->texture[13].s_l, &map->texture[13].endian);
	map->texture[14].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_2.xpm", &a, &b);
	map->texture[14].str_img = (int *)mlx_get_data_addr(map->texture[14].img,
		&map->texture[14].bpp, &map->texture[14].s_l, &map->texture[14].endian);
	map->texture[15].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_3.xpm", &a, &b);
	map->texture[15].str_img = (int *)mlx_get_data_addr(map->texture[15].img,
		&map->texture[15].bpp, &map->texture[15].s_l, &map->texture[15].endian);
	map->texture[16].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_4.xpm", &a, &b);
	map->texture[16].str_img = (int *)mlx_get_data_addr(map->texture[16].img,
		&map->texture[16].bpp, &map->texture[16].s_l, &map->texture[16].endian);
	map->texture[17].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/destroy_stage_5.xpm", &a, &b);
	map->texture[17].str_img = (int *)mlx_get_data_addr(map->texture[17].img,
		&map->texture[17].bpp, &map->texture[17].s_l, &map->texture[17].endian);
}

static void	ft_draw_texture_pistol(t_mlx *mlx, t_map *map, int a, int b)
{
	a = 128;
	b = 128;
	map->texture[7].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/pistol1.xpm", &a, &b);
	map->texture[7].str_img = (int *)mlx_get_data_addr(map->texture[7].img,
		&map->texture[7].bpp, &map->texture[7].s_l, &map->texture[7].endian);
	map->texture[8].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/pistol2.xpm", &a, &b);
	map->texture[8].str_img = (int *)mlx_get_data_addr(map->texture[8].img,
		&map->texture[8].bpp, &map->texture[8].s_l, &map->texture[8].endian);
	map->texture[9].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/pistol3.xpm", &a, &b);
	map->texture[9].str_img = (int *)mlx_get_data_addr(map->texture[9].img,
		&map->texture[9].bpp, &map->texture[9].s_l, &map->texture[9].endian);
	map->texture[10].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/pistol4.xpm", &a, &b);
	map->texture[10].str_img = (int *)mlx_get_data_addr(map->texture[10].img,
		&map->texture[10].bpp, &map->texture[10].s_l, &map->texture[10].endian);
	map->texture[11].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/pistol5.xpm", &a, &b);
	map->texture[11].str_img = (int *)mlx_get_data_addr(map->texture[11].img,
		&map->texture[11].bpp, &map->texture[11].s_l, &map->texture[11].endian);
}

static void	ft_draw_texture2(t_mlx *mlx, t_map *map, int a, int b)
{
	map->texture[4].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/wood.xpm", &a, &b);
	map->texture[4].str_img = (int *)mlx_get_data_addr(map->texture[4].img,
		&map->texture[4].bpp, &map->texture[4].s_l, &map->texture[4].endian);
	map->texture[5].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/sand.xpm", &a, &b);
	map->texture[5].str_img = (int *)mlx_get_data_addr(map->texture[5].img,
		&map->texture[5].bpp, &map->texture[5].s_l, &map->texture[5].endian);
	a = 512;                                                     
	b = 512;
	map->texture[6].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/sky.xpm", &a, &b);
	map->texture[6].str_img = (int *)mlx_get_data_addr(map->texture[6].img,
		&map->texture[6].bpp, &map->texture[6].s_l, &map->texture[6].endian);
}

void		ft_draw_texture(t_mlx *mlx, t_map *map)
{
	int a;
	int	b;

	map->texture = malloc(sizeof(t_img) * 22);
	a = 64;
	b = 64;
	map->texture[0].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/emerald_block.xpm", &a, &b);
	map->texture[0].str_img = (int *)mlx_get_data_addr(map->texture[0].img,
		&map->texture[0].bpp, &map->texture[0].s_l, &map->texture[0].endian);
	map->texture[1].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/bookshelf.xpm", &a, &b);
	map->texture[1].str_img = (int *)mlx_get_data_addr(map->texture[1].img,
		&map->texture[1].bpp, &map->texture[1].s_l, &map->texture[1].endian);
	map->texture[2].img = mlx_xpm_file_to_image(mlx->mlx,
		"textures/daylight_detector_top.xpm", &a, &b);
	map->texture[2].str_img = (int *)mlx_get_data_addr(map->texture[2].img,
		&map->texture[2].bpp, &map->texture[2].s_l, &map->texture[2].endian);
	map->texture[3].img = mlx_xpm_file_to_image(mlx->mlx,
			"textures/door_iron_lower.xpm", &a, &b);
	map->texture[3].str_img = (int *)mlx_get_data_addr(map->texture[3].img,
		&map->texture[3].bpp, &map->texture[3].s_l, &map->texture[3].endian);
	ft_draw_texture2(mlx, map, a, b);
	ft_draw_texture_pistol(mlx, map, a, b);
	ft_draw_texture_crackel(mlx, map, a, b);
	ft_draw_texture_crackel_2(mlx, map, a, b);
}
