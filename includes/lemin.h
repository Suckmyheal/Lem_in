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
# include "../libft/libft.h"
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"

# define NBR_ROOM param->mat_adj[0][0].value

typedef struct	s_room
{
	char	*name;
	int		value;
	int		start;
	int		nbr_ant;
	int		ant_name;
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
	t_room	*tab_room;
	t_poids	*tab_poids;
	t_ante	*tab_ant;
	t_room	*path;
	int		part;
	int		nbr_ant;
	int		comm;
	int		error;
}				t_param;

int				ft_init_tables(t_param *param);
char			*ft_min_poids(t_poids *tab_poids, int nbr_room);
int				ft_passed(t_poids *tab_poids, int nbr_room, char *name);
int				ft_tab_index(t_poids *tab_poids, int nbr_room, char *name);
int				ft_get_poids(t_poids *tab_poids, char *roomname);
char			*ft_get_ante(t_ante *tab_ant, char *roomname);
void			ft_fill_path(t_param *param);
void			ft_put_move(int ant_name, char *roomname);
void			ft_display_end(t_room *path, int nbr_ant, int poids, int i);
void			ft_path_2(t_param *param, int *j, int *i, char *tmp);
void			ft_path_3(t_param *param);
int				ft_pathfinding(t_param *param);
int				arraystr_len(char **tab);
int				ft_is_strnum(char *str);
int				arraystr_push_free(t_param *param, char *str);
int				ft_tab_room_len(t_room *tab);
t_room			*ft_add_roomname(t_param *param, char *roomname);
void			ft_print_arraystr(char **tab);
int				ft_room_exist(t_room *tab_room, char *roomname);
char			*ft_get_start(t_room *tab_room);
char			*ft_get_end(t_room *tab_room);
int				ft_init_2(t_param *param);
void			ft_init_3(t_param *param);
int				ft_init_mat_adj(t_param *param);
int				ft_link_bis(t_room **mat_adj, char *name, char *name2);
int				ft_link(t_param *param, char *link);
int				ft_is_correc_2(t_param *param, char *line);
int				ft_is_correc_3(t_param *param, char *line);
int				ft_is_correc_4(t_param *param, char *line);
int				ft_is_correct_line(char *line, t_param *param);
int				main(int ac, char **av);

#endif
