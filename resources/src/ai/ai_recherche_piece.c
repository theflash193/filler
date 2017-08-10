/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_recherche_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:46:53 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/10 17:52:56 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord	piece_plus_bas(t_entite plateau, char c)
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
			if (PLATEAU[i][j] == c && ret.x < i)
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

t_coord	piece_plus_gauche(t_entite plateau, char c)
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
			if (PLATEAU[i][j] == c && ret.y > i)
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

t_coord	piece_plus_droite(t_entite plateau, char c)
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
			if (PLATEAU[i][j] == c && ret.y < i)
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

t_coord	piece_plus_haute(t_entite plateau, char c)
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
			if (PLATEAU[i][j] == c && ret.x > i)
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