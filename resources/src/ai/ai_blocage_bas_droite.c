/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_bas_droite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:36:11 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 13:52:44 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int blocage_bas_droite(t_entite plateau)
{
	int		score;
	t_coord bas;
	t_coord droite;
	t_env *e;

	score = 0;
	e = singleton(NULL);
	score = 0;
	if (e->numero_joueur == 1)
	{
		bas = piece_plus_bas(plateau, 'o');
		droite = piece_plus_droite(plateau, 'o');
	}
	else
	{
		bas = piece_plus_bas(plateau, 'x');
		droite = piece_plus_droite(plateau, 'x');
	}
	if (bas.x == plateau.x - 1)
		score = +1000;
	else if (droite.y == plateau.y - 1)
		score = 500;
	else
	{
		score = bas.x;
		score += droite.y;
	}
	return (score);
}

t_list 	*iter_bas_droite(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage_bas_droite(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}

int piece_plus_proche(t_entite plateau, char c, t_coord cible)
{
	t_coord iter;
	int dist;

	iter.x = 0;
	iter.y = 0;
	dist = plateau.x * plateau.y;
	while (iter.x < plateau.x)
	{
		iter.y = 0;
		while (iter.y < plateau.y)
		{
			if (PLATEAU[iter.x][iter.y] == c && (distance(iter, cible) < dist))
				dist = distance(iter, cible);
			iter.y++;
		}
		iter.x++;
	}	
	return (dist);
}

int blocage(t_entite plateau)
{
	int		score;
	t_coord cible;
	t_coord proche;
	t_env *e;
	int dist;

	score = 0;
	dist = 0;
	e = singleton(NULL);
	cible.x = 0;
	cible.y = 0;
	if (e->numero_joueur == 1)
		dist = piece_plus_proche(plateau, 'o', cible);
	else
		dist = piece_plus_proche(plateau, 'x', cible);
	if (dist == 0)
	{
		score = 1000;
		core_entite(e->plateau);
	}
	else
		score = (e->plateau.x * e->plateau.y) - dist;
	return (score);
}

t_list 	*iter_blocage(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}