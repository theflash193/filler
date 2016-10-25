/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:57:10 by ozdek             #+#    #+#             */
/*   Updated: 2016/10/25 17:32:06 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	final_decision(t_env *e)
{

}

void 	play(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			if (try_place_piece(e, i, j))
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

int	try_place_piece(t_env *e, int x, int y)
{

}
