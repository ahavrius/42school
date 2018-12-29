/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:00:26 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/22 16:00:27 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_first_line(int *row, int *col)
{
	char	**split;
	char	*line;

	g_terminate = (get_next_line(0, &line) > 0);
	if (g_terminate == 0)
		return ;
	split = ft_strsplit(line, ' ');
	free(line);
	*row = ft_atoi(split[1]);
	*col = ft_atoi(split[2]);
	del_map(split, 4);
}

void	del_map(char **map, int row)
{
	int		i;

	i = -1;
	while (++i < row)
		if (map[i])
			free(map[i]);
	free(map);
	map = NULL;
}

void	get_map(void)
{
	char	*line;
	char	**split;
	int		i;

	get_next_line(0, &line);
	free(line);
	i = (g_row) ? -1 : 0;
	g_real_board = (char **)malloc(g_row * sizeof(char *));
	while (++i < g_row)
	{
		get_next_line(0, &line);
		split = ft_strsplit(line, ' ');
		g_real_board[i] = split[1];
		free(split[0]);
		free(split);
		free(line);
	}
}

void	get_player(void)
{
	char *line;

	if (get_next_line(0, &line) == -1)
		exit(0);
	g_player = line[10] - '0';
	free(line);
}

void	get_token(void)
{
	int		i;

	get_first_line(&g_row_token, &g_col_token);
	g_token = (char **)malloc(sizeof(char *) * g_row_token);
	i = -1;
	while (++i < g_row_token)
		get_next_line(0, &g_token[i]);
}
