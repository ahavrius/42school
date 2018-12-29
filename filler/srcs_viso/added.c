/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:34:55 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/28 15:35:01 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

void	get_first_line(int *row, int *col, char **line)
{
	char	**split;

	split = ft_strsplit(*line, ' ');
	free(*line);
	*line = NULL;
	*row = ft_atoi(split[1]);
	*col = ft_atoi(split[2]);
	del_map(split, 4);
}

void	del_map(char **map, int row)
{
	int		i;

	i = -1;
	while (++i < row)
		if (map[i] != NULL)
			free(map[i]);
	free(map);
	map = NULL;
}
