/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:36:23 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/13 09:36:24 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char		*fill_str(char *str, int n, int len, int p)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	if (p == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		p;

	p = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		p = 1;
		n = -n;
	}
	str = fill_str(str, n, len, p);
	return (str);
}
