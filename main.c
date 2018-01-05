/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:08:24 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/04 10:08:25 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof (t_map))))
		return (-1);
	if (!(mlx = (t_mlx *)malloc(sizeof (t_mlx))))
		return (-1);
	mlx->map = map;
	img = NULL;
	if (ft_reader(argc, argv[1], mlx) != 0)
	{
		ft_putstr("error");
		//sleep(10);
		return (0);
	}
	//sleep(10);
	/*
	mlx->mlx = mlx_init();
	mlx->img = img;
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->str_img = (int *)mlx_get_data_addr(img->img,
		&(img->bpp), &(img->s_l), &(img->endian));
		*/

	return (0);
}
