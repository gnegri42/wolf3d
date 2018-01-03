/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:01:49 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/10 14:01:50 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_space(char const *s, int len)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		space++;
		i++;
	}
	if (s[i] != '\0')
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			space++;
			i--;
		}
	}
	return (space);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		space;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	space = ft_space(s, len);
	str = (char *)malloc(sizeof(char) * (len - space + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < (len - space))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
