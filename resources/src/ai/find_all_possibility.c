/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_possibility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:01:01 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**tentative_insertion_de_piece(t_env *e, int x, int y)
{
	if (piece_non_inserable(e, x, y, e->map) == 1)
		return (NULL);
	return (insertion_de_piece(e, x, y));
}

static void	init_choix(t_map **choix, t_env *e, char **tentative)
{
	choix = (t_map *)malloc(sizeof(t_map));
	choix->map = tentative;
	choix->line = e->line;
	choix->colonne = e->colonne;
	choix->player = e->nb_player;
	choix->points_influence_p1 = 0;
	choix->points_influence_p2 = 0;
	choix->nouvelle_pieces = stockage_nouvelle_piece(choix);
}

static void	init(t_list **all_possibility, t_map **choix, int *i)
{
	*all_possibility = NULL;
	*choix = NULL;
	*i = 0;
}

t_list		*find_all_possibility(t_env *e)
{
	int		i;
	int		j;
	t_map	*choix;
	char	**tentative;
	t_list	*all_possibility;

	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			tentative = tentative_insertion_de_piece(e, i, j);
			if (tentative != 0)
			{
				choix->x = i;
				choix->y = j;
				init_choix(&choix, e, tentative);
				ft_lst_push_back(&(all_possibility),
					ft_lstnew(choix, sizeof(t_map)));
			}
			j++;
		}
		i++;
	}
	return (all_possibility);
}
