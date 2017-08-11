/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_position_groupes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 19:05:21 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/11 07:45:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    ai_position_groupes(t_env *e)
{
    t_coord piece_ennemie;
    t_coord piece_joueur;
    t_direction joueur;
    t_direction ennemie;

    if (e->tour != 0)
        return ;
    piece_joueur = piece_joueur_plus_haute(e->plateau, e);
    piece_ennemie = piece_ennemie_plus_haute(e->plateau, e);
    if (HAUT_GAUCHE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        joueur = HAUT_GAUCHE;
    if (HAUT_DROITE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        joueur = HAUT_DROITE;
    if (BAS_GAUCHE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        joueur = BAS_GAUCHE;
    if (BAS_DROITE(piece_joueur.x, piece_joueur.y, e->plateau.x, e->plateau.y))
        joueur = BAS_DROITE;
        
    if (HAUT_GAUCHE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        ennemie = HAUT_GAUCHE;
    if (HAUT_DROITE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        ennemie = HAUT_DROITE;
    if (BAS_GAUCHE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
        ennemie = BAS_GAUCHE;
    if (BAS_DROITE(piece_ennemie.x, piece_ennemie.y, e->plateau.x, e->plateau.y))
         ennemie = BAS_DROITE;
    // exit(0);
    // else
    //     e->etat_machine = B_HAUT_DROIT;
    if (joueur == BAS_GAUCHE && ennemie == BAS_DROITE)
    {
        core_message("jonathan");
        e->etat2 = B_HAUT_DROIT;
        e->etat_machine = B_BAS_DROIT;
        e->cote_ennemie = DROITE;
    }
    if (joueur == HAUT_GAUCHE && ennemie == BAS_DROITE)
    {
        core_message("joseph");
        // exit(0);
        e->etat2 = B_HAUT_GAUCHE;
        e->etat_machine = B_BAS_DROIT;
        e->cote_ennemie = DROITE;
    }
    if (joueur == BAS_DROITE && ennemie == HAUT_GAUCHE)
    {
        core_message("ilala");
        e->etat1 =  B_BAS_DROIT;
        e->etat2 = B_HAUT_DROIT;
        e->etat_machine = B_HAUT_GAUCHE;
    }
    if (joueur == BAS_DROITE && ennemie == BAS_GAUCHE)
    {
        core_message("mirion");
        e->etat1 =  B_BAS_DROIT;
        e->etat2 = B_HAUT_DROIT;
        e->etat_machine = B_BAS_DROIT;
    }
    e->tour = 1;
}


//  x 4
//  y 4

//  haut gauche = ((x >= 0 && x <= lenght.x) && (y >= 0 && y <= lenght.y / 2));
//  haut droit = ((x >= 0 && x <= lenght.x) && (y >= lenght.y / 2 && y < lenght.y));
//  bas gauche = ((x >= lenght.x / 2 && x <= lenght.x) && (y >= 0 && y <= lenght.y / 2));
//  bas droite = ((x >= lenght.x / 2 && x <= lenght.x) && (x >= lenght.x / 2 && x <= lenght.x));