/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_recherche_joueur.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:48:23 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/25 17:50:46 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// recherche la piece du joueur la plus en haut

t_coord		piece_joueur_plus_haute(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_joueur(PLATEAU[i][j], e) && ret.x > i)
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

// recherche la piece du joueur la plus en bas
t_coord		piece_joueur_plus_bas(t_entite plateau, t_env *e)
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
			if (piece_joueur(PLATEAU[i][j], e) && ret.x < i)
			{
				if (PLATEAU[i][j] == 'o')
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// recherche la piece du joueur la plus en gauche
t_coord		piece_joueur_plus_gauche(t_entite plateau, t_env *e)
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
			if (piece_joueur(PLATEAU[i][j], e) && ret.y > i)
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
// recherche la piece du joueur la plus en droite
t_coord		piece_joueur_plus_droite(t_entite plateau, t_env *e)
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
			if (piece_joueur(PLATEAU[i][j], e) && ret.y < j)
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
