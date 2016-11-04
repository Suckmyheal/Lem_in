/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 15:58:26 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/10/06 15:58:29 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_init_tables(t_param *param)
{
	int		i;

	i = 0;
	param->tab_poids = (t_poids *)malloc(sizeof(t_poids) * NBR_ROOM);
	while (i < NBR_ROOM)
	{
		param->tab_poids[i].name = param->mat_adj[0][i + 1].name;
		param->tab_poids[i].poids = -1;
		param->tab_poids[i].passed = 0;
		if (i == 0)
			param->tab_poids[i].poids = 0;
		i++;
	}
	i = 0;
	param->tab_ant = (t_ante *)malloc(sizeof(t_ante) * NBR_ROOM);
	while (i < NBR_ROOM)
	{
		param->tab_ant[i].name = param->mat_adj[0][i + 1].name;
		param->tab_ant[i].ante = NULL;
		i++;
	}
	return (1);
}

char	*ft_min_poids(t_poids *tab_poids, int nbr_room)
{
	int		min;
	int		i;
	char	*save;

	i = 0;
	min = -1;
	save = NULL;
	while (i < nbr_room)
	{
		if (tab_poids[i].passed == 0 && tab_poids[i].poids != -1 && min == -1)
		{
			min = tab_poids[i].poids;
			save = tab_poids[i].name;
		}
		else if (min != -1 && min > tab_poids[i].poids
			&& tab_poids[i].passed == 0 && tab_poids[i].poids != -1)
		{
			min = tab_poids[i].poids;
			save = tab_poids[i].name;
		}
		i++;
	}
	return (save);
}

int		ft_passed(t_poids *tab_poids, int nbr_room, char *name)
{
	int		i;

	i = 0;
	while (i < nbr_room)
	{
		if (ft_strcmp(tab_poids[i].name, name) == 0)
		{
			tab_poids[i].passed = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_tab_index(t_poids *tab_poids, int nbr_room, char *name)
{
	int		i;

	i = 0;
	while (i < nbr_room)
	{
		if (ft_strcmp(tab_poids[i].name, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
