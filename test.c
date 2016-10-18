/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:22:22 by nbelkaid          #+#    #+#             */
/*   Updated: 2016/10/05 15:22:26 by nbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_create_test(t_param *param)
{
	printf("%d\n", param->mat_adj[0][0].value = 7);
	printf("%s/n", param->mat_adj[0][1].name = ft_strdup("Depart"));
	printf("%s/n", param->mat_adj[0][2].name = ft_strdup("a"));
	printf("%s/n", param->mat_adj[0][3].name = ft_strdup("b"));
	printf("%s/n", param->mat_adj[0][4].name = ft_strdup("c"));
	printf("%s/n", param->mat_adj[0][5].name = ft_strdup("d"));
	printf("%s/n", param->mat_adj[0][6].name = ft_strdup("e"));
	printf("%s/n", param->mat_adj[0][7].name = ft_strdup("Arrive"));

	printf("\n");
	printf("%s/n", param->mat_adj[1][0].name = ft_strdup("Depart"));
	printf("%d\n", param->mat_adj[1][1].value = 0);
	printf("%d\n", param->mat_adj[1][2].value = 1);
	printf("%d\n", param->mat_adj[1][3].value = 1);
	printf("%d\n", param->mat_adj[1][4].value = 0);
	printf("%d\n", param->mat_adj[1][5].value = 0);
	printf("%d\n", param->mat_adj[1][6].value = 0); 
	printf("%d\n", param->mat_adj[1][7].value = 0);

	printf("\n");
	printf("%s\n", param->mat_adj[2][0].name = ft_strdup("a"));
	printf("%d\n", param->mat_adj[2][1].value = 1);
	printf("%d\n", param->mat_adj[2][2].value = 0);
	printf("%d\n", param->mat_adj[2][3].value = 0);
	printf("%d\n", param->mat_adj[2][4].value = 1);
	printf("%d\n", param->mat_adj[2][5].value = 0);
	printf("%d\n", param->mat_adj[2][6].value = 0);
	printf("%d\n", param->mat_adj[2][7].value = 0);

	printf("\n");	
	printf("%s\n", param->mat_adj[3][0].name = ft_strdup("b"));
	printf("%d\n", param->mat_adj[3][1].value = 1);
	printf("%d\n", param->mat_adj[3][2].value = 0);
	printf("%d\n", param->mat_adj[3][3].value = 0);
	printf("%d\n", param->mat_adj[3][4].value = 1);
	printf("%d\n", param->mat_adj[3][5].value = 1);
	printf("%d\n", param->mat_adj[3][6].value = 0);
	printf("%d\n", param->mat_adj[3][7].value = 0);

	printf("\n");
	printf("%s\n", param->mat_adj[4][0].name = ft_strdup("c"));
	printf("%d\n", param->mat_adj[4][1].value = 0);
	printf("%d\n", param->mat_adj[4][2].value = 1);
	printf("%d\n", param->mat_adj[4][3].value = 1);
	printf("%d\n", param->mat_adj[4][4].value = 0);
	printf("%d\n", param->mat_adj[4][5].value = 1);
	printf("%d\n", param->mat_adj[4][6].value = 0);
	printf("%d\n", param->mat_adj[4][7].value = 0);

	printf("\n");
	printf("%s\n", param->mat_adj[5][0].name = ft_strdup("d"));
	printf("%d\n", param->mat_adj[5][1].value = 0);
	printf("%d\n", param->mat_adj[5][2].value = 0);
	printf("%d\n", param->mat_adj[5][3].value = 1);
	printf("%d\n", param->mat_adj[5][4].value = 1);
	printf("%d\n", param->mat_adj[5][5].value = 0);
	printf("%d\n", param->mat_adj[5][6].value = 1);
	printf("%d\n", param->mat_adj[5][7].value = 0);

	printf("\n");
	printf("%s\n", param->mat_adj[6][0].name = ft_strdup("e"));
	printf("%d\n", param->mat_adj[6][1].value = 0);
	printf("%d\n", param->mat_adj[6][2].value = 0);
	printf("%d\n", param->mat_adj[6][3].value = 0);
	printf("%d\n", param->mat_adj[6][4].value = 0);
	printf("%d\n", param->mat_adj[6][5].value = 1);
	printf("%d\n", param->mat_adj[6][6].value = 0);
	printf("%d\n", param->mat_adj[6][7].value = 0);

	printf("\n");
	printf("%s\n", param->mat_adj[7][0].name = ft_strdup("Arrive"));
	printf("%d\n", param->mat_adj[7][1].value = 0);
	printf("%d\n", param->mat_adj[7][2].value = 0);
	printf("%d\n", param->mat_adj[7][3].value = 0);
	printf("%d\n", param->mat_adj[7][4].value = 0);
	printf("%d\n", param->mat_adj[7][5].value = 0);
	printf("%d\n", param->mat_adj[7][6].value = 0);
	printf("%d\n", param->mat_adj[7][7].value = 0);
	return (1);
}