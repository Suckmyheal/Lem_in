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

// int		ft_is_correct_line(char *line, t_param *param)
// {
// 	int		i;
// 	int		nbr;

// 	i = 0;
// 	nbr = 0;
// 	if (line == NULL || ft_strcmp(line, "\n") == 0)
// 		return (-1);
// 	else if (line[0] == '#')
// 		return (1);
// 	if (param->salle == 0)
// 	{
// 		if (line[0] == 'L')
// 			return (-1);
// 		while (line[i] != ' ' && line[i])
// 			i++;
// 		line[i] == ' ' ? i++ : return (-1);	
// 		while (line[i])
// 		{
// 			if (ft_isdigit(line[i]) == 1 || line[i] == ' ')
// 			{
// 				line[i] == ' ' ? nbr = nbr + 1 : nbr = nbr + 0;
// 				i++;
// 			}
// 			else
// 				return (-1);
// 		}
// 		nbr > 1 ? return (-1) : return (1);
// 	}
// 	else if (param->tube == 0)
// 	{
// 		while (ft_isdigit(line[i]) == 1)
			
// 	}
// }


int		main(int ac, char **av)
{
	int		i;
	t_param		param;

	i = 0;
	param.mat_adj = (t_room **)malloc(sizeof(t_room) * 8);
	while (i < 8)
	{
		param.mat_adj[i] = (t_room *)malloc(sizeof(t_room) * 8);
		i++;
	}

	ft_create_test(&param);
	ft_pathfinding(&param);
	// char **line;
	// char **tab;

	// tab = NULL;
	// if (ac < 0 || av == NULL)
	// {
	// 	printf("Error\n");
	// 	return (-1);
	// }
	// while (get_next_line(0, line) == 1)
	// {
	// 	printf("test\n");
	// 	arraystr_push_free(tab, *line);
	// 	printf("test2\n");
	// 	// ft_print_arraystr(tab);
	// 	printf("test3\n");
	// }
	return (0);
}