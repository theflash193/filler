/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 13:51:56 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// int ft_sqrt(int val) // sqrt for int
// {
// 	int i;
// 	if (val <= 1) return val;	// 0, 1: special
// 	for (i = 0; i <= val / 2; i++) {
// 		if (i * i > val) break;
// 	}
// 	return (val <= i * (i - 1)) ? i - 1 : i;
// }

double	ft_sqrt(double nb)
{
	double calc;
	double diff;

	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	diff = 0.0;
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}

int		ft_pow(int nb, int pow)
{
	int ret;

	ret = nb;
	if (pow < 0)
		return (0);
	else if (pow == 0)
		return (1);
	while (pow-- > 1)
		ret *= nb;
	return (ret);
}

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

	score = ft_lstmap(e->liste_coup, iter_blocage);
	// if (e->etat_machine == B_HAUT_DROIT)
	// {
	// 	core_message("B_HAUT_DROIT");
	// 	score = ft_lstmap(e->liste_coup, iter_haut_droit);
	// }
	// if (e->etat_machine == B_BAS_DROIT)
	// {
	// 	core_message("B_BAS_DROITE ////////");
	// 	// exit(0);
	// 	score = ft_lstmap(e->liste_coup, iter_bas_droite);
	// }
	// if (e->etat_machine == B_HAUT_GAUCHE)
	// {
	// 	core_message("B_HAUT_GAUCHE");
	// 	score = ft_lstmap(e->liste_coup, iter_haut_gauche);
	// }
	// if (e->etat_machine == B_BAS_GAUCHE/* || (e->etat_machine == REMPLISSAGE && e->remplissage == BAS)*/)
	// {
	// 	core_message("B_BAS_GAUCHE");
	// 	score = ft_lstmap(e->liste_coup, iter_bas_gauche);
	// }
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
		core_int(a.score);
		// if ((a.score >= 1000 || a.score >= 500) && e->transition == 0)
		if ((a.score >= 1000) && e->transition == 0)
		{
			// core_message("cible atteint");
			
			// exit(0);
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

void core_direction(t_direction a)
{
	if (a == DROITE)
		core_message("DROITE");
	else if (a == GAUCHE)
		core_message("GAUCHE");
	else if (a == BAS)
		core_message("BAS");
	else if (a == HAUT)
		core_message("HAUT");
	else if (a == HAUT_DROITE)
		core_message("HAUT_DROIT");
	else if (a == BAS_DROITE)
		core_message("BAS_DROIT");
	else if (a == HAUT_GAUCHE)
		core_message("HAUT_GAUCHE");
	else
		core_message("BAS_GAUCHE");
}

void core_etat(t_etat_machine a)
{
	if (a == B_HAUT_DROIT)
		core_message("B_HAUT_DROIT");
	else if (a == B_BAS_DROIT)
		core_message("B_BAS_DROIT");
	else if (a == B_HAUT_GAUCHE)
		core_message("B_HAUT_GAUCHE");
	else if (a == B_BAS_GAUCHE)
		core_message("B_BAS_GAUCHE");
	else
		core_message("REMPLISSAGE");
}

t_coord position_blocage(void)
{
	t_env *e;
	t_coord ennemie_bas;
	t_coord position;

	e = singleton(NULL);
	ennemie_bas = piece_joueur_plus_bas(e->plateau, e);
	position.x = ennemie_bas.x;
	position.y = ennemie_bas.y;
	return (position);
}

void	ai(t_env *e)
{
	t_list *score;
	t_entite a;
	
	e->liste_coup = ai_recuperation_liste_coups(e);
	if (e->liste_coup != NULL)
	{
		// analyse de l'attaque ennemie
		
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
