/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:04:54 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void piece_dimension(t_env *e)
{
	char	*line;
	char	**tab;

	line = NULL;
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	e->piece_line = atoi(tab[1]);
	e->piece_colonne = atoi(tab[2]);
	ft_strclean(line);
	ft_free_tab(tab);
}

void piece(t_env *e)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	piece_dimension(e);
	e->piece = (char **)malloc(sizeof(char *) * e->piece_line + 1);
	while (i < e->piece_line)
	{
		get_next_line(0, &line);
		e->piece[i++] = ft_strdup(line);
		ft_strclean(line);
	}
	e->piece[i] = 0;
}

