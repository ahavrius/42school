/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:33:18 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/13 20:33:19 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph		*graph_new_el(char *name, int x, int y)
{
	t_graph	*new_graph;

	if (!name || !(new_graph = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	new_graph->name = ft_strdup(name);
	if (new_graph->name == NULL)
	{
		free(new_graph);
		return (NULL);
	}
	new_graph->coord_x = x;
	new_graph->coord_y = y;
	new_graph->neighs = NULL;
	new_graph->dist = INT_MAX;
	new_graph->visited = 0;
	new_graph->from = NULL;
	return (new_graph);
}

int			graph_cmp(void *g1, void *line)
{
	if (g1 == NULL || line == NULL)
		return (0);
	return (!ft_strcmp(((t_graph *)g1)->name, (char *)line));
}

void		graph_del_el(void *el, size_t len)
{
	t_graph		*elem;

	elem = (t_graph *)el + 0 * len;
	if (elem)
	{
		free(elem->name);
		free(elem);
	}
}

void		define_link(char *name1, char *name2)
{
	t_list		*node1;
	t_list		*node2;

	g_error = 9 * !ft_strcmp(name1, name2);
	if (g_error == 0)
	{
		node1 = ft_lstfind(g_all_nodes, name1, graph_cmp);
		node2 = ft_lstfind(g_all_nodes, name2, graph_cmp);
		g_error = 7 * (node1 == NULL || node2 == NULL);
	}
	if (g_error == 0)
	{
		ft_lstadd(&(((t_graph *)node1->content)->neighs),
			ft_lstnew_link((t_graph *)node2->content, 8));
		ft_lstadd(&(((t_graph *)node2->content)->neighs),
			ft_lstnew_link((t_graph *)node1->content, 8));
	}
}
