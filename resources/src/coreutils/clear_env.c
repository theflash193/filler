/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 06:00:02 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/18 07:00:03 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_selection(void *content, size_t content_size)
{
	t_select	*data;

	data = (t_select *)content;
	free(data->content);
	free(content);
	content_size = 0;
}

void	clear_env(t_env *e)
{
	if (e->liste_selection != NULL)
		clst_del(&(e->liste_selection), delete_selection);
}
