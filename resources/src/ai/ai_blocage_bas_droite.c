/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_bas_droite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:36:11 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/11 09:32:29 by grass-kw         ###   ########.fr       */
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