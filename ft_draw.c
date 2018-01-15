/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:46:37 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/09 15:46:38 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static int			ft_text_ground(t_mlx *mlx, int x, int y)
{
	int d;
	int j;
	int texY;
	int color;
	
	d = y * 256 - WIN_HEIGHT * 128 + mlx->map->line_height * 128;
	texY = ((d * TEXTURE_HEIGHT) / mlx->map->line_height) / 256;
	j = x + y * WIN_WIDTH;
	color = mlx->map->texture[5].str_img[texY * 64 + mlx->player->ray->texture_coord % 64];
	return (color);
}

void			ft_fill_pixel(t_img *img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img->str_img[i] = color;
}

static int			ft_text(t_mlx *mlx, int x, int y)
{
	int d;
	int j;
	int texY;
	int color;
	
	d = y * 256 - WIN_HEIGHT * 128 + mlx->map->line_height * 128;
	texY = ((d * TEXTURE_HEIGHT) / mlx->map->line_height) / 256;
	j = x + y * WIN_WIDTH;
	color = mlx->map->texture[mlx->player->ray->texture_num].str_img[texY * 64 + mlx->player->ray->texture_coord % 64];
	return (color);
}

static unsigned int	ft_get_color(t_mlx *mlx, int x, int y)
{
	int color;

	if (mlx->player->ray->side == 1)
	{
		if ((mlx->player->ray->step_x == -1 &&
			mlx->player->ray->step_y == -1) ||
			(mlx->player->ray->step_x == 1 && mlx->player->ray->step_y == -1))
		{
			mlx->player->ray->texture_num = 0;
			color = ft_text(mlx, x, y);
			return (color);			
		}
		if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1) ||
			(mlx->player->ray->step_x == 1 && mlx->player->ray->step_y == 1))
		{
			mlx->player->ray->texture_num = 1;
			color = ft_text(mlx, x, y);
			return (color);	
		}
	}
	if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == -1) ||
		(mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1))
	{
		mlx->player->ray->texture_num = 2;
		color = ft_text(mlx, x, y);
		return (color);			
	}
	mlx->player->ray->texture_num = 3;
	color = ft_text(mlx, x, y);
	return (color);			
}

void				ft_draw_sky(t_mlx *mlx)
{
	int		x;
	int		y;
	int 	j;
	int		color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			j = x + y * 512;
			color = mlx->map->texture[6].str_img[j];
			ft_fill_pixel(mlx->img, x, y, color);
			y++;
		}
		x++;
	}
}
/*
static int ft_draw_floor(t_mlx *mlx, t_ray *ray, int y)
{
	double weight;
	double current_floor_x;
	double current_floor_y;
	int	floor_texX;
	int floor_texY;
	int color;

	mlx->player->current_dist = WIN_HEIGHT / (2.0 * y - WIN_HEIGHT);
	weight = (mlx->player->current_dist - mlx->player->dist) / (ray->wall_dist_bottom - mlx->player->dist);
	current_floor_x = weight * ray->floor_pos_x + (1.0 - weight) * ray->floor_pos_x;
	current_floor_y = weight * ray->floor_pos_y + (1.0 - weight) * ray->floor_pos_y;
	floor_texX = (int)(current_floor_x * TEXTURE_WIDTH) % TEXTURE_WIDTH;
	floor_texY = (int)(current_floor_y * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;
	color = mlx->map->texture[5].str_img[floor_texY  + floor_texX * TEXTURE_WIDTH];
	return (color);
}
*/
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
	while (i++ <= mlx->map->pixel_last)
	{
		if (mlx->map->switch_tex == 1)
			color = ft_get_initial_color(mlx);
		else
			color = ft_get_color(mlx, x, i);
		ft_fill_pixel(mlx->img, x, i, color);
	}
	i--;
	while (i++ < WIN_HEIGHT)
	{
		if (mlx->map->switch_tex == 1)
			ft_fill_pixel(mlx->img, x, i, BLACK);
		else
		{
			//color = ft_draw_floor(mlx, mlx->player->ray, i);
			color = ft_text_ground(mlx, x, i);
			ft_fill_pixel(mlx->img, x, i, color);
		}
	}
}
