/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:52:43 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/30 19:38:55 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h>
# define IS_PLAYER1(x) (x == 'o' || x == 'O')
# define IS_PLAYER2(x) (x == 'x' || x == 'X')
# define PLATEAU plateau.entite

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
	int			score;
	t_coord		reponse;
}				t_entite;

typedef enum	e_etat_machine
{
	B_HAUT_DROIT,
	B_BAS_DROIT
}				t_etat_machine;

// typedef enum	e_enum
// {
// 	B_HAUT_DROIT,
// 	B_BAS_DROIT
// }				t_etat_machine;

typedef struct	s_env
{
	int			numero_joueur;
	t_entite	plateau;
	t_entite	piece;
	t_coord		reponse;
	t_list		*liste_coup;
	int			loop;
	int			blocage;
	t_etat_machine		etat_machine;
	int			tour;
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
void			core_coup(t_list *elem);
void			core_entite(t_entite entite);
void			core_int(int i);
void			core_coord(t_coord a);

/*
** ai
*/
void			ai_reponse(int i, int j);
void			ai(t_env *e);
t_list			*ai_recuperation_liste_coups(t_env *e);
t_coord			piece_plus_bas(t_entite plateau, char c);
t_coord			piece_plus_gauche(t_entite plateau, char c);
t_coord			piece_plus_droite(t_entite plateau, char c);
t_coord			piece_plus_haute(t_entite plateau, char c);
void			lst_bubble_sort(t_list **lst, int (*cmp)());
int				sort_best_move_p1(t_entite *a, t_entite *b);
void			lstswap(void **a, void **b);
void			delete_entite(void *content, size_t size);
t_coord			piece_joueur_plus_haute(t_entite plateau, t_env *e);
t_coord			piece_joueur_plus_bas(t_entite plateau, t_env *e);
t_coord			piece_joueur_plus_gauche(t_entite plateau, t_env *e);
t_coord			piece_joueur_plus_droite(t_entite plateau, t_env *e);
int				piece_joueur(char c, t_env *e);
int				piece_ennemie(char c, t_env *e);
t_list 			*iter_bas_gauche(t_list *elem);
int 			blocage_bas_gauche(t_entite plateau);
t_list 			*iter_bas_droite(t_list *elem);
int 			blocage_bas_droite(t_entite plateau);
t_list 			*iter_haut_droit(t_list *elem);
int 			blocage_haut_droit(t_entite plateau);
t_list 			*iter_haut_gauche(t_list *elem);
int				blocage_haut_gauche(t_entite plateau);
void			ai_position_groupes(t_env *e);
t_coord			piece_ennemie_plus_haute(t_entite plateau, t_env *e);
t_coord			piece_ennemie_plus_bas(t_entite plateau, t_env *e);
t_coord			piece_ennemie_plus_gauche(t_entite plateau, t_env *e);
t_coord			piece_ennemie_plus_droite(t_entite plateau, t_env *e);

#endif
