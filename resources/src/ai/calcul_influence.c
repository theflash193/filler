/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_influence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:21:13 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 19:21:26 by grass-kw         ###   ########.fr       */
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