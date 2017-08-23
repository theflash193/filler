/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:21:16 by grass-kw          #+#    #+#             */
/*   Updated: 2017/08/23 17:21:33 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double	ft_sqrt(double nb)
{
	double calc;
	double diff;

	if (nb == 0.0 || nb == 1.0)
		return (nb);
	calc = nb;
	diff = 0.0;
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}

int		ft_pow(int nb, int pow)
{
	int ret;

	ret = nb;
	if (pow < 0)
		return (0);
	else if (pow == 0)
		return (1);
	while (pow-- > 1)
		ret *= nb;
	return (ret);
}