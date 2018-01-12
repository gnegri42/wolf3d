/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:58:56 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/12 11:58:58 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_get_initial_color(t_mlx *mlx)
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
	return (0x054163);
}
