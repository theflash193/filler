/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:20:21 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/22 15:16:51 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*padding_left(size_t lenght_max, char *s, int justify)
{
	char	*res;
	size_t	start;
	int		lenght;

	lenght = ft_strlen(s);
	start = lenght_max - lenght;
	res = ft_strnew(lenght_max);
	ft_memset(res, justify, lenght_max);
	ft_memcpy(res + start, s, lenght);
	return (res);
}
