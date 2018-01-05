/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:31:17 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/04 11:31:18 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_number_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > '0' && str[i] < '9') && str[i + 1] != ' ')
		{
			ft_putstr("wrong number value : ");
			return (-1);
		}
		else if (str[i + 1] == ' ' && (str[i + 1] < '0' && str[i + 1] > '9'))
		{
			ft_putstr("wrong number value : ");
			return (-1);
		}
		i++;
	}
	return (1);
}

static int	ft_invalid(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n'
			&& !(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("bad character in file : ");
			return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_check_errors(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
	{
		ft_putstr("file is empty : ");
		return (0);
	}
	while (str[i] != '\0')
		i++;
	if (ft_number_error(str) == -1 || ft_invalid(str, 0) == -1)
		return (0);
	return (1);
}

int			ft_check_args(int argc, char *argv, int *fd)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./wolf3d input_file\n");
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("bad_file : error\n");
		return (-1);
	}
	if (BUFF_SIZE <= 0)
	{
		ft_putstr("BUFF_SIZE : error\n");
		return (-1);
	}
	return (1);
}
