/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/05 17:40:03 by grass-kw         ###   ########.fr       */
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

typedef enum	e_map
{
	p1 = 'O',
	p1_recent = 'o',
	p2 = 'x',
	p2_recent = 'X',
	empty = '.',
	new_piece = '*'
}				t_map;

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
	int			game_over;
}				t_env;

void	clear_env(t_env *e);
void	ft_put_array_fd(char **tab, int fd);

void	player_number(t_env *e);
void	map_dimension(t_env *e);
void	map(t_env *e);
void	piece_dimension(t_env *e);
void	piece(t_env *e);
#endif
