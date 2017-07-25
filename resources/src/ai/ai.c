/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/25 09:18:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	delete_entite(void *content, size_t size)
{
	t_entite *a;

	a = (t_entite *)content;
	ft_bzero(a, sizeof(t_entite *));
	ft_free_tab(a->entite);
	free(content);
	// content_size = 0;
}

void assign_reponse(t_env *e, void *content)
{
	e->reponse.x = 7;
	e->reponse.y = 7;
}

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