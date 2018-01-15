/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:40:11 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/28 15:59:31 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_delete(char const *s1, char const *s2, int n1, int n2)
{
	char	*str_new;

	str_new = ft_strjoin((char *)s1, (char *)s2);
	if (n1 == 1)
		ft_strdel((char **)&s1);
	if (n2 == 1)
		ft_strdel((char **)&s2);
	return (str_new);
}
