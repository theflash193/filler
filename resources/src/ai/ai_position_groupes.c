/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_position_groupes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 19:05:21 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/30 19:41:50 by grass-kw         ###   ########.fr       */
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
    if (piece_joueur )
    // core_message("position joueur :");
    // core_coord(piece_joueur);
    // core_message("position ennemie :");
    // core_coord(piece_ennemie);
    e->tour = 1;
}