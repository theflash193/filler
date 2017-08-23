/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_position_groupes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 19:05:21 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 10:33:55 by grass-kw         ###   ########.fr       */
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
    if (joueur == BAS_GAUCHE && ennemie == BAS_DROITE)
    {
        e->etat_machine = B_BAS_DROIT;
        e->etat2 = B_HAUT_DROIT;
        e->cote_ennemie = DROITE;
    }
    if (joueur == HAUT_GAUCHE && ennemie == BAS_DROITE)
    {
        e->etat2 = B_HAUT_GAUCHE;
        e->etat_machine = B_BAS_DROIT;
        e->cote_ennemie = DROITE;
    }
    if (joueur == BAS_DROITE && ennemie == HAUT_GAUCHE)
    {
        // exit(0);
        e->etat_machine = B_HAUT_GAUCHE;
        e->etat2 = B_HAUT_DROIT;
        e->cote_ennemie = GAUCHE;
    }
    if (joueur == BAS_DROITE && ennemie == BAS_GAUCHE)
    {
        // exit(0);
        e->etat_machine = B_HAUT_GAUCHE;
        e->etat2 = B_BAS_DROIT;
        e->cote_ennemie = GAUCHE;
    }
    // if (joueur == BAS_DROITE && ennemie == BAS_GAUCHE)
    // {
    //     // exit(0);
    //     e->etat_machine = B_HAUT_GAUCHE;
    //     e->etat2 = B_BAS_GAUCHE;
    //     e->cote_ennemie = GAUCHE;
    // }
    e->tour = 1;
}
