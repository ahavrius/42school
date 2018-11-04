/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:50:52 by ahavrius          #+#    #+#             */
/*   Updated: 2018/10/22 19:39:55 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = -1;
	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	while (++i + min < max)
		tab[i] = i + min;
	return (tab);
}
