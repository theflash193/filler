/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_bas_gauche.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:02:57 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/11 09:39:33 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// blocage vers le haut gauche
int blocage_bas_gauche(t_entite plateau)
{
	int		score;
	t_coord bas;
	t_coord gauche;
	t_env	*e;

	e = singleton(NULL);
	score = 0;
	if (e->numero_joueur == 1)
	{
		bas = piece_plus_bas(plateau, 'o');
		gauche = piece_plus_gauche(plateau, 'o');
	}
	else
	{
		bas = piece_plus_bas(plateau, 'x');
		gauche = piece_plus_gauche(plateau, 'x');
	}
	if (bas.x == plateau.x)
		score = +1000;
	else if (gauche.y == 0)
		score = 500;
	else
	{
		score = bas.x;
		score += plateau.y - gauche.y;
	}
	return (score);
}

//iter haut_gauche
t_list 	*iter_bas_gauche(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage_bas_gauche(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}