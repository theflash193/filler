/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:57:10 by ozdek             #+#    #+#             */
/*   Updated: 2016/12/01 22:00:53 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_list *stockage_nouvelle_piece(t_map *choix)
{
	t_list	*ret;
	int	i;
	int	j;
	t_coord	*pieces;

	i = 0;
	ret = NULL;
	while (i < choix->line)
	{
		j = 0;
		while (j < choix->colonne)
		{
			if (choix->player == 1 && choix->map[i][j] == 'o')
			{
				pieces = (t_coord *)malloc(sizeof(t_coord));
				pieces->x = i;
				pieces->y = j;
				ft_lst_push_back(&(ret), ft_lstnew(pieces, sizeof(t_coord)));
			}
			if (choix->player == 2 && choix->map[i][j] == 'x')
			{
				pieces = (t_coord *)malloc(sizeof(t_coord));
				pieces->x = i;
				pieces->y = j;
				ft_lst_push_back(&(ret), ft_lstnew(pieces, sizeof(t_coord)));
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int 	calcul_player_points2(t_env *e, int player)
{
	int	i;
	int	j;
	int	points;

	points = 0;
	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			if (IS_PLAYER1(e->map[i][j]) && player == 1)
				points++;
			if (IS_PLAYER2(e->map[i][j]) && player == 2)
				points++;
			j++;
		}
		i++;
	}
	return (points);
}

int 	calcul_player_points(t_map *choix, int player)
{
	int i;
	int	j;
	int points;

	points = 0;
	i = 0;
	while (i < choix->line)
	{
		j = 0;
		while (j < choix->colonne)
		{
			if (IS_PLAYER1(choix->map[i][j]) && player == 1)
				points++;
			if (IS_PLAYER2(choix->map[i][j]) && player == 2)
				points++;
			j++;
		}
		i++;
	}
	// exit(0);
	return (points);
}

void	final_decision(t_env *e)
{
	ft_putnbr_fd(e->choice_x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(e->choice_y, 1);
	ft_putendl_fd("", 1);
}

t_coord	find_piece_droite(t_env *e)
{
  	int	i;
	int	j;
	t_coord	piece_droite;

	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			if (e->map[i][j] == 'O' && e->nb_player == 1)
			{
				piece_droite.x = i;
				piece_droite.y = j;
			}
			if (e->map[i][j] == 'X' && e->nb_player != 1)
			{
				piece_droite.x = i;
				piece_droite.y = j;				
			}
			j++;
		}
	}
	return (piece_droite);
}

int	placement_piece_droite(t_env *e)
{
	t_coord	piece_plus_droite;
	t_coord	*nouvelle_piece_droite;

	piece_plus_droite = find_piece_droite(e);
	return (0);
}

void	thinking_strategy(t_env *e)
{
	t_map	*choix;

	e->liste_possibilite = find_all_possibility(e);
	if (e->liste_possibilite == NULL)
	{
		e->choice_x = 0;
		e->choice_y = 0;
		e->game_continue = 0;
	}
	else
	{
	  	print_possibilite(e->liste_possibilite);
	       	placement_piece_droite(e);
		ft_lstiter(e->liste_possibilite, influence);
		if (e->nb_player == 1)
			lst_buble_sort(&(e->liste_possibilite), sort_best_move_p1);
		else
			lst_buble_sort(&(e->liste_possibilite), sort_best_move_p2);
		choix = (t_map *)e->liste_possibilite->content;
		e->choice_x = choix->x;
		e->choice_y = choix->y;
	}
}
