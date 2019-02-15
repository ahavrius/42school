/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:31:16 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/14 14:31:17 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	skip_comments(char **input)
{
	int		len;

	*input = NULL;
	if (g_error == 0)
	{
		len = get_next_line(0, input);
		while (len > 0 && *input &&
			(((*input)[0] == '#' && (*input)[1] != '#')
				||
				((*input)[0] == '#' && (*input)[1] == '#'
			&& ft_strcmp(*input, "##start") && ft_strcmp(*input, "##end"))))
		{
			free(*input);
			*input = NULL;
			len = get_next_line(0, input);
		}
		g_error = 4 * (len < 0) + 5 * (*input == NULL && len > 0);
	}
	return (g_error == 0 && len > 0);
}

static int	try_parse_node(char *input)
{
	char	**split;
	int		x;
	int		y;

	if (g_error || ft_strcountchr(input, ' ') != 2)
		return (0);
	split = ft_strsplit(input, ' ');
	x = atoi_correct(split[1]);
	y = atoi_correct(split[2]);
	if (g_error == 0)
	{
		if (ft_lstfind(g_all_nodes, split[0], graph_cmp) == NULL)
			ft_lstadd(&g_all_nodes,
				ft_lstnew_link(graph_new_el(split[0], x, y), 8));
		else
			g_error = 6;
	}
	ft_splitdel(split);
	return (!g_error);
}

static int	try_parse_link(char *input)
{
	char	**split;

	if (g_error || ft_strcountchr(input, '-') != 1)
		return (0);
	split = ft_strsplit(input, '-');
	define_link(split[0], split[1]);
	ft_splitdel(split);
	return (!g_error);
}

static void	parse_start_end(char *input)
{
	char	*input_2;

	if (ft_strcmp(input, "##start") && ft_strcmp(input, "##end"))
		return ;
	skip_comments(&input_2);
	if (try_parse_node(input_2) == 1 && g_error == 0)
	{
		g_start_node = (!ft_strcmp(input, "##start")) ?
						g_all_nodes->content : NULL;
		g_end_node = (!ft_strcmp(input, "##end")) ?
						g_all_nodes->content : NULL;
	}
	else
		g_error = 8;
	free(input_2);
}

void		main_read(void)
{
	char	*input;

	g_start_node = NULL;
	g_end_node = NULL;
	g_error = 0;
	skip_comments(&input);
	if (g_error == 0)
	{
		g_num_ants = atoi_correct(input);
		free(input);
	}
	while (skip_comments(&input) > 0 && g_error == 0)
	{
		if (input[0] == '\0' || input[0] == 'L')
			g_error = 3;
		else if (input[0] == '#' && input[1] == '#')
			parse_start_end(input);
		else if (try_parse_link(input) + try_parse_node(input) == 0)
			g_error = (g_error == 0) ? 5 : g_error;
		free(input);
	}
}
