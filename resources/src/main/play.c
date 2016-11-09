/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:57:10 by ozdek             #+#    #+#             */
/*   Updated: 2016/11/09 17:32:26 by ozdek            ###   ########.fr       */
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
	return (new_map);
}


static char	**tentative_insertion_de_piece(t_env *e, int x, int y)
{
	if (piece_non_inserable(e, x, y, e->map) == 1)
		return (NULL);
	return (insertion_de_piece(e, x, y));
}

void test(t_map *choix) {
	ft_put_array_fd(choix->map, 2);
	ft_putstr_fd("points_player1: ", 2);
	ft_putnbr_fd(calcul_player_points(choix, 1), 2);
	ft_putstr_fd(" points_player2: ", 2);
	ft_putnbr_fd(calcul_player_points(choix, 2), 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("p1 potentiel: ", 2);
	ft_putnbr_fd(choix->score_potentiel, 2);
	ft_putendl_fd("", 2);
}

static void find_all_possibility(t_env *e)
{
	int		i;
	int		j;
	t_map	*choix;
	char	**tentative;

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
				int point_apres_placement;

				point_apres_placement = calcul_player_points(choix, e->nb_player);
				choix->score_potentiel = point_apres_placement - e->p1_point_debut_tour;
				test(choix);
				ft_lst_push_back(&(e->liste_possibilite), ft_lstnew(choix, sizeof(choix)));
				e->choice_x = i;
				e->choice_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	e->choice_x = 0;
	e->choice_y = 0;
	e->game_continue = 0;
}

void	final_decision(t_env *e)
{
	ft_putnbr_fd(e->choice_x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(e->choice_y, 1);
	ft_putendl_fd("", 1);
}

void	selectionne_la_meilleur_possibilite(t_env *e)
{
	// ft_lstiter(e->liste_possibilite, print_possibilite);
}

void	preparation_du_prochain_tour(t_env *e)
{
	char *line;

	line = NULL;
	e->piece_line = 0;
	e->piece_colonne = 0;
	if (e->game_continue == 0)
		ft_putnbr_fd(e->score_p1, 2);
	if (e->piece != NULL)
	{
		ft_free_tab(e->piece);
		e->piece = NULL;
	}
	if (e->liste_possibilite != 0)
	{
		ft_lstdel(&(e->liste_possibilite), delete_map);
		e->liste_possibilite = NULL;
	}
	e->choice_x = 0;
	e->choice_y = 0;
	e->p1_point_debut_tour = 0;
	e->p1_point_apres_placement = 0;
}

void	thinking_strategy(t_env *e)
{
	ft_putendl_fd("nouveau tour", 2);
	find_all_possibility(e);
	selectionne_la_meilleur_possibilite(e);
}
