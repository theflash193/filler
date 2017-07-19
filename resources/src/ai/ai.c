/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 19:16:45 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/19 19:08:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int placement_possible(int x, int y, t_env *e)
{
	t_coord		p;
	t_coord		i;
	int			recouvre_forme;

	recouvre_forme = 0;
	p.x = x;
	p.y = y;
	if ((p.x + e->piece.x > e->plateau.x) || (p.y + e->piece.y > e->plateau.y)) // je verifie que mon plateau entre dans cette position
		return (0);
	i.x = 0;
	while (i.x < e->piece.x)
	{
		i.y = 0;
		p.y = y;
		while (i.y < e->piece.y)
		{
			if (e->piece.entite[i.x][i.y] == '*' && IS_PLAYER2(e->plateau.entite[p.x][p.y]))
				return (0);
			if (e->piece.entite[i.x][i.y] == '*' && IS_PLAYER1(e->plateau.entite[p.x][p.y]))
				recouvre_forme++;
			i.y++;
			p.y++;
		}
		i.x++;
		p.x++;
	}
	if (recouvre_forme != 1)
		return (0);
	return (1);
}

t_entite	impression_piece(t_env *e, int i, int j, t_entite a)
{
	t_coord piece;
	t_coord	plateau;

	piece.x = 0;
	plateau.x = i;
	while (piece.x < e->piece.x)
	{
		piece.y = 0;
		plateau.y = j;
		while (piece.y < e->piece.y)
		{
			if (e->piece.entite[piece.x][piece.y] == '*' && a.entite[plateau.x][plateau.y] != 'O')
			{
				if (e->numero_joueur == 1)
					a.entite[plateau.x][plateau.y] = 'o';
				else
					a.entite[plateau.x][plateau.y] = 'x';
			}
			piece.y++;
			plateau.y++;
		}
		plateau.x++;
		piece.x++;
	}
	return (a);
}

t_entite	sauvegarde_plateau(t_env *e, int i, int j)
{
	char	**plateau;
	int		count;
	t_entite a;
	
	count = 0;
	plateau = (char **)malloc(sizeof(char *) * e->plateau.x + 1);
	while (count < e->plateau.x)
	{
		plateau[count] = ft_strdup(e->plateau.entite[count]);
		count++;
	}
	plateau[count] = 0;
	a.entite = plateau;
	a.x = e->plateau.x;
	a.y = e->plateau.y;
	impression_piece(e, i, j, a);
	return (a);
}

void	core_coup(t_list *elem)
{
	t_entite	*coup;

	coup = (t_entite *)elem->content;
	core_entite(*coup);
}

t_list	*recuperation_liste_coups(t_env *e)
{
	t_list		*liste_coup;
	t_entite	coup;
	int			i;
	int			j;

	i = 0;
	liste_coup = NULL;
	while (i < e->plateau.x)
	{
		j = 0;
		while (j < e->plateau.y)
		{
			if (placement_possible(i, j, e) == 1)
			{
				coup = sauvegarde_plateau(e, i, j);
				ft_lst_push_back(&liste_coup, ft_lstnew(&coup, sizeof(t_entite)));
				e->reponse.x = i;
				e->reponse.y = j;
			}
			j++;
		}
		i++;
	}
	return (liste_coup);
}

void	core_int(int i)
{
	ft_putnbr_fd(i, 2);
}

void blocage_bas(t_entite plateau)
{
//	core_entite(plateau);
	int		i;
	int		j;
	int		score;
	t_coord bas;
	t_coord droite;

	ft_bzero(&bas, sizeof(bas));
	ft_bzero(&droite, sizeof(droite));
	i = 0;
	while (i < plateau.x)
	{
		j = 0;
		while (j < plateau.y)
		{
			if (IS_PLAYER1(plateau.entite[i][j]) && bas.x > i)
			{
				core_message("hello world");
				bas.x = i;
				bas.y = j;
			}
			if (IS_PLAYER1(plateau.entite[i][j]) && droite.y > j)
			{
				core_message("gordon");
				droite.x = i;
				droite.y = j;
			}
			j++;
		}
		i++;
	}
	if (bas.x == plateau.x)
		score = +1000;
	else
	{
		score = bas.x;
		score += droite.y;
	}
	ft_putstr_fd("Le score du plateau est de ", 2);
	core_int(score);
	ft_putchar_fd('\n', 2);
	core_entite(plateau);

}

void iter_bas(t_list *elem)
{
	blocage_bas(*(t_entite *)elem->content);
}

void	ai(t_env *e)
{
	t_list	*liste_coup;

	//core_entite(e->plateau);
	liste_coup = recuperation_liste_coups(e);
	ft_lstiter(liste_coup, core_coup);
	//ft_lstiter(liste_coup, iter_bas);
	e->loop = 0;
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
