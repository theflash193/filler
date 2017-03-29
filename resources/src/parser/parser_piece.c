/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:19:11 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/29 19:22:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		**creation_piece(int x, int y)
{
	char	*ligne;
	char	**plateau;
	int		count;

	count = 0;
	plateau = (char **)malloc(sizeof(char *) * (x + 1));
	while (count < x)
	{
		ligne = parser_iteration_ligne();
		plateau[count] = ft_strdup(ligne + 4);
		count++;
		ft_strclean(ligne);
	}
	plateau[x] = 0;
	return (plateau);
}

void	parser_piece(t_env *e)
{
	char		*ligne;
	char		**split;

	ligne = parser_iteration_ligne();
	split = ft_strsplit(ligne, ' ');
	e->plateau.x = ft_atoi(split[1]);
	e->plateau.y = ft_atoi(split[2]);
	ft_strclean(ligne);
	e->plateau.entite = creation_plateau(e->plateau.x, e->plateau.y);
}
