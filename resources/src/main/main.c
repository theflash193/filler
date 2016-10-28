/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/28 23:19:33 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	preparation_du_prochain_tour(t_env *e)
{
	char *line;

	line = NULL;
	e->piece_line = 0;
	e->piece_colonne = 0;
	if (e->piece != NULL)
	{
		ft_free_tab(e->piece);
		e->piece = NULL;
	}
	if (e->liste_possibilite != 0)
	{
		ft_lstdel(&(e->liste_possibilite), delete_map);
		e->liste_possibilite = NULL;
	}
	e->choice_x = 0;
	e->choice_y = 0;
}

void 	message(char *s)
{
	ft_putendl_fd(s, 2);
}

int			main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	player_number(&e);
	e.game_continue = 1;
	while (e.game_continue)
	{
		map(&e);
		piece(&e);
		thinking_strategy(&e);
		final_decision(&e);
		preparation_du_prochain_tour(&e);
	}
	clear_env(&e);
	return (0);
}
