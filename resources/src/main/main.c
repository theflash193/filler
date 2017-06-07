/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/06/03 20:05:27 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	e.loop = 1;
	parser_numero_joueur(&e);
	while (e.loop)
	{
		parser_plateau(&e);
		parser_piece(&e);
		ai(&e);
		if (e.loop == 1)
			ai_reponse(e.reponse.x, e.reponse.y);
		else
			ai_reponse(0, 0);
	}
	return (0);
}
