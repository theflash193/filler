/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/25 10:27:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// fonction utils
// recherche la piece du joueur la plus en haut
// recherche la piece du joueur la plus en bas
// recherche la piece du joueur la plus en gauche
// recherche la piece du joueur la plus en droite

// recherche la piece du ennemie la plus en haut
// recherche la piece du ennemie la plus en bas
// recherche la piece du ennemie la plus en gauche
// recherche la piece du ennemie la plus en droite

// fontion de calcul des dimensions du groupe du joueur
// fonction de calcul des dimensions du groupe ennemie

// blocage vers le haut droite
int blocage_haut_droit(t_entite plateau)
{
	int		i;
	int		j;
	int		score;
	t_coord haute;
	t_coord droite;

	score = 0;
	i = 0;
	haute = piece_plus_haute(plateau, 'o');
	droite = piece_plus_droite(plateau, 'o');
	if (haute.x == 0)
		score = +1000;
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
// end utils

void	ai(t_env *e)
{
	t_list	*score;
	t_entite a;

	e->liste_coup = ai_recuperation_liste_coups(e);
	if (e->liste_coup != NULL)
	{
		if (e->blocage == 0)
			score = ft_lstmap(e->liste_coup, iter_haut_droit);
		else 
			score = ft_lstmap(e->liste_coup, iter_bas);
		ft_lstdel(&(e->liste_coup), delete_entite);
		e->liste_coup = score;
		lst_bubble_sort(&(e->liste_coup), sort_best_move_p1);
		a = *(t_entite *)e->liste_coup->content;
		e->reponse = a.reponse;
		if (a.score >= 1000)
			e->blocage = 1;
		// e->loop = 0;
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

// l'idee est de cherche a avoir une coordonné precis de l'endroit ou on veut bloquer
// l'autre joueur
// pour cela on va chercher a choisir les coup qui nous raproche de ce point

// il faut d'abord choisir l'endroit
// ensuite on cherche le coup qui s'en rapproche