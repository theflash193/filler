/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/25 09:11:35 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void		suppression_env(t_env *e)
// {
// 	ft_bzero(e, sizeof(t_env));
// }

static void	delete_entite(void *content, size_t size)
{
	t_entite *a;

	a = (t_entite *)content;
	ft_bzero(a, sizeof(t_entite *));
	ft_free_tab(a->entite);
	free(content);
}

void		preparation_env(t_env *e)
{
	if (e->liste_coup != NULL)
	{
		ft_lstdel(&(e->liste_coup), delete_entite);
		e->liste_coup = NULL;
	}
	ft_free_tab(e->plateau.entite);
	ft_bzero(&(e->plateau), sizeof(t_entite));
	ft_free_tab(e->piece.entite);
	ft_bzero(&(e->piece), sizeof(t_piece));
}

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
		preparation_env(&e);
	}
	ft_bzero(&e, sizeof(t_env));
	return (0);
}
