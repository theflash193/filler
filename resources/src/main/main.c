/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/30 18:42:09 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void clear_env(t_env *e)
{
	if (e->map != NULL)
		ft_free_tab(e->map);
	if (e->piece != NULL)
		ft_free_tab(e->piece);
	ft_bzero(e, sizeof(t_env));
}

static void	ft_put_array_fd(char **tab, int fd)
{
	int	i;

	i = 0;
	ft_putendl_fd("array(", fd);
	while (tab[i])
	{
		ft_putstr_fd("\t", fd);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd(" => ", fd);
		ft_putendl_fd(tab[i], fd);
		i++;
	}
	ft_putendl_fd("    )", fd);
}

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

static void piece_dimension(t_env *e)
{
	char	*line;
	char	**tab;

	line = NULL;
	get_next_line(0, &line);
	tab = ft_strsplit(line, ' ');
	e->piece_line = atoi(tab[1]);
	e->piece_colonne = atoi(tab[2]);
	ft_strclean(line);
	ft_free_tab(tab);
}

static void piece(t_env *e)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	piece_dimension(e);
	e->piece = (char **)malloc(sizeof(char *) * e->piece_line + 1);
	while (i < e->piece_line)
	{
		get_next_line(0, &line);
		e->piece[i++] = ft_strdup(line);
		ft_strclean(line);
	}
	e->piece[i] = 0;
	ft_put_array_fd(e->piece, 2);
}

int main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	player_number(&e);
	map(&e);
	piece(&e);
	clear_env(&e);
	return (0);
}
