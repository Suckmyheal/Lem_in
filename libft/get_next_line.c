/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 14:41:54 by nbelkaid          #+#    #+#             */
/*   Updated: 2014/12/17 14:42:20 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static void		join_stk(char **str, char *stk, int ret)
{
	char *ptr;

	stk[ret] = '\0';
	ptr = *str;
	*str = ft_strjoin(*str, stk);
	ft_strdel(&ptr);
}

int				get_next_line(int const fd, char **line)
{
	int			len;
	static char	*str[256];
	char		*ptr;
	char		*stk;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || !(stk = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	str[fd] = !str[fd] ? ft_strnew(1) : str[fd];
	while (!(ft_strchr(str[fd], '\n')) && (ret = read(fd, stk, BUFF_SIZE)) > 0)
		join_stk(&str[fd], stk, ret);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !(ft_strchr(str[fd], '\n')))
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (((*line)[0] == '\0') ? 0 : 1);
	}
	len = ft_strchr(str[fd], '\n') - str[fd];
	*line = ft_strsub(str[fd], 0, len);
	ptr = str[fd];
	str[fd] = ft_strdup(ft_strchr(str[fd], '\n') + 1);
	ft_strdel(&ptr);
	return (1);
}
