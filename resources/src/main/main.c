/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/28 23:26:07 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
