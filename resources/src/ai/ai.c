/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/06/03 20:24:41 by grass-kw         ###   ########.fr       */
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
			if (e->piece.entite[i.x][i.y] == '*' && IS_PLAYER2(e->plateau.entite[p.x][p.y]))
				return (0);
			if (e->piece.entite[i.x][i.y] == '*' && IS_PLAYER1(e->plateau.entite[p.x][p.y]))
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

void	impression_plateau(t_env *e, int i, int j, t_entite	a)
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
			if (e->piece.entite[piece.x][piece.y] == '*' && a.entite[plateau.x][plateau.y] != 'o')
			{
				if (e->numero_joueur == 1)
					a.entite[plateau.x][plateau.y] = 'o';
				else
					a.entite[plateau.x][plateau.y] = 'x';
			}
			piece.y++;
			plateau.y++;
		}
		plateau.x++;
		piece.x++;
	}
	core_entite(a);
}

void	initialisation_entite(t_env *e, int i, int j)
{
	char	**plateau;
	int		count;

	count = 0;
	plateau = (char **)malloc(sizeof(char *) * e->plateau.x + 1);
	while (count < e->plateau.x)
	{
		plateau[count] = ft_strdup(e->plateau.entite[count]);
		count++;
	}
	plateau[count] = 0;
	t_entite a;
	a.entite = plateau;
	a.x = e->plateau.x;
	a.y = e->plateau.y;
	impression_plateau(e, i, j, a);
}

void	ai(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->plateau.x)
	{
		j = 0;
		while (j < e->plateau.y)
		{
			if (placement_possible(i, j, e) == 1)
			{
				initialisation_entite(e, i, j);
				e->reponse.x = i;
				e->reponse.y = j;
				e->loop = 0;
				return ;
			}
			j++;
		}
		i++;
	}
	e->loop = 0;
}
