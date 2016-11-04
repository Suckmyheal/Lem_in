/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:39:32 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/11/03 15:39:35 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_init_2(t_param *param)
{
	int		i;

	i = 0;
	if (ft_get_end(param->tab_room) == NULL || ft_get_start(param->tab_room)
		== NULL || ft_tab_room_len(param->tab_room) < 2)
		return (-1);
	param->mat_adj = (t_room **)malloc(sizeof(t_room) *
		(ft_tab_room_len(param->tab_room) + 1));
	while (i < (ft_tab_room_len(param->tab_room) + 1))
	{
		param->mat_adj[i] = (t_room *)malloc(sizeof(t_room) *
			(ft_tab_room_len(param->tab_room) + 1));
		i++;
	}
	return (1);
}

void		ft_init_3(t_param *param)
{
	param->mat_adj[0][1].name = ft_get_start(param->tab_room);
	param->mat_adj[1][0].name = ft_get_start(param->tab_room);
	param->mat_adj[0][ft_tab_room_len(param->tab_room)].name =
	ft_get_end(param->tab_room);
	param->mat_adj[ft_tab_room_len(param->tab_room)][0].name =
	ft_get_end(param->tab_room);
}

int			ft_init_mat_adj(t_param *param)
{
	int		i;
	int		j;

	j = 0;
	i = 2;
	if (ft_init_2(param) == -1)
		return (-1);
	param->mat_adj[0][0].value = ft_tab_room_len(param->tab_room);
	while (i < param->mat_adj[0][0].value)
	{
		if (param->tab_room[j].start == 0)
		{
			param->mat_adj[0][i].name = param->tab_room[j].name;
			param->mat_adj[i][0].name = param->tab_room[j].name;
			i++;
			j++;
		}
		else
			j++;
	}
	ft_init_3(param);
	return (1);
}

int			ft_link_bis(t_room **mat_adj, char *name, char *name2)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (ft_strcmp(mat_adj[0][i].name, name) != 0)
		i++;
	while (ft_strcmp(mat_adj[j][0].name, name2) != 0)
		j++;
	mat_adj[j][i].value = 1;
	mat_adj[i][j].value = 1;
	return (1);
}

int			ft_link(t_param *param, char *link)
{
	char	**tab;

	if (ft_strchr(link, '-') == NULL)
		return (0);
	tab = ft_strsplit(link, '-');
	if (arraystr_len(tab) != 2)
		return (0);
	if (ft_room_exist(param->tab_room, tab[0]) != 1
		|| ft_room_exist(param->tab_room, tab[1]) != 1)
		return (0);
	ft_link_bis(param->mat_adj, tab[0], tab[1]);
	return (1);
}
