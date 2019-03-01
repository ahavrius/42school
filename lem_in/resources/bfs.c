/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:00:40 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/16 14:00:40 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	make_bfs_step(t_linlist **list_head,
							t_linlist **list_tail, t_graph *end)
{
	t_graph	*taken;
	t_list	*l_node;
	t_graph	*node;

	taken = (t_graph *)linlist_pop_tail(list_tail, list_head);
	l_node = taken->neighs;
	while (l_node != NULL)
	{
		node = (t_graph *)(l_node->content);
		if (node->visited == 0 && taken != end)
		{
			node->visited = node != end;
			taken->visited += 1;
			node->from = taken;
			linlist_push_head(list_head, list_tail, linlist_new_link(node, 1));
		}
		l_node = l_node->next;
	}
}

static void	calculate_min_popular(t_list *elem)
{
	t_graph		*node;

	node = (t_graph *)elem->content;
	if (node != g_start_node && node != g_end_node && node->visited != INT_MAX)
		g_min_popular = (node->visited > g_min_popular)
						? node->visited : g_min_popular;
}

static void	clean_and_detect_popular(t_list *elem)
{
	t_graph		*node;

	node = (t_graph *)elem->content;
	node->from = NULL;
	if (g_min_popular <= MIN_VISITERS)
		node->visited = (node->visited == INT_MAX) ? node->visited : 0;
	else if (node != g_start_node && node->visited >= g_min_popular)
	{
		node->detected++;
		node->visited = INT_MAX * (node->detected >= 2);
		g_min_popular = g_min_popular * (node->detected <= 2);
	}
	else
		node->visited = 0;
}

void		main_bfs(t_graph *start, t_graph *end)
{
	t_linlist	*list_head;
	t_linlist	*list_tail;

	list_head = NULL;
	list_tail = NULL;
	g_min_popular = 0;
	if (start == NULL || end == NULL)
		g_error = 10;
	if (g_error != 0)
		return ;
	linlist_push_head(&list_head, &list_tail, linlist_new_link(start, 1));
	while (!linlist_is_emply(list_head))
		make_bfs_step(&list_head, &list_tail, end);
	detect_paths(end, start != g_start_node);
	ft_lstiter(g_all_nodes, calculate_min_popular);
	ft_lstiter(g_all_nodes, clean_and_detect_popular);
	g_error = (g_error > 0) ? g_error : 11 * (g_total_path_len == 0);
}
