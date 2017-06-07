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
	t_coord	p;
	t_coord	i;
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
				e->reponse.x = i;
				e->reponse.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	e->loop = 0;
}
