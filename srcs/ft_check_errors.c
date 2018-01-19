/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:31:17 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/09 14:44:11 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_check_space(char *str)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			space = 1;
		i++;
	}
	if (space == 0)
	{
		ft_putstr("The map cannot be composed of less than 3 row of int.\n");
		return (-1);
	}
	return (0);
}

static int	ft_number_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '0' && str[i] < '9')
		{
			while (str[i] > '0' && str[i] < '9' && str[i + 1] != ' ')
				i++;
			if ((str[i] > '0' && str[i] < '9') && str[i + 1] != ' ')
			{
				ft_putstr("Error : Wrong number value.\n");
				return (-1);
			}
		}
		else if (str[i + 1] == ' ' && (str[i + 1] < '0' && str[i + 1] > '9'))
		{
			ft_putstr("Error : Wrong number value.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	ft_start_error(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
		{
			ft_putstr("Error: lines must start by a digit or a space.\n");
			return (-1);
		}
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		i++;
	}
	return (0);
}

static int	ft_invalid(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n'\
				&& !(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("Error: bad character in file.\n");
			return (-1);
		}
		if (str[i] == '0')
			count = 1;
		i++;
	}
	if (count == 0)
	{
		ft_putstr("Error: no place to stand in the map.\n");
		return (-1);
	}
	return (0);
}

int			ft_check_errors(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
	{
		ft_putstr("Error: file is empty.\n");
		return (-1);
	}
	while (str[i] != '\0')
		i++;
	if (ft_start_error(str) == -1 || ft_invalid(str, 0) == -1
		|| ft_number_error(str) == -1 || ft_check_space(str) == -1)
		return (-1);
	return (0);
}
