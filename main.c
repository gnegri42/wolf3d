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

static int		**ft_new_tab(char *str, int nb_line, int nb_int)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	j = 0;
	k = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nb_line)))
		return (NULL);
	while (str[k] != '\0' && j < nb_line)
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * nb_int)))
			return (NULL);
		while (str[k] != '\n' && str[k] != '\0' && j < nb_line)
		{
			tab[j][i++] = ft_atoi_wolf(str, &k);
			while (str[k] == ' ')
				k++;
		}
		k++;
		j++;
	}
	return (tab);
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (-1);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (-1);
	mlx->map = map;
	mlx->img = img;
	if (ft_reader(argc, argv[1], map) != 0)
		return (-1);
	map->tab = ft_new_tab(map->str, map->nb_line, map->nb_int);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d 42");
	if (ft_init_player(mlx) == -1)
		return (-1);
	img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->str_img = (int *)mlx_get_data_addr(img->img,
		&(img->bpp), &(img->s_l), &(img->endian));
	mlx_key_hook(mlx->win, ft_key_events, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
