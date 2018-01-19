/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:19:29 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/19 12:19:30 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_modif_text(t_mlx *mlx, int y)
{
	int d;
	int tex_y;
	int color;

	d = y * 256 - WIN_HEIGHT * 128 + mlx->map->line_height * 128;
	tex_y = ((d * TEXTURE_HEIGHT) / mlx->map->line_height) / 256;
	mlx->player->ray->texture_num = mlx->map->tab
		[mlx->player->map_x][mlx->player->map_y] - 1;
	if (mlx->player->ray->texture_num > 4)
		mlx->player->ray->texture_num = 4;
	color = mlx->map->texture[mlx->player->ray->texture_num].
		str_img[tex_y * 64 + mlx->player->ray->texture_coord % 64];
	if (mlx->destroyed_map->tab[mlx->player->map_x][mlx->player->map_y] > 0
	&& mlx->map->texture[11 + mlx->destroyed_map->
	tab[mlx->player->map_x][mlx->player->map_y]].
		str_img[tex_y * 64 + mlx->player->ray->texture_coord % 64] != WHITE)
		color = mlx->map->
	texture[11 + mlx->destroyed_map->tab[mlx->player->map_x]
			[mlx->player->map_y]].str_img
	[tex_y * 64 + mlx->player->ray->texture_coord % 64];
	return (color);
}

int			ft_modif_tex_color(t_mlx *mlx, int y)
{
	int	color;

	color = ft_modif_text(mlx, y);
	return (color);
}
