/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/29 21:08:15 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	affiche(char *s)
{
	ft_putendl("2 2");
	ft_putendl_fd(s, 2);	
}

static void get_line(void)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	affiche(line);
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
	ft_putnbr_fd(e->player, 2);
	ft_strclean(line);
}

// static void map(t_env *e)
// {
// }

int main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	player_number(&e);
	return (0);
}
