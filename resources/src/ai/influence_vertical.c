/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   influence_vertical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:26:38 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 19:27:00 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	influence_vertical(t_map *choix, t_coord coord, int player)
{
	int i;

	i = coord.x - 1;
	if (player == 1)
	{
		while (i >= 0 && choix->influence_p1[i][coord.y] == '.')
		{
			choix->influence_p1[i][coord.y] = '1';
			i--;
		}
		i = coord.x + 1;
		while (i < choix->line && choix->influence_p1[i][coord.y] == '.')
		{
			choix->influence_p1[i][coord.y] = '1';
			i++;
		}
	}
	if (player == 2)
	{
		i = coord.x - 1;
		while (i >= 0 && choix->influence_p2[i][coord.y] == '.')
		{
			choix->influence_p2[i][coord.y] = '2';
			i--;
		}
		i = coord.x + 1;
		while (i < choix->line && choix->influence_p2[i][coord.y] == '.')
		{
			choix->influence_p2[i][coord.y] = '2';
			i++;
		}
	}
}