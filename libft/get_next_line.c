/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:40:11 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/28 15:59:31 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		
		
static t_list	*check_fd(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*tmp_previous;

	if (fd < 0)
		return (NULL);
	tmp = *list;
	tmp_previous = NULL;
	while (tmp != NULL)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp_previous = tmp;
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = (size_t)fd;
	if (!tmp_previous)
		*list = tmp;
	else
		tmp_previous->next = tmp;
	
	return (tmp);
}

static int	inside_list_content(t_list *list, char **line)
{
	char *str;
	int x;

	x = 0;
	if (list->content)
	{
		while (((char*)list->content)[x] && ((char*)list->content)[x] != '\n')
			x++;
		str = ft_strsub((char*)list->content, 0, x);
		*line = ft_strjoin_delete(*line, str, 1, 1);
		if (((char*)list->content)[x] == '\n')
		{
			str = ft_strdup((char*)list->content + x + 1);
			ft_strdel((char**)&(list->content));
			list->content = str;
			return (1);
		}
		else
			ft_strdel((char**)&(list->content));
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
    char            buf[BUFF_SIZE + 1];
    int             ret;
	static t_list   *list;
	t_list			*tmp;

	if ((tmp = check_fd(&list, fd)) == NULL || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	if (inside_list_content(tmp, line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp->content = ft_strdup(buf);
		if (inside_list_content(tmp, line) == 1)
			return (1);
	}
	if (**line)
		return (1);
	return (0);
}
