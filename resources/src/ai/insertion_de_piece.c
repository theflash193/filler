/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_de_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:01:07 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init(int x, int y, t_env *e, t_ip *a)
{
	a->new_map = array_cpy(e->map);
	a->i = x;
	a->j = y;
	a->k = 0;
}

char	**insertion_de_piece(t_env *e, int x, int y)
{
	t_ip	a;

	init(x, y, e, &a);
	while (a.k < e->piece_line)
	{
		a.l = 0;
		a.j = y;
		while (a.l < e->piece_colonne)
		{
			if (e->piece[a.k][a.l] == '*' && a.new_map[a.i][a.j] != e->player)
			{
      			  if (e->nb_player == 1)
				a.new_map[a.i][a.j] = 'o';
			  else
			      a.new_map[a.i][a.j] = 'x'; 
			}
			a.l++;
			a.j++;
		}
		a.i++;
		a.k++;
	}
	return (a.new_map);

}
