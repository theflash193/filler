/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage_nouvelle_piece.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:00:48 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:00:51 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_piece(t_list **ret, int i, int j, t_coord **pieces)
{
	*pieces = (t_coord *)malloc(sizeof(t_coord));
	*pieces->x = i;
	*pieces->y = j;
	ft_lst_push_back(ret, ft_lstnew(*pieces, sizeof(t_coord)));
}

static void	init_piece(t_coord **piece, int i, int j)
{
	*piece->x = i;
	*piece->y = j;
}

t_list		*stockage_nouvelle_piece(t_map *choix)
{
	t_list	*ret;
	int		i;
	int		j;
	t_coord	*pieces;

	i = 0;
	ret = NULL;
	while (i < choix->line)
	{
		j = 0;
		while (j < choix->colonne)
		{
			if (choix->player == 1 && choix->map[i][j] == 'o')
				init_piece(ret, i, j, pieces);
			if (choix->player == 2 && choix->map[i][j] == 'x')
			{
				pieces = (t_coord *)malloc(sizeof(t_coord));
				init_piece(&pieces, i, j);
				ft_lst_push_back(&(ret), ft_lstnew(pieces, sizeof(t_coord)));
			}
			j++;
		}
		i++;
	}
	return (ret);
}
