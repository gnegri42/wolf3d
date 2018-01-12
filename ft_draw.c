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
static void			ft_fill_pixel(t_img *img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img->str_img[i] = color;
}
/*
static int			ft_text(t_mlx *mlx, int y, int x)
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
*/
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
/*
static unsigned int	ft_get_color(t_mlx *mlx)
{
	if (mlx->player->ray->side == 1)
	{
		if ((mlx->player->ray->step_x == -1 &&
			mlx->player->ray->step_y == -1) ||
			(mlx->player->ray->step_x == 1 && mlx->player->ray->step_y == -1))
			return (ORANGE);
		if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1) ||
			(mlx->player->ray->step_x == 1 && mlx->player->ray->step_y == 1))
			return (WHITE);
	}
	if ((mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == -1) ||
		(mlx->player->ray->step_x == -1 && mlx->player->ray->step_y == 1))
		return (GREEN);
	return (0x0441FF);
}
*/
void				ft_draw_col(t_mlx *mlx, int x)
{
	int		i;
	int		color;

	//color = ft_get_color(mlx);
	i = 0;
	while (i < mlx->map->pixel_start)
		//ft_fill_pixel(mlx->img, x, i, BLUE);
		i++;
	while (i++ <= mlx->map->pixel_last)
	{
		color = ft_get_color(mlx, x, i);
		//color = ft_text(mlx, x, i);
		ft_fill_pixel(mlx->img, x, i, color);
	}
	i--;
	while (i++ < WIN_HEIGHT)
	{
		color = ft_text_ground(mlx, x, i);
		ft_fill_pixel(mlx->img, x, i, color);
	}
}
