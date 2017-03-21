/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_non_inserable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:01:14 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init(int x, int y, t_pni *a)
{
	a->nombre_de_piece_joueur = 0;
	a->i = x;
	a->j = y;
}

int			piece_non_inserable(t_env *e, int x, int y, char **new_map)
{
	t_pni	a;

	init(x, y, &a);
	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (1);
	a.k = 0;
	while (a.k < e->piece_line)
	{
		a.l = 0;
		a.j = y;
		while (a.l < e->piece_colonne)
		{
			if (is_ennemy(new_map[a.i][a.j], e) && e->piece[a.k][a.l] == '*')
				return (1);
			if (is_player(new_map[a.i][a.j], e) && e->piece[a.k][a.l] == '*')
				a.nombre_de_piece_joueur++;
			a.l++;
			a.j++;
		}
		a.i++;
		a.k++;
	}
	if (a.nombre_de_piece_joueur != 1)
		return (1);
	return (0);
}
