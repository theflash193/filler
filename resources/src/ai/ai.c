/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/10 09:51:49 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// fonction qui cherche une piece joueur dans la colonne et retournant sa coordonné
t_coord coord_joueur_col(t_env *e, int y)
{
	t_coord count;

	count.x = 0;
	count.y = y;
	while (count.x < e->plateau.x)
	{
		if (piece_joueur(e->plateau.entite[count.x][count.y], e) == 1)
			return (count);
		count.x++;
	}
	count.x = 0;
	count.y = 0;
	return (count);
}

// fonction qui cherche une piece ennemie dans la colonne et retournant sa coordonné
t_coord coord_ennemie_col(t_env *e, int y)
{
	t_coord count;

	count.x = 0;
	count.y = y;
	while (count.x < e->plateau.x)
	{
		if (piece_ennemie(e->plateau.entite[count.x][count.y], e) == 1)
			return (count);
		count.x++;
	}
	count.x = 0;
	count.y = 0;
	return (count);
}

	t_coord joueur;
	t_coord ennemie;

t_direction direction_ennemie(t_env *e)
{
	// t_coord joueur;
	// t_coord ennemie;
	int y;

	y = e->plateau.y;
	while (y > 0)
	{
		joueur = coord_joueur_col(e, y);
		ennemie = coord_ennemie_col(e, y);
		if (piece_ennemie(e->plateau.entite[ennemie.x][ennemie.y], e) == 1 && piece_joueur(e->plateau.entite[joueur.x][joueur.y], e) == 1)
			break ;
		y--;
	}
	// core_message("joueur :");
	// core_coord(joueur);
	// core_message("ennemie :");
	// core_coord(ennemie);
	// exit(0);
	if (joueur.x < ennemie.x)
		return (BAS);
	return (HAUT);
}
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

void	analyse_plateau(t_env *e)
{
	t_coord piece_ennemie;
	t_coord piece_joueur;

	if (e->etat_machine == B_HAUT_DROIT)
	{
		piece_ennemie = piece_plus_gauche(e->plateau, 'x');
		if (piece_ennemie.y >= e->plateau.y / 2)
			e->etat_machine = B_BAS_DROIT;
	}
}

void	ai_action(t_env *e)
{
	t_list *score;

		core_message("joueur :");
	core_coord(joueur);
	core_message("ennemie :");
	core_coord(ennemie);
			if (e->remplissage == HAUT)
				core_message("ennemie haut");
			if (e->remplissage == BAS)
				core_message("ennemie bas");
	if (e->etat_machine == B_HAUT_DROIT || (e->etat_machine == REMPLISSAGE && e->remplissage == HAUT))
		score = ft_lstmap(e->liste_coup, iter_haut_droit);
	if (e->etat_machine == B_BAS_DROIT)
		score = ft_lstmap(e->liste_coup, iter_bas_droite);
	if (e->etat_machine == B_HAUT_GAUCHE)
		score = ft_lstmap(e->liste_coup, iter_haut_gauche);
	if (e->etat_machine == B_BAS_GAUCHE || (e->etat_machine == REMPLISSAGE && e->remplissage == BAS))
		score = ft_lstmap(e->liste_coup, iter_bas_gauche);
	ft_lstdel(&(e->liste_coup), delete_entite);
	e->liste_coup = score;
}

void	ai_camp_ennemie(t_env *e)
{
	t_coord gauche;
	t_coord droite;

	gauche = piece_joueur_plus_gauche(e->plateau, e);
	droite = piece_joueur_plus_droite(e->plateau, e);
	core_message("gauche :");
	core_coord(gauche);
	core_message("droite :");
	core_coord(droite);
}

void	ai(t_env *e)
{
	t_entite a;
	static int i = 0;

	// analyse_plateau(e);
	e->liste_coup = ai_recuperation_liste_coups(e);
	if (e->liste_coup != NULL)
	{
		// score = ft_lstmap(e->liste_coup, iter_haut_droit);
		if (e->etat_machine == REMPLISSAGE && i == 0)
		{
			// core_message("hello world");
			// exit(0);
			e->remplissage = direction_ennemie(e);
			i++;
		}
		ai_action(e);
		lst_bubble_sort(&(e->liste_coup), sort_best_move_p1);
		a = *(t_entite *)e->liste_coup->content;
		e->reponse = a.reponse;	
		if (a.score >= 1000 && e->etat_machine == B_HAUT_DROIT)
			e->etat_machine = B_BAS_DROIT;
		if (a.score >= 1000 && e->etat_machine == B_BAS_DROIT)
			{
				e->etat_machine = B_HAUT_DROIT;
				e->blocage1 = BAS;
			}
		if (a.score >= 1000 && e->etat_machine == B_HAUT_GAUCHE)
		{
			e->etat_machine = REMPLISSAGE;
			e->blocage2 = HAUT;
		}
		if (a.score >= 500 && e->etat_machine == B_HAUT_GAUCHE)
		{
			e->etat_machine = REMPLISSAGE;
			e->blocage2 = GAUCHE;
		}
		if (a.score >= 500 && e->etat_machine == B_HAUT_DROIT)
			{
				e->etat_machine = B_BAS_GAUCHE;
				e->blocage1 = DROITE;
			}
		if (a.score >= 500 && e->etat_machine == B_BAS_DROIT)
			e->etat_machine = B_HAUT_GAUCHE;
		// e->loop = 0;
	}
	else
		e->loop = 0;
}
