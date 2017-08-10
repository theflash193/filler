/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_position_groupes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 19:05:21 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/10 11:44:44 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    ai_position_groupes(t_env *e)
{
    t_coord piece_ennemie;
    t_coord piece_joueur;

    if (e->tour != 0)
        return ;
    piece_joueur = piece_joueur_plus_haute(e->plateau, e);
    piece_ennemie = piece_ennemie_plus_haute(e->plateau, e);
    if (HAUT_GAUCHE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        core_message("joueur haut gauche !");
    if (HAUT_DROITE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        core_message("joueur haut DROITE !");
    if (BAS_GAUCHE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        core_message("joueur BAS gauche !");
    if (BAS_DROITE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        core_message("joueur BAS DROITE !");
    if (HAUT_GAUCHE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        core_message("ennemie haut gauche !");
    if (HAUT_DROITE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        core_message("ennemie haut DROITE !");
    if (BAS_GAUCHE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        core_message("ennemie BAS gauche !");
    if (BAS_DROITE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        core_message("ennemie BAS DROITE !");
    // exit(0);
    // else
    //     e->etat_machine = B_HAUT_DROIT;
    e->tour = 1;
}


//  x 4
//  y 4

//  haut gauche = ((x >= 0 && x <= lenght.x) && (y >= 0 && y <= lenght.y / 2));
//  haut droit = ((x >= 0 && x <= lenght.x) && (y >= lenght.y / 2 && y < lenght.y));
//  bas gauche = ((x >= lenght.x / 2 && x <= lenght.x) && (y >= 0 && y <= lenght.y / 2));
//  bas droite = ((x >= lenght.x / 2 && x <= lenght.x) && (x >= lenght.x / 2 && x <= lenght.x));