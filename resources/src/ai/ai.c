/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 17:28:24 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_direction direction_ennemie(t_env *e)
{
	t_coord joueur;
	t_coord ennemie;
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
	if (joueur.x < ennemie.x)
		return (BAS);
	return (HAUT);
}
// fonction utils


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

	score = ft_lstmap(e->liste_coup, iter_blocage);
	if (e->blocage1 || e->blocage2)
	{
		core_message("BLOCAGE");
		score = ft_lstmap(e->liste_coup, iter_blocage);
	}
	else if (e->etat_machine == B_HAUT_DROIT)
	{
		core_message("B_HAUT_DROIT");
		score = ft_lstmap(e->liste_coup, iter_haut_droit);
	}
	else if (e->etat_machine == B_BAS_DROIT)
	{
		core_message("B_BAS_DROITE ////////");
		// exit(0);
		score = ft_lstmap(e->liste_coup, iter_bas_droite);
	}
	else if (e->etat_machine == B_HAUT_GAUCHE)
	{
		core_message("B_HAUT_GAUCHE");
		score = ft_lstmap(e->liste_coup, iter_haut_gauche);
	}
	else if (e->etat_machine == B_BAS_GAUCHE/* || (e->etat_machine == REMPLISSAGE && e->remplissage == BAS)*/)
	{
		core_message("B_BAS_GAUCHE");
		score = ft_lstmap(e->liste_coup, iter_bas_gauche);
	}
	else
	{
		core_message("B_BAS_GAUCHE");
		score = ft_lstmap(e->liste_coup, iter_bas_gauche);
	}
	ft_lstdel(&(e->liste_coup), delete_entite);
	e->liste_coup = score;
}

t_etat_machine direction_remplissage(t_direction a, t_direction b)
{
	if (a == HAUT && b == DROITE)
		return (B_HAUT_DROIT);
	if (a == HAUT && b == GAUCHE)
		return (B_HAUT_GAUCHE);
	if (a == BAS && b == DROITE)
		return (B_BAS_DROIT);
	return (B_BAS_GAUCHE);
}

void	transition_etat(t_env *e)
{
		t_entite a;

		a = *(t_entite *)e->liste_coup->content;
		// exit(0);
		// core_int(a.score);
			core_message("score : ");
			core_int(a.score);
		// if ((a.score >= 1000 || a.score >= 500) && e->transition == 0)
		// blocage cas particulier map02
		if ((a.score >= 1000) && e->blocage1 == 1)
		{
			// exit(0);
			// core_message("hello");
			e->blocage1 = 0;
			e->blocage2 = 1;
			core_message("blocage1");
		}
		else if ((a.score >= 1000) && e->blocage2 == 1)
		{
			core_message("blocage2");
			e->blocage2 = 0;
		}
		// end blocage cas particulier map02
		else if ((a.score >= 1000) && e->transition == 0)
		{
			e->yolo = 1;
			e->etat_machine = e->etat2;
			e->transition++;
		}
		else if ((a.score >= 1000 || a.score >= 500) && e->transition == 1)
		{
			core_message("transition 2");
			// exit(0);
			e->etat_machine = REMPLISSAGE;
			e->transition++;
		}
}

void	analyse_blocage(t_env *e)
{
	t_coord ennemie_bas;
	t_coord ennemie_droite;
	t_coord position;
	t_coord joueur_haute;

	e = singleton(NULL);
	if (e->blocage1)
	{
		ennemie_bas = piece_ennemie_plus_bas(e->plateau, e);
		joueur_haute = piece_joueur_plus_haute(e->plateau, e);
		e->cible.x = e->debut.x;
		e->cible.y = 0;
	}
	if (e->blocage2)
	{
		ennemie_droite = piece_ennemie_plus_droite(e->plateau, e);
		joueur_haute = piece_joueur_plus_haute(e->plateau, e);
		e->cible.x = e->debut.y;
		e->cible.y = e->plateau.y - 1;
	}
	core_coord(e->cible);
}

void	construction_barrage()
{
	
}

void	ai(t_env *e)
{
	t_list *score;
	t_entite a;
	
	e->liste_coup = ai_recuperation_liste_coups(e);
	if (e->liste_coup != NULL)
	{
		// analyse de l'attaque ennemie
		analyse_blocage(e);
		if (e->etat_machine == REMPLISSAGE)
		{
			e->remplissage = direction_ennemie(e);
			e->etat_machine = direction_remplissage(e->remplissage, e->cote_ennemie);
			core_message("remplissage : cote : etat machine");
			core_direction(e->remplissage);
			core_direction(e->cote_ennemie);
			core_etat(e->etat_machine);
			core_message("");
		}
		ai_action(e);
		lst_bubble_sort(&(e->liste_coup), sort_best_move_p1);
		a = (*(t_entite *)e->liste_coup->content);
		// core_entite(a);
		e->reponse.x = a.reponse.x;
		e->reponse.y = a.reponse.y;
		transition_etat(e);
	}
	else
		e->loop = 0;
}
