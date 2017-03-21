/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marquage_influence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:26:00 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 19:27:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	marquage_influence(t_map *choix, int player)
{
	char	**tmp;
	t_coord	coord;

	tmp = (player == 1) ? choix->influence_p1 : choix->influence_p2;
	coord.x = 0;
	while (tmp[coord.x])
	{
		coord.y = 0;
		while (tmp[coord.x][coord.y])
		{
			if (player == 1 && IS_PLAYER1(tmp[coord.x][coord.y]))
			{
				influence_horizontal(choix, coord, player);
				influence_vertical(choix, coord, player);
			}
			if (player == 2 && IS_PLAYER2(tmp[coord.x][coord.y]))
			{
				influence_horizontal(choix, coord, player);
				influence_vertical(choix, coord, player);
			}
			coord.y++;
		}
		coord.x++;
	}
}