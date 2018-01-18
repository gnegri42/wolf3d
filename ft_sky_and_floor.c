/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sky_and_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:45:24 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/17 11:45:26 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void		ft_calc_floor(t_mlx *mlx, t_ray *ray)
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
}*/

/*
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
*/

/*
int 	ft_draw_floor(t_mlx *mlx, t_ray *ray, int y)
{
	double	weight;
	double	current_floor_x;
	double	current_floor_y;
	int		floor_texX;
	int		floor_texY;
	int		color;

	mlx->player->current_dist = WIN_HEIGHT / (2.0 * y - WIN_HEIGHT);
	weight = (mlx->player->current_dist - mlx->player->dist) / (ray->wall_dist_bottom - mlx->player->dist);
	//weight = mlx->player->current_dist / mlx->player->dist;
	current_floor_x = weight * ray->floor_pos_x + (1.0 - weight) * ray->floor_pos_x;
	current_floor_y = weight * ray->floor_pos_y + (1.0 - weight) * ray->floor_pos_y;
	floor_texX = (int)(current_floor_x * TEXTURE_WIDTH) % TEXTURE_WIDTH;
	floor_texY = (int)(current_floor_y * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;
	color = mlx->map->texture[5].str_img[floor_texY * TEXTURE_WIDTH + floor_texX * TEXTURE_WIDTH];
	return (color);
}
*/

int		ft_space_error(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->map->nb_line)
	{
		j = 0;
		while (j < mlx->map->nb_int)
		{
			if (mlx->map->tab[i][j] > 49)
			{
				ft_putstr(
					"The value of a number is too big. Limit set to 50.\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_calc_pos_hit(t_ray *ray, t_map *map, t_player *player)
{
	ray->texture_num = map->tab[player->map_x][player->map_y] - 1;
	if (ray->side == 0)
		ray->wall_hit = ray->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = ray->pos_x + ray->wall_dist * ray->dir_x;
	ray->texture_coord = (int)(ray->wall_hit * (double)(TEXTURE_WIDTH));
	if ((ray->side == 0 && ray->dir_x > 0) ||
		(ray->side == 1 && ray->dir_y < 0))
		ray->texture_coord = TEXTURE_WIDTH - ray->texture_coord - 1;
	ray->texture_coord = abs(ray->texture_coord);
}

void	ft_draw_sky(t_mlx *mlx)
{
	int	x;
	int	y;
	int j;
	int	color;

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
