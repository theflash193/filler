/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/25 09:30:27 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ai(t_env *e)
{
	t_list	*score;
	t_entite a;

	e->liste_coup = ai_recuperation_liste_coups(e);
	if (e->liste_coup != NULL)
	{
		score = ft_lstmap(e->liste_coup, iter_bas);
		ft_lstdel(&(e->liste_coup), delete_entite);
		e->liste_coup = score;
		lst_bubble_sort(&(e->liste_coup), sort_best_move_p1);
		e->reponse = ((t_entite *)e->liste_coup->content)->reponse;
	}
	else
		e->loop = 0;
}

// void	ai(t_env *e)
// {
// 	t_list	*liste_coup;

// 	liste_coup = ai_recuperation_liste_coups(e);
// 	if (liste_coup != NULL)
// 	{
// 		// ft_lstiter(liste_coup, core_coup);
// 	}
// 	else
// 		e->loop = 0;
// }