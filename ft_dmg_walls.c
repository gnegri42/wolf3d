/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dmg_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:30 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/17 15:30:32 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static int	**ft_null_tab_bis(t_mlx *mlx, int **tab)
{
	int	i;
	int j;

	i = 0;
	while (i < mlx->map->nb_line)
	{
		j = 0;
		while (j < mlx->map->nb_int)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

static int	**ft_null_tab(t_mlx *mlx, char *str, int nb_line, int nb_int)
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
	tab = ft_null_tab_bis(mlx, tab);
	return (tab);
}

int			ft_dmg_walls(t_mlx *mlx)
{
	int x;

	x = 0;
	mlx->destroyed_map->tex_hit = mlx->map->
	tab[mlx->player->map_x][mlx->player->map_y];
	if (mlx->destroyed_map->tex_hit > 0 && mlx->player->weapon == 1
		&& mlx->destroyed_map->tab[mlx->player->map_x][mlx->player->map_y] < 9)
		mlx->destroyed_map->tab[mlx->player->map_x][mlx->player->map_y] += 1;
	return (0);
}

int			ft_init_dmg_walls(t_mlx *mlx)
{
	t_map	*destroyed_map;

	if (!(destroyed_map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	mlx->destroyed_map = destroyed_map;
	destroyed_map->tab = ft_null_tab(mlx, mlx->map->str,
		mlx->map->nb_line, mlx->map->nb_int);
	return (0);
}
