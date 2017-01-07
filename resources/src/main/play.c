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

int 	calcul_player_points2(t_env *e, int player)
{
	int i;
	int	j;
	int points;

	points = 0;
	i = 0;
	// ft_put_array_fd(choix->map, 2);
	// ft_putnbr_fd(choix->line, 2);
	// ft_putnbr_fd(choix->colonne, 2);
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
	// exit(0);
	return (points);
}

int 	calcul_player_points(t_map *choix, int player)
{
	int i;
	int	j;
	int points;

	points = 0;
	i = 0;
	// ft_put_array_fd(choix->map, 2);
	// ft_putnbr_fd(choix->line, 2);
	// ft_putnbr_fd(choix->colonne, 2);
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

static int	piece_non_inserable(t_env *e, int x, int y, char **new_map)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	nombre_de_piece_joueur;

	nombre_de_piece_joueur = 0;
	i = x;
	j = y;
	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (1);
	k = 0;
	while (k < e->piece_line)
	{
		l = 0;
		j = y;
		while (l < e->piece_colonne)
		{
			if (is_ennemy(new_map[i][j], e) && e->piece[k][l] == '*')
				return (1);
			if (is_player(new_map[i][j], e) && e->piece[k][l] == '*')
				nombre_de_piece_joueur++;
			l++;
			j++;
		}
		i++;
		k++;
	}
	if (nombre_de_piece_joueur != 1)
		return (1);
	return (0);
}

static char	**insertion_de_piece(t_env *e, int x, int y)
{
	int i;
	int	j;
	int	k;
	int	l;
	char	**new_map;

	new_map = array_cpy(e->map);
	i = x;
	j = y;
	k = 0;
	while (k < e->piece_line)
	{
		l = 0;
		j = y;
		while (l < e->piece_colonne)
		{
			if (e->piece[k][l] == '*')
				new_map[i][j] = e->player;
			l++;
			j++;
		}
		i++;
		k++;
	}
	//	ft_put_array_fd(new_map, 2);
	// ft_putnbr_fd(choix->line, 2);
	// ft_putnbr_fd(choix->colonne, 2);
	return (new_map);
}


static char	**tentative_insertion_de_piece(t_env *e, int x, int y)
{
	if (piece_non_inserable(e, x, y, e->map) == 1)
		return (NULL);
	return (insertion_de_piece(e, x, y));
}

static t_list *find_all_possibility(t_env *e)
{
	int		i;
	int		j;
	t_map	*choix;
	char	**tentative;
	t_list	*all_possibility;

	all_possibility = NULL;
	choix = NULL;
	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			tentative = tentative_insertion_de_piece(e, i, j);
			if (tentative != 0)
			{
				choix = (t_map *)malloc(sizeof(t_map));
				choix->map = tentative;
				choix->x = i;
				choix->y = j;
				choix->line = e->line;
				choix->colonne = e->colonne;
				choix->player = e->nb_player;
				choix->millieux = e->millieux;
				ft_lst_push_back(&(all_possibility), ft_lstnew(choix, sizeof(t_map)));
			}
			j++;
		}
		i++;
	}
	return (all_possibility);
}

void	final_decision(t_env *e)
{
	ft_putnbr_fd(e->choice_x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(e->choice_y, 1);
	ft_putendl_fd("", 1);
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
	  //		print_possibilite(e->liste_possibilite);
		ft_lstiter(e->liste_possibilite, influence);
		ft_lstiter(e->liste_possibilite, pts_millieux);
		if (e->nb_player == 1)
		  lst_buble_sort(&(e->liste_possibilite), sort_best_move_p1);
		else
		  lst_buble_sort(&(e->liste_possibilite), sort_best_move_p2);
		//		ft_lstiter(e->liste_possibilite, print_possibilite);
		choix = (t_map *)e->liste_possibilite->content;
		e->choice_x = choix->x;
		e->choice_y = choix->y;
	}
}
