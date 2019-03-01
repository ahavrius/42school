/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:53:19 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/15 14:53:19 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	delete_everything(void)
{
	t_list	*list;

	ft_lstdel(&g_all_nodes, graph_del_node);
	list = g_input;
	while (list)
	{
		free(list->content);
		g_input = list->next;
		free(list);
		list = g_input;
	}
}

static void	error_print(int flag)
{
	if (!flag && g_error > 0)
		write(1, "ERROR\n", 6);
	else if (g_error == 2)
		write(1, "ERROR: positive number required\n", 32);
	else if (g_error == 3)
		write(1, "ERROR: forbidden prefix L or empty line\n", 40);
	else if (g_error == 4)
		write(1, "ERROR: file has not found\n", 26);
	else if (g_error == 5)
		write(1, "ERROR: invalid format\n", 22);
	else if (g_error == 6)
		write(1, "ERROR: node doublicating\n", 25);
	else if (g_error == 7)
		write(1, "ERROR: unknown vertax\n", 22);
	else if (g_error == 8)
		write(1, "ERROR: vertax required\n", 23);
	else if (g_error == 9)
		write(1, "ERROR: different names required\n", 32);
	else if (g_error == 10)
		write(1, "ERROR: start/end has not found\n", 31);
	else if (g_error == 11)
		write(1, "ERROR: path has not found\n", 26);
	delete_everything();
}

static void	write_input(t_list *l_line)
{
	char	*line;

	line = (char *)l_line->content;
	if (line)
		ft_printf("%s\n", line);
}

int			main(int argc, char const *argv[])
{
	int step;

	main_read();
	step = is_special_case() * 20;
	while (g_error == 0 && step++ < 20)
	{
		main_bfs(g_start_node, g_end_node);
		main_bfs(g_end_node, g_start_node);
	}
	if (g_error == 0 && !(argc == 2 && ft_strcmp(argv[1], "--not_print") == 0))
	{
		g_input = ft_lst_reverse(g_input);
		ft_lstiter(g_input, write_input);
		ft_printf("\n");
	}
	if (!is_special_case())
	{
		main_efficiency();
		main_print();
	}
	else
		main_special();
	error_print((argc > 1 && !ft_strcmp(argv[1], "--error")));
	return (0);
}
