/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:59:50 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/10 10:59:51 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	int				c;
	char			*str;

	i = 0;
	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	str = (char *)malloc((c + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			str[i] = (*f)(((char *)s)[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
