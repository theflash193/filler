/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/11/09 17:13:16 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h>

# define PLAYER_1_PIECE 'O'
# define PLAYER_1_LAST_MOVE 'o'
# define PLAYER_2_PIECE 'X'
# define PLAYER_2_LAST_MOVE 'x'
# define EMPTY '.'
# define NEW_PIECE '*'
# define IS_PLAYER1(x) (x == 'o' || x == 'O')
# define IS_PLAYER2(x) (x == 'x' || x == 'X')

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_env
{
	int			nb_player;
	char		**map;
	int			line;
	int			colonne;
	char		**piece;
	int			piece_line;
	int			piece_colonne;
	int			choice_x;
	int			choice_y;
	char		ennemy;
	char		player;
	char		player_lm;
	int			game_continue;
	int			p1_point_debut_tour;
	int			p1_point_apres_placement;
	int			score_p1;
	int			score_p2;
	t_list		*liste_possibilite;
}				t_env;

typedef struct	s_map
{
	char		**map;
	int			x;
	int			y;
	int			points_player;
	int			points_ennemy;
	int			line;
	int			colonne;
	int			point_apres_placement;
	int			score_potentiel;
}				t_map;

void	clear_env(t_env *e);
void	ft_put_array_fd(char **tab, int fd);

void	player_number(t_env *e);
void	map_dimension(t_env *e);
void	map(t_env *e);
void	piece_dimension(t_env *e);
void	piece(t_env *e);
void	delete_map(void *content, size_t content_size);

void	thinking_strategy(t_env *e);
void	final_decision(t_env *e);
void	preparation_du_prochain_tour(t_env *e);
void	points_player1(t_list *elem);
void	points_player2(t_list *elem);
int 	calcul_player_points(t_map *choix, int player);
int 	calcul_player_points2(t_env *e, int player);

void	affiche_piece(char i, char j);
void	affiche_position(int i, int j);
void	print_possibilite(t_list *elem);
int		is_ennemy(char c, t_env *e);
int		is_player(char c, t_env *e);
char	**array_cpy(char **src);

#endif
