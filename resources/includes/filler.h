/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:53:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/09/30 18:28:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h>

typedef enum	e_booleen
{
	 p1 = 'o',
	 p2 = 'x'
}				t_boolen;

typedef struct	s_env
{
	int			player;
	char		**map;
	int			line;
	int			colonne;
	char		**piece;
	int			piece_line;
	int			piece_colonne;
}				t_env;

#endif
