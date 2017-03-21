/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:01:21 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		thinking_strategy(t_env *e)
{
	t_map	*choix;

	e->liste_possibilite = find_all_possibility(e);
	if (e->liste_possibilite == NULL)
	{
		e->choice_x = 0;
		e->choice_y = 0;
		e->game_continue = 0;
	}
	else
	{
		print_possibilite(e->liste_possibilite);
		ft_lstiter(e->liste_possibilite, influence);
		if (e->nb_player == 1)
			lst_buble_sort(&(e->liste_possibilite), sort_best_move_p1);
		else
			lst_buble_sort(&(e->liste_possibilite), sort_best_move_p2);
		choix = (t_map *)e->liste_possibilite->content;
		e->choice_x = choix->x;
		e->choice_y = choix->y;
	}
}
