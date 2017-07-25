/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/25 15:51:28 by grass-kw         ###   ########.fr       */
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

// recherche la piece du joueur la plus en haut


t_coord		piece_joueur_plus_haute(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_joueur(PLATEAU[i][j], e) && ret.x > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

// recherche la piece du joueur la plus en bas
t_coord		piece_joueur_plus_bas(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_joueur(PLATEAU[i][j], e) && ret.x < i)
			{
				if (PLATEAU[i][j] == 'o')
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// recherche la piece du joueur la plus en gauche
t_coord		piece_joueur_plus_gauche(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_joueur(PLATEAU[i][j], e) && ret.y > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// recherche la piece du joueur la plus en droite
t_coord		piece_joueur_plus_droite(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_joueur(PLATEAU[i][j], e) && ret.y < j)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

// recherche la piece ennemie la plus en haut
t_coord		piece_ennemie_plus_haute(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.x > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// recherche la piece ennemie la plus en bas
t_coord		piece_ennemie_plus_bas(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.x < i)
			{
				if (PLATEAU[i][j] == 'o')
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// // recherche la piece ennemie la plus en gauche
t_coord		piece_ennemie_plus_gauche(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_joueur(PLATEAU[i][j], e) && ret.y > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
// // recherche la piece ennemie la plus en droite
t_coord		piece_ennemie_plus_droite(t_entite plateau, t_env *e)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (piece_ennemie(PLATEAU[i][j], e) && ret.y < j)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

// fontion de calcul des dimensions du groupe du joueur
// t_coord		dimensions_groupe_joueur(t_entite plateau, t_env *e)
// {
// }
// fonction de calcul des dimensions du groupe ennemie
// t_coord		dimensions_groupe_ennemie(t_entite plateau, t_env *e)
// {
// }

// blocage vers le haut droite
int blocage_haut_droit(t_entite plateau)
{
	int		score;
	t_coord haute;
	t_coord droite;

	score = 0;
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
		t_coord test;

		test = piece_joueur_plus_droite(e->plateau, e);
		core_coord(test);
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