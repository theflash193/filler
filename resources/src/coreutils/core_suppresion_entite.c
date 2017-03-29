/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_suppresion_entite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:23:51 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/29 19:28:39 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	core_suppresion_entite(t_entite *entite)
{
	ft_free_tab(entite->entite);
	ft_bzero(entite, sizeof(t_entite));
}
