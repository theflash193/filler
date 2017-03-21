/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:55 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/21 18:04:46 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	map_dimension(t_env *e)
{
	char	*line;
	char	**tab;

	line = NULL;
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	e->line = atoi(tab[1]);
	e->colonne = atoi(tab[2]);
	ft_strclean(line);
	ft_free_tab(tab);
}

void	map(t_env *e)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	map_dimension(e);
	e->map = (char **)malloc(sizeof(char *) * e->line + 1);
	get_next_line(0, &line);
	ft_strclean(line);
	while (i < e->line)
	{
		get_next_line(0, &line);
		e->map[i++] = ft_strdup(line + 4);
		ft_strclean(line);
	}
	e->map[i] = 0;
}
