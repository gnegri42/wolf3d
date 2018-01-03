/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:46:41 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/10 13:46:42 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	int		l_s1;
	int		l_s2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(str) * (l_s1 + l_s2 + 1));
	if (str == NULL)
		return (0);
	while (i < l_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < l_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
