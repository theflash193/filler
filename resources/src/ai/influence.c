/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   influence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:19:15 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 19:19:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	influence(t_list *elem)
{
	t_map *choix;

	choix = (t_map *)elem->content;
	if (choix->player == 1)
	{
		choix->influence_p1 = array_cpy(choix->map);
		marquage_influence(choix, 1);
		choix->influence_p2 = array_cpy(choix->influence_p1);
		marquage_influence(choix, 2);
	}
	else
	{
		choix->influence_p2 = array_cpy(choix->map);
		marquage_influence(choix, 2);
		choix->influence_p1 = array_cpy(choix->influence_p2);
		marquage_influence(choix, 1);
	}
	choix->points_influence_p1 = calcul_influence(choix->influence_p1, 1);
	choix->points_influence_p2 = calcul_influence(choix->influence_p2, 2);
}