/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_position_groupe_ennemie.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 18:38:07 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/30 18:59:59 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    ai_position_groupe_ennemie(t_env *e)
{
    t_coord piece_ennemie;
    t_coord piece_joueur;

    piece_joueur = piece_joueur_plus_haute(e->plateau, e);
    piece_joueur = piece_ennemie_plus_haute(e->plateau, e);
    // core_message("position joueur :");
    // core_coord(piece_joueur);
    // core_message("position ennemie :");
    // core_coord(piece_ennemie);
}