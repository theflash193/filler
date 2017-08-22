/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_haut_gauche.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:03:24 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/11 09:34:44 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int blocage_haut_gauche(t_entite plateau)
{
	int		score;
	t_coord haute;
	t_coord gauche;
	t_env	*e;

	e = singleton(NULL);
	score = 0;
	if (e->numero_joueur == 1)
	{
		haute = piece_plus_haute(plateau, 'o');
		gauche = piece_plus_gauche(plateau, 'o');
	}
	else
	{
		haute = piece_plus_haute(plateau, 'x');
		gauche = piece_plus_gauche(plateau, 'x');
	}
	if (haute.x == 0)
		score = +1000;
	else if (gauche.y == 0)
		score = 500;
	else
	{
		score = plateau.x - haute.x;
		score += plateau.y - gauche.y;
	}
	return (score);
}

//iter haut_gauche
t_list 	*iter_haut_gauche(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage_haut_gauche(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}