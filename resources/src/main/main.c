/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/28 22:32:31 by ozdek            ###   ########.fr       */
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
int main(int ac, char **av)
{
	for (int i = 0; i < 2;i++)
	{
		get_line();
	}
	return (0);
}
