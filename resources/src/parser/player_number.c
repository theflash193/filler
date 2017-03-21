/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:04:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	player_number(t_env *e)
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
