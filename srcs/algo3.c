/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:39:57 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/11/03 15:39:58 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_path_2(t_param *param, int *j, int *i, char *tmp)
{
	while (*j < (NBR_ROOM + 1))
	{
		while (tmp != NULL && param->mat_adj[0][*i].name != tmp)
			*i = *i + 1;
		if (param->mat_adj[*j][*i].value == 1 && param->tab_poids[
			ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[*j][0
			].name)].passed == 0)
		{
			if (param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM,
			param->mat_adj[*j][0].name)].poids == -1 || param->tab_poids[
			ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[*j][0].
			name)].poids > (param->tab_poids[ft_tab_index(param->tab_poids
			, NBR_ROOM, tmp)].poids + 1))
			{
				param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM
				, param->mat_adj[*j][0].name)].poids = param->tab_poids[
				ft_tab_index(param->tab_poids, NBR_ROOM, tmp)].poids + 1;
				param->tab_ant[ft_tab_index(param->tab_poids, NBR_ROOM,
				param->mat_adj[*j][0].name)].ante = tmp;
			}
		}
		*i = 0;
		*j = *j + 1;
	}
	*j = 0;
}

void	ft_path_3(t_param *param)
{
	ft_print_arraystr(param->save_map);
	ft_fill_path(param);
	ft_display_end(param->path, param->nbr_ant, ft_get_poids(param->tab_poids,
	ft_get_end(param->tab_room)), 1);
}

int		ft_pathfinding(t_param *param)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_get_end(param->tab_room) == NULL || ft_get_start(param->tab_room) ==
	NULL || ft_tab_room_len(param->tab_room) < 2)
		return (-1);
	ft_init_tables(param);
	tmp = NULL;
	while (ft_min_poids(param->tab_poids, NBR_ROOM) != NULL &&
		ft_strcmp(ft_min_poids(param->tab_poids, NBR_ROOM),
		param->mat_adj[0][NBR_ROOM].name) != 0)
	{
		tmp = ft_min_poids(param->tab_poids, NBR_ROOM);
		ft_passed(param->tab_poids, NBR_ROOM, tmp);
		if (tmp == NULL)
			return (-1);
		ft_path_2(param, &j, &i, tmp);
	}
	if (ft_get_ante(param->tab_ant, ft_get_end(param->tab_room)) == NULL)
		return (-1);
	ft_path_3(param);
	return ((tmp == NULL) ? -1 : 1);
}
