/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:52:43 by grass-kw          #+#    #+#             */
/*   Updated: 2017/06/03 19:59:32 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h>
# define IS_PLAYER1(x) (x == 'o' || x == 'O')
# define IS_PLAYER2(x) (x == 'x' || x == 'X')

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_piece
{
	char		**piece;
	int			x;
	int			y;
}				t_piece;

typedef struct	s_entite
{
	char		**entite;
	int			x;
	int			y;
}				t_entite;

typedef struct	s_env
{
	int			numero_joueur;
	t_entite	plateau;
	t_entite	piece;
	t_coord		reponse;
	int			loop;
}				t_env;

enum			e_pieces
{
	JOUEUR1 = 'o',
	JOUEUR1_A = 'O',
	JOUEUR2 = 'x',
	JOUEUR2_A = 'X',
	VIDE = ' '
};

/*
**	parser
*/

void			parser_numero_joueur(t_env *e);
char			*parser_iteration_ligne(void);
void			parser_plateau(t_env *e);
void			parser_passer_ligne_suivant(void);
void			parser_piece(t_env *e);
/*
**	coreutils
*/
void			core_message(char *s);
void			core_put_array(char **tab);
void			core_suppresion_entite(t_entite *entite);
void			core_entite(t_entite entite);

/*
** ai
*/
void			ai_reponse(int i, int j);
void			ai(t_env *e);
#endif
