/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:27:27 by grass-kw          #+#    #+#             */
/*   Updated: 2016/10/28 02:13:18 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	affiche_position(int i, int j)
{
	ft_putstr_fd("position : ", 2);
	ft_putnbr_fd(i, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(j, 2);
	ft_putchar_fd('\n', 2);
}

void	affiche_piece(char i, char j)
{
	ft_putstr_fd("comparaison piece : ", 2);
	ft_putchar_fd(i, 2);
	ft_putchar_fd(' ', 2);
	ft_putchar_fd(j, 2);
	ft_putchar_fd('\n', 2);
}

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

static int	piece_non_inserable(t_env *e, int x, int y, char **new_map)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	nombre_de_piece_joueur;

	nombre_de_piece_joueur = 0;
	i = x;
	j = y;
	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (1);
	k = 0;
	while (k < e->piece_line)
	{
		l = 0;
		j = y;
		while (l < e->piece_colonne)
		{
			// affiche_piece(new_mp[i][j], e->piece[k][l] == '*');
			if (is_ennemy(new_map[i][j], e) && e->piece[k][l] == '*')
				return (1);
			if (is_player(new_map[i][j], e) && e->piece[k][l] == '*')
				nombre_de_piece_joueur++;
			l++;
			j++;
		}
		i++;
		k++;
	}
	if (nombre_de_piece_joueur != 1)
		return (1);
	return (0);
}

static char	**insertion_de_piece(t_env *e, int x, int y, char **new_map)
{
	int i;
	int	j;
	int	k;
	int	l;

	i = x;
	j = y;
	k = 0;
	while (k < e->piece_line)
	{
		l = 0;
		j = y;
		while (l < e->piece_colonne)
		{
			if (e->piece[k][l] == '*')
				new_map[i][j] = e->player;
			l++;
			j++;
		}
		i++;
		k++;
	}
	// ft_put_array_fd(new_map, 2);
	return (new_map);
}


static char	**tentative_insertion_de_piece(t_env *e, int x, int y, char **new_map)
{
	// affiche_position(x, y);
	if (piece_non_inserable(e, x, y, new_map) == 1)
		return (NULL);
	return (insertion_de_piece(e, x, y, new_map));
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
			if (tentative_insertion_de_piece(e, i, j, new_map) != NULL)
			{
				// ft_putendl_fd("insertion piece possible", 2);
				ft_free_tab(new_map);
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
	ft_putnbr_fd(e->choice_y, 1);
	ft_putendl_fd("", 1);
}

static void	thinking_strategy(t_env *e)
{
	find_all_possibility(e);
}

static void	preparation_du_prochain_tour(t_env *e)
{
	char *line;

	line = NULL;
	e->piece_line = 0;
	e->piece_colonne = 0;
	if (e->piece != NULL)
	{
		ft_free_tab(e->piece);
		e->piece = NULL;
	}
	e->choice_x = 0;
	e->choice_y = 0;
}

void 	message(char *s)
{
	ft_putendl_fd(s, 2);
}
int			main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	player_number(&e);
	e.game_continue = 1;
	while (e.game_continue)
	{
		map(&e);
		piece(&e);
		thinking_strategy(&e);
		final_decision(&e);
		preparation_du_prochain_tour(&e);
	}
	clear_env(&e);
	return (0);
}
