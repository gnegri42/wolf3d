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

static void	ft_enclosed_bis(t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < mlx->map->nb_line)
	{
		if (mlx->map->tab[i][0] == 0)
			mlx->map->tab[i][0] = 1;
		i++;
	}
	i = 0;
	while (i < mlx->map->nb_line)
	{
		if (mlx->map->tab[i][mlx->map->nb_int - 1] == 0)
			mlx->map->tab[i][mlx->map->nb_int - 1] = 1;
		i++;
	}
}

static void	ft_enclosed(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->map->nb_int)
	{
		if (mlx->map->tab[0][i] == 0)
			mlx->map->tab[0][i] = 1;
		i++;
	}
	i = 0;
	while (j < mlx->map->nb_int)
	{
		if (mlx->map->tab[mlx->map->nb_line - 1][j] == 0)
			mlx->map->tab[mlx->map->nb_line - 1][j] = 1;
		j++;
	}
	ft_enclosed_bis(mlx);
}

static int	**ft_new_tab(char *str, int nb_line, int nb_int)
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

static void	ft_loop_img(t_mlx *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->str_img = (int *)mlx_get_data_addr(img->img,
		&(img->bpp), &(img->s_l), &(img->endian));
	ft_calc(mlx, mlx->player);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx_key_hook(mlx->win, ft_key_events, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, ft_move_events, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, ft_red_cross, mlx);
	mlx_loop(mlx->mlx);
}

int			main(int argc, char **argv)
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
	ft_enclosed(mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d 42");
	if (ft_init_player(mlx) == -1)
		return (-1);
	ft_loop_img(mlx, img);
	return (0);
}
