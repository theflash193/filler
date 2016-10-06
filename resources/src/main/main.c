/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/06 14:41:59 by grass-kw         ###   ########.fr       */
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

	form_replace_piece = 0;
	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (NULL);
	i = x;
	ft_putendl_fd("1", 2);
	k = 0;
	while (i < e->piece_line)
	{
		j = y;
		l = 0;
		while (j < e->piece_colonne)
		{
			// ft_putendl_fd("2", 2);
			if (is_ennemy(new_map[i][j], e) && e->piece[k][l] == NEW_PIECE)
				return (NULL);
			// ft_putendl_fd("3", 2);
			if (form_replace_piece == 1 && (is_player(new_map[i][j], e) && e->piece[k][l] == NEW_PIECE))
				return (NULL);
			// ft_putendl_fd("4", 2);
			if (form_replace_piece == 0 && is_player(new_map[i][j], e))
				form_replace_piece = 1;
			// ft_putendl_fd("5", 2);
			if (new_map[i][j] == EMPTY && e->piece[k][l] == NEW_PIECE)
				new_map[i][j] = e->player_lm;
			// ft_putendl_fd("6", 2);
			j++;
			l++;
		}
		i++;
		k++;
	}
	if (form_replace_piece != 1)
	{
		ft_putendl_fd("pas d'emplacement", 2);
		return (NULL);
	}
	ft_putendl_fd("7", 2);
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
			if (try_place_piece(e, i, j, e->map) != NULL)
			{
				ft_put_array_fd(new_map, 2);
				e->choice_x = i;
				e->choice_y = j;
				return ;
			}
			ft_free_tab(new_map);
			j++;
		}
		i++;
	}
	e->choice_x = 0;
	e->choice_y = 0;
	e->game_continue = 0;
}

static void	final_decision(t_env *e)
{
	ft_putnbr_fd(e->choice_x, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(e->choice_x, 1);
	ft_putendl_fd("", 1);
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
	while (e.game_continue)
	{
		ft_putendl_fd("nouveau tour", 2);
		ft_putendl_fd("map", 2);
		map(&e);
		ft_putendl_fd("piece", 2);
		piece(&e);
		ft_putendl_fd("thinking_startegy", 2);
		thinking_strategy(&e);
		ft_putendl_fd("final_decision", 2);
		final_decision(&e);
		prepare_next_turn(&e);
	}
	// ft_putendl_fd("3", 2);
	clear_env(&e);
	return (0);
}
