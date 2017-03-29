/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:55:38 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/29 19:14:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	core_put_array(char **tab)
{
	int	i;

	i = 0;
	ft_putendl_fd("array(", 2);
	while (tab[i])
	{
		ft_putstr_fd("\t", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(" => ", 2);
		ft_putendl_fd(tab[i], 2);
		i++;
	}
	ft_putendl_fd("    )", 2);
}
