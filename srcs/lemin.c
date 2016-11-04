/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 00:57:24 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/04/16 00:57:31 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			arraystr_len(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int			ft_is_strnum(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != 0)
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int			arraystr_push_free(t_param *param, char *str)
{
	int		i;
	char	**new_tab;

	i = 0;
	new_tab = (char **)malloc(8 * (arraystr_len(param->save_map) + 2));
	if (new_tab == NULL)
	{
		param->error = 1;
		return (-1);
	}
	while (param->save_map != NULL && param->save_map[i] != NULL)
	{
		new_tab[i] = param->save_map[i];
		i++;
	}
	new_tab[i] = ft_strdup(str);
	new_tab[i + 1] = NULL;
	param->save_map = new_tab;
	return (1);
}

int			ft_tab_room_len(t_room *tab)
{
	int		i;

	i = 0;
	while (tab && tab[i].name != NULL)
		i++;
	return (i);
}

t_room		*ft_add_roomname(t_param *param, char *roomname)
{
	t_room	*new_tab;
	int		i;

	i = 0;
	new_tab = (t_room *)malloc(sizeof(t_room) *
		(ft_tab_room_len(param->tab_room) + 2));
	while (param->tab_room && param->tab_room[i].name != NULL)
	{
		new_tab[i].name = param->tab_room[i].name;
		new_tab[i].start = param->tab_room[i].start;
		i++;
	}
	new_tab[i].name = ft_strdup(roomname);
	if (param->comm == 1)
		new_tab[i].start = 1;
	else if (param->comm == 2)
		new_tab[i].start = 2;
	else
		new_tab[i].start = 0;
	param->comm = 0;
	new_tab[i + 1].name = NULL;
	return (new_tab);
}
