/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:36:42 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/10 11:36:45 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str[i] = (*f)(i, ((char *)s)[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
