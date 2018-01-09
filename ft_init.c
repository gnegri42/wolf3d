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

/*
Function that init the player position and the vectors in order to calculate the view.
To be modified later to chage the initial position of the player
*/

int		ft_init_player(t_mlx *mlx)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (-1);
	mlx->player = player;
	player->pos_x = 22;
	player->pos_y = 12;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return (0);
}
