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

int		arraystr_len(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		arraystr_push_free(char **tab, char *str)
{
	int		i;
	char	**new_tab;
	char	**tmp;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * (arraystr_len(tab) + 2));
	if (new_tab == NULL)
	{
		printf("Error\n");
		return (-1);
	}
	while (tab != NULL && tab[i] != NULL)
	{
		new_tab[i] = tab[i];
		ft_putendl(new_tab[i]);
		i++;
	}
	new_tab[i] = (char *)malloc(ft_strlen(str) + 1);
	new_tab[i] = ft_strdup(str);
	new_tab[i + 1] = NULL;
	tmp = tab;
	tab = new_tab;
	free(tmp);
	return (1);
}

int		ft_tab_room_len(t_room *tab)
{
	int		i;

	i = 0;
	while (tab[i].name != NULL)
		i++;
	return (i);
}

t_room		*ft_add_roomname(t_param *param, char *roomname)
{
	t_room	*new_tab;
	int		i;

	i = 0;
	new_tab = (t_room *)malloc(sizeof(t_room) * (ft_tab_room_len(param->tab_room) + 2));
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

void	ft_print_arraystr(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putendl(tab[i]);
		i++;
	}
}


int		ft_room_exist(t_room *tab_room, char *roomname)
{
	int		i;

	i = 0;
	while (tab_room[i].name != NULL)
	{
		if (ft_strcmp(tab_room[i].name, roomname) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_start(t_room *tab_room)
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

char	*ft_get_end(t_room *tab_room)
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

int		ft_init_mat_adj(t_param *param)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_tab_room_len(param->tab_room) < 2 || ft_get_end(param->tab_room) == NULL || ft_get_start(param->tab_room) == NULL)
		return (-1);
	param->mat_adj = (t_room **)malloc(sizeof(t_room) * (ft_tab_room_len(param->tab_room) + 1));
	while (i < (ft_tab_room_len(param->tab_room) + 1))
	{
		param->mat_adj[i] = (t_room *)malloc(sizeof(t_room) * (ft_tab_room_len(param->tab_room) + 1));
		i++;
	}
	i = 2;
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
	param->mat_adj[0][1].name = ft_get_start(param->tab_room);
	param->mat_adj[1][0].name = ft_get_start(param->tab_room);
	param->mat_adj[0][ft_tab_room_len(param->tab_room)].name = ft_get_end(param->tab_room);
	param->mat_adj[ft_tab_room_len(param->tab_room)][0].name = ft_get_end(param->tab_room);
	return (1);
}

int		ft_link_bis(t_room **mat_adj, char *name, char *name2)
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

int		ft_link(t_param *param, char *link)
{
	char	**tab;

	if (ft_strchr(link, '-') == NULL)
		return (0);
	tab = ft_strsplit(link, '-');
	if (arraystr_len(tab) != 2)
		return (0);
	if (ft_room_exist(param->tab_room, tab[0]) != 1 || ft_room_exist(param->tab_room, tab[1]) != 1)
		return (0);
	ft_link_bis(param->mat_adj, tab[0], tab[1]);
	return (1);
}

int		ft_is_correct_line(char *line, t_param *param)
{
	char **tab;

	if (line == NULL || ft_strcmp(line, "") == 0 || ft_strcmp(line, "\n") == 0)
		return (0);
	if (line[0] == '#')
	{
		printf("Comm\n");
		if (ft_strcmp(line, "##start") == 0)
			param->comm = 1;
		if (ft_strcmp(line, "##end") == 0)
			param->comm = 2;
		return (1);
	}
	if (param->part == 0)
	{

		param->nbr_ant = ft_atoi(line);
		param->part++;
		return (1);
	}
	if (param->part == 1 && ft_strchr(line, ' ') != NULL)
	{
		tab = ft_strsplit(line, ' ');
		if (tab[0])
		{

			param->tab_room = ft_add_roomname(param, tab[0]);
			// verifier si coordonees entieres
		}
	}
	if (param->part == 1 && ft_strchr(line, ' ') == NULL)
	{
		//Definition des liems commence
		ft_init_mat_adj(param);
		if (ft_link(param, line) == 0)
			return (0);
		param->part++;
	}
	else if (param->part == 2)
	{
		printf("LIEN\n");
		if (ft_link(param, line) == 0)
		{
			printf("FIN\n");
			return (0);
		}
	}
	return (1);
}


void	ft_show_data_bis(t_room *tab_room)
{
	int		i;

	i = 0;
	while (tab_room && tab_room[i].name != NULL)
	{
		printf("Name Room = %s\n", tab_room[i].name);
		printf("Start = %d\n", tab_room[i].start);
		printf("\n");
		i++;
	}
}

void	ft_show_data_ter(t_room **mat_adj)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (i <= mat_adj[0][0].value)
	{
		while (j <= mat_adj[0][0].value)
		{
			if (i == 0 && j == 0)
				printf("%d ", mat_adj[0][0].value);
			else if (i == 0 || j == 0)
			{
				printf("%s ", mat_adj[i][j].name);
			}
			else
				printf("%d ", mat_adj[i][j].value);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}



int		main(int ac, char **av)
{
	int		i;
	t_param		param;

	i = 0;
	param.part = 0;
	param.comm = 0;
	param.tab_room->name = NULL;
	// param.mat_adj = (t_room **)malloc(sizeof(t_room) * 8);
	// while (i < 8)
	// {
	// 	param.mat_adj[i] = (t_room *)malloc(sizeof(t_room) * 8);
	// 	i++;
	// }
	// ft_create_test(&param);
	// ft_pathfinding(&param);
	char *line;
	char **tab;

	tab = NULL;
	if (ac < 0 || av == NULL)
	{
		printf("Error\n");
		return (-1);
	}
	while (get_next_line(0, &line) == 1 && ft_is_correct_line(line, &param) != 0)
	{
	}
	ft_show_data_ter(param.mat_adj);
	printf("end = %s\n", param.mat_adj[0][ft_tab_room_len(param.tab_room)].name);
	ft_pathfinding(&param);
	return (0);
}