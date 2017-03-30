/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:19:11 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/30 16:02:33 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		**creation_piece(int x, int y)
{
	char	*ligne;
	char	**piece;
	int		count;

	count = 0;
	piece = (char **)malloc(sizeof(char *) * (x + 1));
	while (count < x)
	{
		ligne = parser_iteration_ligne();
		piece[count] = ft_strdup(ligne);
		count++;
		ft_strclean(ligne);
	}
	piece[x] = 0;
	return (piece);
}

void			parser_piece(t_env *e)
{
	char		*ligne;
	char		**split;

	ligne = parser_iteration_ligne();
	split = ft_strsplit(ligne, ' ');
	e->piece.x = ft_atoi(split[1]);
	e->piece.y = ft_atoi(split[2]);
	ft_strclean(ligne);
	e->piece.entite = creation_piece(e->piece.x, e->piece.y);
}
