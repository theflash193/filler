/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/30 16:01:50 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	parser_numero_joueur(&e);
	while (42)
	{
		parser_plateau(&e);
		parser_piece(&e);
		ai(&e);
		ai_reponse(0, 0);
		break ; 
	}
	return (0);
}
