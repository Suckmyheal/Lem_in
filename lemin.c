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

#include "libft/libft.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "lemin.h"

int		ft_is_correct_line(char *line, t_stat *param)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	if (line == NULL || line == "\n")
		return (-1);
	else if (line[0] == '#' && line[1] == '#')
		return (1);
	if (param->salle == 0)
	{
		if (line[0] == # || line[0] == 'L')
			return (-1);
		while (line[i] != ' ' && line[i])
			i++;
		line[i] == ' ' ? i++ : return (-1);	
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 1 || line[i] == ' ')
			{
				line[i] == ' ' ? nbr++ : nbr = nbr;
				i++;
			}
			else
				return (-1);
		}
		nbr > 1 ? return (-1) : return (1);
	}
	else if (param->tube == 1)
	{
		while (ft_isdigit(line[i]) == 1)
			
	}
}


int		main(int argc, char **argv)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		printf("%s\n", line);
	}
	return (0);
}