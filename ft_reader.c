/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:26:38 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/08 11:50:51 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static int	ft_strlen_content(char *str)
{
	int	i;
	int	nb_int;

	i = 0;
	nb_int = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 1)
		{
			nb_int++;
			i++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
	}
	return (nb_int);
}

static int	ft_verif_int_nb(t_map *map)
{
	int		l;
	int		c;

	l = 0;
	while (l < map->nb_line - 1)
	{
		c = ft_strlen_content(map->content[l]);
		if (ft_strlen_content(map->content[l + 1]) != c)
			return (-1);
		l++;
	}
	return (0);
}

static int	ft_verifs(int fd, t_map *map, char *line)
{
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("error : unable to read any content\n");
		free(map->str);
		free(map->content);
		return (-1);
	}
	if (close(fd) == -1 || ft_check_errors(map->str) != 0)
	{
		free(map->content);
		free(map->str);
		return (-1);
	}
	if (ft_verif_int_nb(map) != 0)
	{
		ft_putstr("error : wrong line length\n");
		free(map->content);
		free(map->str);
		return (-1);
	}
	return (0);
}

static int	ft_check_read(int argc, char *argv, int *fd)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./wolf3d input_file\n");
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("error : bad_file\n");
		close(*fd);
		return (-1);
	}
	if (WIN_WIDTH > 800 || WIN_HEIGHT > 600)
	{
		ft_putstr("Window size is too big : 800:600 is recommended.\n");
		return(-1);
	}
	return (0);
}

int			ft_reader(int argc, char *argv, t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;

	map->str = ft_strnew(1);
	if (ft_check_read(argc, argv, &fd) != 0)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = map->str;
		tmp2 = ft_strjoin(tmp, line);
		map->str = ft_strjoin(tmp2, "\n");
		free(tmp);
		free(tmp2);
		map->nb_line++;
		free(line);
	}
	map->content = ft_strsplit(map->str, '\n');
	if (ft_verifs(fd, map, line) != 0)
		return (-1);
	map->nb_int = ft_strlen_content(map->content[0]);
	return (0);
}
