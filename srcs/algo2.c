/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:39:52 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/11/03 15:39:53 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_get_poids(t_poids *tab_poids, char *roomname)
{
	int		i;

	i = 0;
	while (tab_poids[i].name != NULL)
	{
		if (ft_strcmp(tab_poids[i].name, roomname) == 0)
			return (tab_poids[i].poids);
		i++;
	}
	return (0);
}

char	*ft_get_ante(t_ante *tab_ant, char *roomname)
{
	int		i;

	i = 0;
	while (tab_ant[i].name != NULL)
	{
		if (ft_strcmp(tab_ant[i].name, roomname) == 0)
			return (tab_ant[i].ante);
		i++;
	}
	return (NULL);
}

void	ft_fill_path(t_param *param)
{
	int		poids;
	int		i;

	i = 0;
	poids = ft_get_poids(param->tab_poids, ft_get_end(param->tab_room));
	param->path = (t_room *)malloc(sizeof(t_room) * (poids + 2));
	while (i < (poids + 1))
	{
		if (i == 0)
		{
			param->path[i].name = ft_get_end(param->tab_room);
			param->path[i].nbr_ant = 0;
			param->path[i].ant_name = 0;
		}
		else
		{
			param->path[i].name = ft_get_ante(param->tab_ant,
			param->path[i - 1].name);
			param->path[i].ant_name = 0;
			if (i == poids)
				param->path[i].nbr_ant = param->nbr_ant;
		}
		i++;
	}
	param->path[poids + 1].name = NULL;
}

void	ft_put_move(int ant_name, char *roomname)
{
	ft_putstr("L");
	ft_putnbr(ant_name);
	ft_putstr("-");
	ft_putstr(roomname);
	ft_putstr(" ");
}

void	ft_display_end(t_room *path, int nbr_ant, int poids, int i)
{
	while (path[0].nbr_ant < nbr_ant)
	{
		while (i <= poids)
		{
			if (i == poids && path[i].nbr_ant > 0)
			{
				if (i == 1)
					path[i - 1].nbr_ant++;
				path[i].ant_name = 0;
				path[i - 1].ant_name = nbr_ant - path[i].nbr_ant + 1;
				ft_put_move(path[i - 1].ant_name, path[i - 1].name);
				path[i].nbr_ant--;
			}
			else if (i != poids && path[i].ant_name != 0)
			{
				path[i - 1].ant_name = path[i].ant_name;
				path[i].ant_name = 0;
				if (i == 1)
					path[i - 1].nbr_ant++;
				ft_put_move(path[i - 1].ant_name, path[i - 1].name);
			}
			i++;
		}
		ft_putendl("");
		i = 1;
	}
}
