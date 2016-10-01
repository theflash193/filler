/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/01 12:23:35 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h>

// typedef enum	e_player1
// {
// 	p1
// }


// typedef enum	e_player2
// {

// }

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
	int			player;
	char		**map;
	int			line;
	int			colonne;
	char		**piece;
	int			piece_line;
	int			piece_colonne;
	int			choice_x;
	int			choice_y;
}				t_env;

void	clear_env(t_env *e);
void	ft_put_array_fd(char **tab, int fd);

void	player_number(t_env *e);
void	map_dimension(t_env *e);
void	map(t_env *e);
void	piece_dimension(t_env *e);
void	piece(t_env *e);
#endif
