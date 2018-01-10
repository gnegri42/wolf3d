/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:54:22 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/09 13:54:30 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_find_position(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->map->nb_line)
	{
		j = 0;
		while (j < mlx->map->nb_int)
		{
			if (mlx->map->tab[i][j] != 0)
				j++;
			else
			{
				mlx->player->pos_x = j;
				mlx->player->pos_y = i;
				return (0);
			}
		}
		i++;
	}
	return (0);
}

/*
Function that init the player position and the vectors in order to calculate the view.
To be modified later to chage the initial position of the player
*/

int		ft_init_player(t_mlx *mlx)
{
	t_player	*player;
	t_ray		*ray;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (-1);
	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (-1);
	mlx->player = player;
	player->ray = ray;
	ft_find_position(mlx);
	player->dir_x = 1;
	player->dir_y = 0;
	player->move = 0.5;
	player->turn = 0.5;
	player->plane_x = 5;
	player->plane_y = 5;
	return (0);
}
