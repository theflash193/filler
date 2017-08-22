/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_recherche_ennemie.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:54:28 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/11 09:33:46 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// recherche la piece ennemie la plus en haut
t_coord		piece_ennemie_plus_haute(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.x > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// recherche la piece ennemie la plus en bas
t_coord		piece_ennemie_plus_bas(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.x < i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// // recherche la piece ennemie la plus en gauche
t_coord		piece_ennemie_plus_gauche(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.y > j)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

// // recherche la piece ennemie la plus en droite
t_coord		piece_ennemie_plus_droite(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.y < j)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}