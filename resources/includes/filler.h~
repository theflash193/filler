/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:52:43 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/30 16:01:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h>

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
}				t_env;

enum			e_pieces
{
	JOUEUR1 = 'o',
	JwOUEUR1_A = 'O',
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
** reponse
*/
void			ai_reponse(int i, int j);

#endif
