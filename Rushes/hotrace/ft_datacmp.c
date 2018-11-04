/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datacmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:02:42 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/03 22:06:52 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_datacmp(t_data *data1, t_data *data2)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = data1->key;
	s2 = data2->key;
	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((t_byte)s1[i] - (t_byte)s2[i]);
}
