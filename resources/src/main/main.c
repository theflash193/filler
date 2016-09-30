/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/30 16:31:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void player_number(t_env *e)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strnequ(line, "$$$ exec p1", 11))
		e->player = 1;
	else if (ft_strnequ(line, "$$$ exec p2", 11))
		e->player = 2;
	ft_strclean(line);
}

static void	map_dimension(t_env *e)
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

static void map(t_env *e)
{
	char	*line;
	int		i;

	line = NULL;
	map_dimension(e);
	// e->map[i] = (char **)malloc(sizeof(char) * e->line + 1);
	// get_next_line(0, &line);
}

int main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	player_number(&e);
	map_dimension(&e);
	return (0);
}
