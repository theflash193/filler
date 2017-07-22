/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/22 14:43:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord	piece_plus_bas(t_entite plateau, char c)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (PLATEAU[i][j] == c && ret.x < i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

t_coord	piece_plus_gauche(t_entite plateau, char c)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (PLATEAU[i][j] == c && ret.y > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

t_coord	piece_plus_droite(t_entite plateau, char c)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = 0;
	ret.y = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (PLATEAU[i][j] == c && ret.y < i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

t_coord	piece_plus_haute(t_entite plateau, char c)
{
	int		i;
	int		j;
	t_coord ret;

	i = 0;
	ret.x = plateau.x;
	ret.y = plateau.y;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (PLATEAU[i][j] == c && ret.x > i)
			{
				ret.x = i;
				ret.y = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int blocage_bas(t_entite plateau)
{
	int		i;
	int		j;
	int		score;
	t_coord bas;
	t_coord droite;

	score = 0;
	ft_bzero(&bas, sizeof(bas));
	ft_bzero(&droite, sizeof(droite));
	i = 0;
	bas = piece_plus_bas(plateau, 'o');
	droite = piece_plus_droite(plateau, 'o');
	if (bas.x == plateau.x)
		score = +1000;
	else
	{
		score = bas.x;
		score += droite.y;
	}
	// ft_putstr_fd("Le score du plateau est de ", 2);
	// core_int(score);
	// ft_putchar_fd('\n', 2);
	// core_entite(plateau);
	return (score);
}

// void iter_bas(t_list *elem)
// {
// 	blocage_bas(*(t_entite *)elem->content);
// }

t_list 	*iter_bas(t_list *elem)
{
	t_list	*lst;
	t_entite entite;

	lst = NULL;
	entite = *(t_entite *)elem->content;
	entite.score = blocage_bas(*(t_entite *)elem->content);
	lst = ft_lstnew(&entite, sizeof(t_entite));
	return (lst);
}

static void	delete_entite(void *content, size_t size)
{
	t_entite *a;

	a = (t_entite *)content;
	// core_entite(*a);
	ft_bzero(a, sizeof(t_entite *));
	ft_free_tab(a->entite);
	free(content);
	// content_size = 0;
}

void	ai(t_env *e)
{
	t_list	*score;

	e->liste_coup = ai_recuperation_liste_coups(e);
	score = ft_lstmap(e->liste_coup, iter_bas);
	ft_lstdel(&(e->liste_coup), delete_entite);
	// ft_lstiter(e->liste_coup, core_coup);
	// e->loop = 0;
}

// void	ai(t_env *e)
// {
// 	t_list	*liste_coup;

// 	liste_coup = recuperation_liste_coups(e);
// 	if (liste_coup != NULL)
// 	{
// 		ft_lstiter(liste_coup, core_coup);
// 	}
// 	else
// 		e->loop = 0;
// }
