/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 10:27:48 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/27 10:27:49 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

static void		get_map(int row)
{
	char	*line;
	char	**split;
	int		i;

	skip(1);
	i = -1;
	g_real_board = (char **)malloc(row * sizeof(char *));
	while (++i < row)
	{
		get_next_line(0, &line);
		split = ft_strsplit(line, ' ');
		g_real_board[i] = split[1];
		free(split[0]);
		free(split);
		free(line);
	}
}

static	char	*read_name(char *line)
{
	char	*split;
	char	i;

	split = ft_strrchr(line, '/');
	i = (split == NULL) ? 0 : split - line + 1;
	line[ft_strlen(line) - 7] = '\0';
	return (ft_strdup(line + i));
}

static void		read_header(void)
{
	char	*line;

	skip(5);
	get_next_line(0, &line);
	g_player1 = read_name(line + 9);
	free(line);
	skip(1);
	get_next_line(0, &line);
	g_player2 = read_name(line + 9);
	free(line);
	skip(1);
}

void			get_and_print(t_data *data)
{
	t_window	window;
	char		*line;
	int			i;
	int			j;

	window.width = 1000 + 2 * MARGIN;
	window.height = 1000 + MARGIN + FOOTER;
	if (!g_player1)
		read_header();
	get_next_line(0, &line);
	if (line[0] == '=')
		g_terminate = 1;
	else if (line[1] == 'i')
	{
		get_first_line(&i, &j, &line);
		skip(i + 1);
	}
	else
	{
		get_first_line(&g_row, &g_col, &line);
		get_map(g_row);
		display(data, &window);
		del_map(g_real_board, g_row);
	}
}
