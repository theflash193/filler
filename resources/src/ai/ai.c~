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

static void mi(int i, int j)
{
	ft_putnbr_fd(i, 2);
	ft_putchar_fd(',', 2);
	ft_putnbr_fd(j, 2);
	ft_putchar_fd('\n', 2);
}

int placement_possible(int x, int y, t_env *e)
{
	t_coord	p; // counteur plateau
	t_coord	i; // counteur piece
	int			recouvre_forme;

	// mi(x, y);
	recouvre_forme = 0;
	p.x = x;
	p.y = y;
	if ((p.x + e->piece.x > e->plateau.x) || (p.y + e->piece.y > e->plateau.y)) // je verifie que mon plateau entre dans cette position
	{
		core_message("taille trop grande");
		return (0);
	}
	i.x = 0; // je parcours ma piece
	while (i.x < e->piece.x)
	{
		i.y = 0;
		p.y = y;
		while (i.y < e->piece.y)
		{
			// si ma forme est sur une case joeur adverse faux
				ft_putchar_fd(e->piece.entite[i.x][i.y], 2);
				ft_putchar_fd('\n', 2);
				ft_putchar_fd(e->plateau.entite[p.x][p.y], 2);
				ft_putchar_fd('\n', 2);
			if (e->piece.entite[i.x][i.y] == '*' && IS_PLAYER2(e->plateau.entite[p.x][p.y]))
			{
				return (0);
				core_message("recouvre enemie");
			}
			// si ma forme est sur une case precedement posé
			if (e->piece.entite[i.x][i.y] == '*' && IS_PLAYER1(e->plateau.entite[p.x][p.y]))
			{
				core_message("recouvre forme");
				recouvre_forme++;
			}
			i.y++;
			p.y++;
		}
		i.x++;
		p.x++;
	}
	if (recouvre_forme != 1)
	{
		core_message("forme superieur a 1");
		return (0);
	}
	ft_putnbr_fd(recouvre_forme, 2);
	ft_putchar_fd('\n', 2);		
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
				break ;
			}
			j++;
		}
		i++;
	}
	e->jeu_terminer = 1;
}
