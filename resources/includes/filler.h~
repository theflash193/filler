/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/12/01 11:58:55 by ozdek            ###   ########.fr       */
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
	t_list		*liste_possibilite;
}				t_env;

typedef struct	s_map
{
	char		**map;
	char		**influence_p1;
	char		**influence_p2;
	int			x;
	int			y;
	int			points_player;
	int			points_ennemy;
	int			points_influence_p1;
	int			points_influence_p2;
	int			line;
	int			colonne;
  int				player;
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
void	test(t_map *choix);
void	test_p1(t_map *choix);
void	test_p2(t_map *choix);

void	influence(t_list *elem);
int		calcul_influence(char **map, int player);
void	marquage_influence(t_map *choix, int player);
void	influence_horizontal(t_map *choix, t_coord coord, int player);
void	influence_vertical(t_map *choix, t_coord coord, int player);

void	lst_buble_sort(t_list *lst, int (*cmp)());
int		sort_best_move_p1(t_map *a, t_map *b);
int		sort_best_move_p2(t_map *a, t_map *b);
void 	message(char *s);
#endif
