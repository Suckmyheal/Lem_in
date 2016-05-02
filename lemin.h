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

typedef struct	s_room
{
	char	*name;
	char	**link;
	int		nbr_linl;
}				t_room;

typedef struct	s_param
{
	t_room	*name_room;
	int		tube;
	int		salle;

}				t_param;


#endif