/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/01 12:27:21 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**try_place_piece(t_env *e, int x, int y, char **new_map)
{
	int i;
	int	j;
	int	nbr_piece;

	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (0);

}

static void find_all_possibility(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			if (try_place_piece(e, i, j, e->map))
			{
				e->choice_x = i;
				e->choice_y = j;
				return ;
			}
		}
	}
	e->choice_x = 0;
	e->choice_y = 0;
}

static void	final_decision(t_env *e)
{
	ft_putnbr(e->choice_x);
	ft_putchar(' ');
	ft_putnbr(e->choice_x);
	ft_putendl("");
}

static void	thinking_strategy(t_env *e)
{
	find_all_possibility(e);	
}

int main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	player_number(&e);
	while (42)
	{
		map(&e);
		piece(&e);
		thinking_strategy(&e);
		final_decision(&e);
	}
	clear_env(&e);
	return (0);
}
