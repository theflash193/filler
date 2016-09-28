/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 06:22:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 06:59:53 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_data(t_clst *alst)
{
	t_select *data;

	data = (t_select *)alst->content;
	printf("=>content[%s], current[%d]\n", data->content, data->current);
}

void	print_select(t_env *e)
{
	clst_iter(e->liste_selection, print_data);
}
