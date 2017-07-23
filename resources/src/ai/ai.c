/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/23 17:13:23 by grass-kw         ###   ########.fr       */
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

// void iter_bas(t_list *elem)
// {
// 	blocage_bas(*(t_entite *)elem->content);
// }

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
// tri lst



// int			sort_best_move_p2(t_map *a, t_map *b)
// {
// 	if (a->points_influence_p1 == b->points_influence_p1)
// 		return (a->points_influence_p2 >= a->points_influence_p2);
// 	return (a->points_influence_p1 < a->points_influence_p1);
// }

static void	delete_entite(void *content, size_t size)
{
	t_entite *a;

	a = (t_entite *)content;
	ft_bzero(a, sizeof(t_entite *));
	ft_free_tab(a->entite);
	free(content);
	// content_size = 0;
}

void	ai(t_env *e)
{
	t_list	*score;

	e->liste_coup = ai_recuperation_liste_coups(e);
	score = ft_lstmap(e->liste_coup, iter_bas);
	ft_lstdel(&(e->liste_coup), delete_entite);
	e->liste_coup = score;
	lst_bubble_sort(&(e->liste_coup), sort_best_move_p1);
	ft_lstiter(e->liste_coup, core_coup);
	// e->loop = 0;
}

// void	ai(t_env *e)
// {
// 	t_list	*liste_coup;

// 	liste_coup = recuperation_liste_coups(e);
// 	if (liste_coup != NULL)
// 	{
// 		ft_lstiter(liste_coup, core_coup);
// 	}
// 	else
// 		e->loop = 0;
// }