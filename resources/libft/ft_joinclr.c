/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 23:47:14 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/22 15:16:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinclr(char *s1, char *s2, int mode)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (mode == 1)
		ft_strclean2(&s1);
	if (mode == 2)
	{
		ft_strclean2(&s1);
		ft_strclean2(&s2);
	}
	return (s);
}
