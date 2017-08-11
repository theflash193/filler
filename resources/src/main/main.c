/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/10 19:03:01 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	delete_entite(void *content, size_t size)
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
	int i = 0;

	ft_bzero(&e, sizeof(t_env));
	e.loop = 1;
	e.etat_machine = B_HAUT_GAUCHE;
	e.transition = 0;
	parser_numero_joueur(&e);
	while (e.loop)
	{
		parser_plateau(&e);
		parser_piece(&e);
		ai_position_groupes(&e);
		// core_message("jojo");
		// exit(0);
		ai(&e);
		if (e.loop == 1)
		{
			ai_reponse(e.reponse.x, e.reponse.y);
			i++;
		}
		else
			ai_reponse(0, 0);
		preparation_env(&e);
	}
	ft_bzero(&e, sizeof(t_env));
	return (0);
}
