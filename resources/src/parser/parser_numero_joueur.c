/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_numero_joueur.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:47:26 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/10 13:31:59 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parser_numero_joueur(t_env *e)
{
	char	*ligne;

	while (42)
	{
		ligne = parser_iteration_ligne();
		if (ft_strstr(ligne, "p1") != NULL &&
			ft_strstr(ligne, "grass-kw.filler") != NULL)
		{
			e->numero_joueur = 1;
			ft_strclean(ligne);
			break ;
		}
		if (ft_strstr(ligne, "p2") != NULL &&
			ft_strstr(ligne, "grass-kw.filler") != NULL)
		{
			e->numero_joueur = 2;
			ft_strclean(ligne);
			break ;
		}
		ft_strclean(ligne);
	}
}
