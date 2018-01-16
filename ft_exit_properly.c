/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_properly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:12:52 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/16 15:12:54 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf3d.h"

static void			ft_wolf_free_image(t_mlx *mlx)
{
  int x;

  x = 0;
  while (x < 11)
  {
    mlx_destroy_image(mlx->mlx, mlx->map->texture[x].img);
    x++;
 }
 free(mlx->map->texture);
 mlx_destroy_image(mlx->mlx, mlx->img->img);
}

static void			ft_wolf_free_map(t_mlx *mlx)
{
	int				x;

	x = 0;
	while (x < mlx->map->nb_line)
		free(mlx->map->tab[x++]);
	free(mlx->map->tab);
  x = 0;
  while (x < mlx->map->nb_line)
	 free(mlx->map->content[x++]);
  free(mlx->map->str);
  mlx->player->ray ? free(mlx->player->ray) : (0);
  mlx->player ? free(mlx->player) : (0);
}

int					ft_exit_properly(t_mlx *mlx)
{
  ft_wolf_free_image(mlx);
	mlx->map->tab ? ft_wolf_free_map(mlx) : (0);
  mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
