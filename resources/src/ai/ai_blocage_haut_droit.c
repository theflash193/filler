/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_haut_droit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:15:02 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/11 09:21:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int blocage_haut_droit(t_entite plateau)
{
	int		score;
	t_coord haute;
	t_coord droite;
	t_env *e;

	score = 0;
	e = singleton(NULL);
	score = 0;
	if (e->numero_joueur == 1)
	{
		haute = piece_plus_haute(plateau, 'o');
		droite = piece_plus_droite(plateau, 'o');
	}
	else
	{
		haute = piece_plus_haute(plateau, 'x');
		droite = piece_plus_droite(plateau, 'x');
	}
	if (haute.x == 0)
		score = 1000;
	else if (droite.y == plateau.y - 1)
		score = 500;	
	else
	{
		score = (plateau.x - haute.x) * 2;
		score += droite.y;
	}
	return (score);
}

//iter haut_droite
t_list 	*iter_haut_droit(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage_haut_droit(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}