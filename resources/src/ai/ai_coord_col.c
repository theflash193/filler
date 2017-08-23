/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_coord_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:24:08 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 17:24:24 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// fonction qui cherche une piece joueur dans la colonne et retournant sa coordonné
t_coord coord_joueur_col(t_env *e, int y)
{
	t_coord count;

	count.x = 0;
	count.y = y;
	while (count.x < e->plateau.x)
	{
		if (piece_joueur(e->plateau.entite[count.x][count.y], e) == 1)
			return (count);
		count.x++;
	}
	count.x = 0;
	count.y = 0;
	return (count);
}

// fonction qui cherche une piece ennemie dans la colonne et retournant sa coordonné
t_coord coord_ennemie_col(t_env *e, int y)
{
	t_coord count;

	count.x = 0;
	count.y = y;
	while (count.x < e->plateau.x)
	{
		if (piece_ennemie(e->plateau.entite[count.x][count.y], e) == 1)
			return (count);
		count.x++;
	}
	count.x = 0;
	count.y = 0;
	return (count);
}