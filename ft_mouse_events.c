/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:35:22 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/16 13:35:24 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_mouse_events(int button, int x, int y, t_mlx *mlx)
{
  if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x <= 0 || y <= 0)
		return (0);
	if (button == 1 && mlx->player->shoot == 0)
		mlx->player->shoot = 1;
  ft_calc(mlx, mlx->player);
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}
