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
static int			**ft_new_tab(char *str, int nb_line, int nb_int)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	j = 0;
	k = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nb_line + 1)))
		return (NULL);
	while (str[k] != '\0')
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * nb_int)))
			return (NULL);
		if (str[k] >= '0' && str[k] <= '9')
		{
			printf("%c", str[k]);
			tab[j][i] = ft_atoi_wolf(str, k);
			i++;
		}
		if (str[k] == '\n')
			printf("\n");
		k++;
		j++;
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map = (t_map *)malloc(sizeof (t_map))))
		return (-1);
	if (!(mlx = (t_mlx *)malloc(sizeof (t_mlx))))
		return (-1);
	mlx->map = map;
	img = NULL;
	if (ft_reader(argc, argv[1], mlx) != 0)
	{
		printf("error \n");
		sleep(10);
		return (0);
	}
	map->tab = ft_new_tab(map->str, map->nb_line, map->nb_int);
	sleep(10);
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
