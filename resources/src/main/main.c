/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/05 17:29:08 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_ennemy(char c, t_env *e)
{
	if (e->nb_player == 1)
		return (c == PLAYER_2_PIECE || c == PLAYER_2_LAST_MOVE);
	return (c == PLAYER_1_PIECE || c == PLAYER_1_LAST_MOVE);
}

int		is_player(char c, t_env *e)
{
	if (e->nb_player == 1)
		return (c == PLAYER_1_PIECE || c == PLAYER_1_LAST_MOVE);
	return (c == PLAYER_2_PIECE || c == PLAYER_2_LAST_MOVE);
}

static char	**try_place_piece(t_env *e, int x, int y, char **new_map)
{
	int i;
	int	j;
	int	form_replace_piece;
	int	k;
	int	l;

	k = 0;
	form_replace_piece = 0;
	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (NULL);
	i = x;
	while (i < e->piece_line)
	{
		j = y;
		k = l;
		while (j < e->piece_colonne)
		{
			if (is_ennemy(new_map[x][y], e) && e->piece[k][y] == NEW_PIECE)
				return (NULL);
			if (form_replace_piece == 1 && (is_player(new_map[x][y], e) && e->piece[k][j] == NEW_PIECE))
				return (NULL);
			if (form_replace_piece == 0 && is_player(new_map[x][y], e))
				form_replace_piece = 1;
			if (new_map[x][y] == EMPTY && e->piece[k][l] == NEW_PIECE)
				new_map[x][y] = ft_toupper(e->player_lm);
			j++;
			l++;
		}
		i++;
		k++;
	}
	return (new_map);
}

static char	**array_cpy(char **src)
{
	char	**new_array;
	char	len;
	int		i;

	len = ft_array_len(src);
	new_array = (char **)malloc(sizeof(char *) * len + 1);
	i = 0;
	while (src[i])
	{
		new_array[i] = ft_strdup(src[i]);
		i++;
	}
	new_array[i] = 0;
	return (new_array);
}

static void find_all_possibility(t_env *e)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			new_map = array_cpy(e->map);
			ft_put_array_fd(new_map, 2);
			if (try_place_piece(e, i, j, e->map) != NULL)
			{
				e->choice_x = i;
				e->choice_y = j;
				return ;
			}
			ft_free_tab(new_map);
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
