/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:39:40 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/11/03 15:39:43 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_is_correc_2(t_param *param, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		param->comm = 1;
	if (ft_strcmp(line, "##end") == 0)
		param->comm = 2;
	return (1);
}

int			ft_is_correc_3(t_param *param, char *line)
{
	if (ft_is_strnum(line) == 0)
		return (0);
	param->nbr_ant = ft_atoi(line);
	param->part++;
	return (1);
}

int			ft_is_correc_4(t_param *param, char *line)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (arraystr_len(tab) != 3)
		return (0);
	if (ft_is_strnum(tab[1]) != 1 || ft_is_strnum(tab[2]) != 1)
		return (0);
	if (tab[0])
		param->tab_room = ft_add_roomname(param, tab[0]);
	return (1);
}

int			ft_is_correct_line(char *line, t_param *param)
{
	if (line == NULL || ft_strcmp(line, "") == 0 || ft_strcmp(line, "\n") == 0)
		return (0);
	if (line[0] == '#')
		return (ft_is_correc_2(param, line));
	else if (param->part == 0)
		return (ft_is_correc_3(param, line));
	else if (param->part == 1 && ft_strchr(line, ' ') != NULL)
		return (ft_is_correc_4(param, line));
	else if (param->part == 1 && ft_strchr(line, ' ') == NULL)
	{
		if (ft_init_mat_adj(param) == -1)
			return (0);
		if (ft_link(param, line) == 0)
			return (0);
		param->part++;
	}
	else if (param->part == 2)
	{
		if (ft_link(param, line) == 0)
			return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_param		param;
	char		*li;
	char		**tab;

	param.part = 0;
	param.comm = 0;
	param.tab_room = NULL;
	param.save_map = NULL;
	param.error = 0;
	tab = NULL;
	if (ac != 1 || av == NULL)
	{
		ft_putendl("ERROR");
		return (-1);
	}
	while (get_next_line(0, &li) == 1 && ft_is_correct_line(li, &param) != 0)
		arraystr_push_free(&param, li);
	if (param.part < 2 || param.error == 1 || ft_pathfinding(&param) == -1)
		ft_putendl("ERROR");
	return (0);
}
