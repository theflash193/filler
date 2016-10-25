/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:42:51 by ozdek             #+#    #+#             */
/*   Updated: 2016/10/25 17:20:29 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void player_number(t_env *e)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
	{
		e->nb_player = 1;
		e->ennemy = PLAYER_2_PIECE;
		e->player = PLAYER_1_PIECE;
		e->player_lm = PLAYER_1_LAST_MOVE;
	}
	else if (ft_strnequ(line, "$$$ exec p2", 11))
	{
		e->nb_player = 2;
		e->ennemy = PLAYER_1_PIECE;
		e->player = PLAYER_2_PIECE;
		e->player_lm = PLAYER_2_LAST_MOVE;
	}
	ft_strclean(line);
}

void	map_dimension(t_env *e)
{
	char	*line;
	char	**tab;

	line = NULL;
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	e->line = atoi(tab[1]);
	e->colonne = atoi(tab[2]);
	ft_strclean(line);
	ft_free_tab(tab);
}

void map(t_env *e)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	map_dimension(e);
	e->map = (char **)malloc(sizeof(char *) * e->line + 1);
	get_next_line(0, &line);
	ft_strclean(line);
	while (i < e->line)
	{
		get_next_line(0, &line);
		e->map[i++] = ft_strdup(line + 4);
		ft_strclean(line);
	}
	e->map[i] = 0;
}

void piece_dimension(t_env *e)
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
	// ft_put_array_fd(e->piece, 2);
}
