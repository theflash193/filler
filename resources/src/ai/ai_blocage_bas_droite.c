/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_bas_droite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:36:11 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/08 14:50:38 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int blocage_bas_droite(t_entite plateau)
{
	int		i;
	int		j;
	int		score;
	t_coord bas;
	t_coord droite;

	score = 0;
	i = 0;
	bas = piece_plus_bas(plateau, 'o');
	droite = piece_plus_droite(plateau, 'o');
	if (bas.x == plateau.x || droite.y == plateau.y)
		score = +1000;
	if (droite.y == plateau.y - 1)
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