/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:46:37 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/17 14:35:47 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			ft_text(t_mlx *mlx, int y)
{
	int d;
	int tex_y;
	int color;

	d = y * 256 - WIN_HEIGHT * 128 + mlx->map->line_height * 128;
	tex_y = ((d * TEXTURE_HEIGHT) / mlx->map->line_height) / 256;
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

static unsigned int	ft_get_color2(t_mlx *mlx, int y)
{
	int color;

	if (mlx->player->ray->side == 1)
	{
		if ((mlx->player->ray->step_x == -1 &&
			mlx->player->ray->step_y == -1) || (mlx->player->ray
			->step_x == 1 && mlx->player->ray->step_y == -1))
		{
			mlx->player->ray->texture_num = 0;
			color = ft_text(mlx, y);
			return (color);
		}
		if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1) ||
				(mlx->player->ray->step_x == 1
					&& mlx->player->ray->step_y == 1))
		{
			mlx->player->ray->texture_num = 1;
			color = ft_text(mlx, y);
			return (color);
		}
	}
	return (0);
}

static unsigned int	ft_get_color(t_mlx *mlx, int y)
{
	int color;

	if (ft_get_color2(mlx, y) == 0)
	{
		if ((mlx->player->ray->step_x == -1 &&
			mlx->player->ray->step_y == -1) ||
				(mlx->player->ray->step_x == -1 &&
					mlx->player->ray->step_y == 1))
		{
			mlx->player->ray->texture_num = 2;
			color = ft_text(mlx, y);
			return (color);
		}
		mlx->player->ray->texture_num = 3;
		color = ft_text(mlx, y);
		return (color);
	}
	else
		return (ft_get_color2(mlx, y));
}

static void			ft_draw_col2(t_mlx *mlx, int x, int i)
{
	while (i < WIN_HEIGHT)
	{
		if (mlx->map->switch_tex == 1)
			ft_fill_pixel(mlx->img, x, i, BLACK);
		else
		{
		//color = ft_draw_floor(mlx, mlx->player->ray, i);
		//color = ft_text_ground(mlx, x, i);
			ft_fill_pixel(mlx->img, x, i, BLACK);
		}
		i++;
	}
	if (mlx->map->show_map == 1)
		ft_draw_minimap(mlx);
}

void				ft_draw_col(t_mlx *mlx, int x)
{
	int		i;
	int		color;

	i = 0;
	while (i < mlx->map->pixel_start)
	{
		if (mlx->map->switch_tex == 1)
			ft_fill_pixel(mlx->img, x, i, BLUE);
		i++;
	}
	while (i <= mlx->map->pixel_last)
	{
		if (mlx->map->switch_tex == 1)
			color = ft_get_initial_color(mlx);
		else
			color = ft_get_color(mlx, i);
		ft_fill_pixel(mlx->img, x, i, color);
		i++;
	}
	i--;
	ft_draw_col2(mlx, x, i);
}
