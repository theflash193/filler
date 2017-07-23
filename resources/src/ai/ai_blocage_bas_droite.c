/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_blocage_bas_droite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:36:11 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/23 17:36:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int blocage_bas(t_entite plateau)
{
	int		i;
	int		j;
	int		score;
	t_coord bas;
	t_coord droite;

	score = 0;
	ft_bzero(&bas, sizeof(bas));
	ft_bzero(&droite, sizeof(droite));
	i = 0;
	bas = piece_plus_bas(plateau, 'o');
	droite = piece_plus_droite(plateau, 'o');
	if (bas.x == plateau.x)
		score = +1000;
	else
	{
		score = bas.x;
		score += droite.y;
	}
	return (score);
}

t_list 	*iter_bas(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage_bas(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}