/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 13:51:37 by grass-kw         ###   ########.fr       */
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

t_env	*singleton(t_env *e)
{
	static t_env *ret = NULL;

	if (e != NULL)
		ret = e;
	return (ret);
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
	singleton(&e);
	while (e.loop)
	{
		parser_plateau(&e);
		parser_piece(&e);
		ai_position_groupes(&e);
		ai(&e);
		if (e.loop == 1)
		{
			ai_reponse(e.reponse.x, e.reponse.y);
			if (e.yolo == 1)
				e.loop = 0;
			i++;
		}
		else
			ai_reponse(0, 0);
		preparation_env(&e);
	}
	ft_bzero(&e, sizeof(t_env));
	return (0);
}

int		distance(t_coord a, t_coord b)
{
	int ret;

	// core_coord(a);
	// core_coord(b);
	ret = ft_sqrt(ft_pow((int)(b.x - a.x), 2) + ft_pow((b.y - a.y), 2));
	return (ret);
}

// int main() {
// 	t_coord a;
// 	t_coord b;
// 	int c;

// 	a.x = 0;
// 	a.y = 0;
// 	b.x = 23;
// 	b.y = 39;
// 	printf("%d", distance(a, b));
// 	return (0);
// }
