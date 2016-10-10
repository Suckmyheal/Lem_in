/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 00:57:42 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/04/16 00:57:45 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H

# define LEMIN_H
# include "libft/libft.h"
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"

# define NBR_ROOM param->mat_adj[0][0].value

typedef struct	s_room
{
	char	*name;
	int		value;
	int		end;
}				t_room;

typedef struct	s_poids
{
	char	*name;
	int		poids;
	int		passed;
}				t_poids;

typedef struct	s_ante
{
	char	*name;
	char	*ante;
}				t_ante;

typedef struct	s_param
{
	char	**save_map;
	t_room	**mat_adj;
	t_poids	*tab_poids;
	t_ante	*tab_ant;
}				t_param;

int		ft_create_test(t_param *param);
int		ft_pathfinding(t_param *param);
void	ft_show_data(t_poids *tab_poids, t_ante *tab_ant, int nbr_room, int nbr);
//param->mat_adj[0][0].value = nbr_room
//premiere ligne de mat_adj = liste des name room
//premier nom = depart, dernier nom = arrivé 

#endif