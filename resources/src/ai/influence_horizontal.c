/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   influence_horizontal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:26:46 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 19:26:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	influence_horizontal(t_map *choix, t_coord coord, int player)
{
	int j;

	j = coord.y;
	if (player == 1)
	{
		j--;
		while (j >= 0 && choix->influence_p1[coord.x][j] == '.')
		{
			choix->influence_p1[coord.x][j] = '1';
			j--;
		}
		j = coord.y + 1;
		while (j < choix->colonne && choix->influence_p1[coord.x][j] == '.')
		{
			choix->influence_p1[coord.x][j] = '1';
			j++;
		}
	}
	if (player == 2)
	{
		j--;
		while (j >= 0 && choix->influence_p2[coord.x][j] == '.')
		{
			choix->influence_p2[coord.x][j] = '2';
			j--;
		}
		j = coord.y + 1;
		while (j < choix->colonne && choix->influence_p2[coord.x][j] == '.')
		{
			choix->influence_p2[coord.x][j] = '2';
			j++;
		}
	}
}