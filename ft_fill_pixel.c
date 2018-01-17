/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:22:00 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/17 14:22:02 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_fill_pixel(t_img *img, int x, int y, int color)
{
	int i;

	i = x + y * WIN_WIDTH;
	img->str_img[i] = color;
}
