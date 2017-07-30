/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/30 19:32:06 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// fonction utils

// calcul piece jointe
int		piece_joueur(char c, t_env *e)
{
	if (e->numero_joueur == 1)
		return (IS_PLAYER1(c));
	return (IS_PLAYER2(c));
}

int		piece_ennemie(char c, t_env *e)
{
	if (e->numero_joueur == 1)
		return (IS_PLAYER2(c));
	return (IS_PLAYER1(c));
}

// fontion de calcul des dimensions du groupe du groupe de joueur

t_coord		dimensions_groupe_joueur(t_entite plateau, t_env *e)
{
	t_coord ret;
	t_coord gauche;
	t_coord droite;
	t_coord haute;
	t_coord bas;

	gauche = piece_joueur_plus_gauche(plateau, e);
	droite = piece_joueur_plus_droite(plateau, e);
	haute = piece_joueur_plus_haute(plateau, e);
	bas = piece_joueur_plus_bas(plateau, e);
	core_coord(haute);
	core_coord(bas);
	ret.x = haute.x - bas.x;
	ret.y = droite.y - gauche.y;
	return (ret);
}

// fonction de calcul des dimensions du groupe ennemie
// t_coord		dimensions_groupe_ennemie(t_entite plateau, t_env *e)
// {
// }

// blocage vers le haut droite

// end utils

void	ai(t_env *e)
{
	t_list	*score;
	t_entite a;

	e->liste_coup = ai_recuperation_liste_coups(e);
	if (e->liste_coup != NULL)
	{
		score = ft_lstmap(e->liste_coup, iter_haut_droit);
		// if (e->etat_machine == B_HAUT_DROIT)
		// 	score = ft_lstmap(e->liste_coup, iter_haut_droit);
		// else 
		// 	score = ft_lstmap(e->liste_coup, iter_bas_gauche);
		ft_lstdel(&(e->liste_coup), delete_entite);
		e->liste_coup = score;
		lst_bubble_sort(&(e->liste_coup), sort_best_move_p1);
		a = *(t_entite *)e->liste_coup->content;
		// t_coord test;

		// test = dimensions_groupe_joueur(a, e);
		// core_coord(test);
		e->reponse = a.reponse;
		if (a.score >= 1000 && e->etat_machine == B_HAUT_DROIT)
			e->etat_machine = B_BAS_DROIT;
		if (a.score >= 1000 && e->etat_machine == B_BAS_DROIT)
			e->etat_machine = B_HAUT_DROIT;
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