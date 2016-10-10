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
	/* initialise tableau des poids et tableau des antecedents */
	int		i;

	i = 0;
	param->tab_poids = (t_poids *)malloc(sizeof(t_poids) * NBR_ROOM);
	while (i < 7)
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
	while (i < 7)
	{
		param->tab_ant[i].name = param->mat_adj[0][i + 1].name;
		param->tab_ant[i].ante = NULL;
		i++;
	}
	return (1);
}

char	*ft_min_poids(t_poids *tab_poids, int nbr_room)
{
	/* Renvoi le nom de la salle ayant le plus petit poids */
	int min;
	int i;
	char *save;

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
		else if (min != -1 && min > tab_poids[i].poids && tab_poids[i].passed == 0 && tab_poids[i].poids != -1)
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

void	ft_show_data(t_poids *tab_poids, t_ante *tab_ant, int nbr_room, int nbr)
{
	int		i;

	i = 0;
	if (nbr == 1)
	{
		while (i < nbr_room)
		{
			printf("name = %s\n", tab_poids[i].name);
			printf("poids = %d\n", tab_poids[i].poids);
			printf("passed = %d\n", tab_poids[i].passed);
			printf("\n");
			i++;
		}
	}
	else if (nbr == 2)
	{
		while (i < nbr_room)
		{
			printf("name = %s\n", tab_ant[i].name);
			printf("ante = %s\n", tab_ant[i].ante);
			printf("\n");
			i++;
		}
	}
}

int		ft_pathfinding(t_param *param)
{
	char *tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_tables(param);
	ft_show_data(param->tab_poids, param->tab_ant, NBR_ROOM, 1);
	ft_show_data(param->tab_poids, param->tab_ant, NBR_ROOM, 2);
	while (ft_strcmp(ft_min_poids(param->tab_poids, NBR_ROOM), param->mat_adj[0][NBR_ROOM].name) != 0 && ft_min_poids(param->tab_poids, NBR_ROOM) != NULL)
	{
		tmp = ft_min_poids(param->tab_poids, NBR_ROOM);
		ft_passed(param->tab_poids, NBR_ROOM, tmp);
		while (j < (NBR_ROOM + 1))
		{
			while (param->mat_adj[0][i].name != tmp)
				i++;
			if (param->mat_adj[j][i].value == 1 && param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[j][0].name)].passed == 0)
			{
				if(param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[j][0].name)].poids == -1
					|| param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[j][0].name)].poids > (param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM, tmp)].poids + 1))
				{
					param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[j][0].name)].poids = param->tab_poids[ft_tab_index(param->tab_poids, NBR_ROOM, tmp)].poids + 1;
					param->tab_ant[ft_tab_index(param->tab_poids, NBR_ROOM, param->mat_adj[j][0].name)].ante = tmp;
					ft_show_data(param->tab_poids, param->tab_ant, NBR_ROOM, 2);
					ft_show_data(param->tab_poids, param->tab_ant, NBR_ROOM, 1);					
					printf("%s\n", ft_min_poids(param->tab_poids, NBR_ROOM));
					printf("%d\n", param->tab_poids[0].passed);
				}
			}
			i = 0;
			j++;
		}
		j = 0;
	}
	ft_show_data(param->tab_poids, param->tab_ant, NBR_ROOM, 1);
	ft_show_data(param->tab_poids, param->tab_ant, NBR_ROOM, 2);
	return (1);
}









