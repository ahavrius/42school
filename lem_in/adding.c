/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:28:11 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/14 19:28:12 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		atoi_correct(const char *str)
{
	long	res;
	int		sign;

	if (!str || !*str || g_error)
		return (g_error = 2);
	sign = 1;
	res = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		res = 10 * res - '0' + *str++;
	if (!*str)
		return (res * sign);
	g_error = 2;
	return (0);
}
