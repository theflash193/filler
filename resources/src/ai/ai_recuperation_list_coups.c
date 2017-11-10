/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_recuperation_list_coups.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:40:47 by grass-kw          #+#    #+#             */
/*   Updated: 2017/11/10 20:05:10 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int placement_possible(int x, int y, t_env *e)
{
	t_coord		p;
	t_coord		i;
	int			recouvre_forme;

	recouvre_forme = 0;
	p.x = x;
	p.y = y;
	if ((p.x + e->piece.x > e->plateau.x) || (p.y + e->piece.y > e->plateau.y)) // je verifie que mon plateau entre dans cette position
		return (0);
	i.x = 0;
	while (i.x < e->piece.x)
	{
		i.y = 0;
		p.y = y;
		while (i.y < e->piece.y)
		{
			if (e->piece.entite[i.x][i.y] == '*' && piece_ennemie(e->plateau.entite[p.x][p.y], e))
				return (0);
			if (e->piece.entite[i.x][i.y] == '*' && piece_joueur(e->plateau.entite[p.x][p.y], e))
				recouvre_forme++;
			i.y++;
			p.y++;
		}
		i.x++;
		p.x++;
	}
	if (recouvre_forme != 1)
		return (0);
	return (1);
}

static t_entite	impression_piece(t_env *e, int i, int j, t_entite a)
{
	t_coord piece;
	t_coord	plateau;

	piece.x = 0;
	plateau.x = i;
	while (piece.x < e->piece.x)
	{
		piece.y = 0;
		plateau.y = j;
		while (piece.y < e->piece.y)
		{
			if (e->piece.entite[piece.x][piece.y] == '*' && a.entite[plateau.x][plateau.y] != 'O' && e->numero_joueur == 1)
				a.entite[plateau.x][plateau.y] = 'o';
			if (e->piece.entite[piece.x][piece.y] == '*' && a.entite[plateau.x][plateau.y] != 'X' && e->numero_joueur == 2)
				a.entite[plateau.x][plateau.y] = 'x';
			piece.y++;
			plateau.y++;
		}
		plateau.x++;
		piece.x++;
	}
	return (a);
}

static t_entite	sauvegarde_plateau(t_env *e, int i, int j)
{
	char	**plateau;
	int		count;
	t_entite a;

	count = 0;
	plateau = (char **)malloc(sizeof(char *) * e->plateau.x + 1);
	while (count < e->plateau.x)
	{
		plateau[count] = ft_strdup(e->plateau.entite[count]);
		count++;
	}
	plateau[count] = 0;
	a.entite = plateau;
	a.x = e->plateau.x;
	a.y = e->plateau.y;
	a.reponse.x = i;
	a.reponse.y = j;
	impression_piece(e, i, j, a);
	return (a);
}
// 
t_list	*ai_recuperation_liste_coups(t_env *e)
{
	t_list		*liste_coup;
	t_entite	coup;
	int			i;
	int			j;

	i = 0;
	liste_coup = NULL;
	while (i < e->plateau.x)
	{
		j = 0;
		while (j < e->plateau.y)
		{
			if (placement_possible(i, j, e) == 1)
			{
				coup = sauvegarde_plateau(e, i, j);
				ft_lst_push_back(&liste_coup, ft_lstnew(&coup, sizeof(t_entite)));
				e->reponse.x = i;
				e->reponse.y = j;
			}
			j++;
		}
		i++;
	}
	return (liste_coup);
}