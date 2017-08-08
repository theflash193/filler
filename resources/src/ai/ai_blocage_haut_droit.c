/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_haut_droit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:15:02 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/08 14:50:45 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	contact_ennemie(t_entite plateau, t_coord droite)
{
	if ((droite.y + 1 >= plateau.y) && IS_PLAYER2(PLATEAU[droite.x][droite.y + 1]))
		return (1);
	if ((droite.y - 1 >= 0) && IS_PLAYER2(PLATEAU[droite.x][droite.y - 1]))
		return (1);
	if ((droite.x + 1 >= plateau.y) && IS_PLAYER2(PLATEAU[droite.x + 1][droite.y]))
		return (1);
	if ((droite.x + 1 >= 0) && IS_PLAYER2(PLATEAU[droite.x - 1][droite.y + 1]))
		return (1);
	return (0);
}

int blocage_haut_droit(t_entite plateau)
{
	int		score;
	t_coord haute;
	t_coord droite;

	// core_message("hello world");
	score = 0;
	haute = piece_plus_haute(plateau, 'o');
	droite = piece_plus_droite(plateau, 'o');
	if (haute.x == 0 || droite.y == plateau.y)
		score = 1000;
	if (droite.y == plateau.y - 1)
		score = 500;	
	else
	{
		score = plateau.x - haute.x;
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