/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_iteration_ligne.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:58:06 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/30 14:03:55 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parser_passer_ligne_suivant(void)
{
	char		*ligne;

	ligne = parser_iteration_ligne();
	ft_strclean(ligne);
}

char	*parser_iteration_ligne(void)
{
	char	*ligne;

	get_next_line(0, &ligne);
	return (ligne);
}
