/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   influence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:02:35 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calcul_influence(char **map, int player)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (player == 1 && map[i][j] == '1')
				count++;
			if (player == 2 && map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

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
