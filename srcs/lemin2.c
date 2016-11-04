/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:39:24 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/11/03 15:39:27 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_print_arraystr(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i] != NULL)
	{
		ft_putendl(tab[i]);
		i++;
	}
	ft_putendl("");
}

int			ft_room_exist(t_room *tab_room, char *roomname)
{
	int		i;

	i = 0;
	if (roomname == NULL)
		return (0);
	while (tab_room[i].name != NULL)
	{
		if (ft_strcmp(tab_room[i].name, roomname) == 0)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_get_start(t_room *tab_room)
{
	int		i;

	i = 0;
	while (i < ft_tab_room_len(tab_room))
	{
		if (tab_room[i].start == 1)
			return (tab_room[i].name);
		i++;
	}
	return (NULL);
}

char		*ft_get_end(t_room *tab_room)
{
	int		i;

	i = 0;
	while (i < ft_tab_room_len(tab_room))
	{
		if (tab_room[i].start == 2)
			return (tab_room[i].name);
		i++;
	}
	return (NULL);
}
