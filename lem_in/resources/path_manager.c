/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:45:52 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/16 19:45:53 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		build_path(t_list **path, t_graph *where)
{
	if (where->from != NULL)
	{
		ft_lstadd(path, ft_lstnew_link(where, 1));
		build_path(path, where->from);
	}
}

static int		identic_paths(void *list_content, void *content)
{
	t_list	*path1;
	t_list	*path2;

	path1 = (t_list *)(list_content);
	path2 = (t_list *)content;
	while (path1 && path2 && path1->content == path2->content)
	{
		path1 = path1->next;
		path2 = path2->next;
	}
	return (!path1 && !path2);
}

void			detect_paths(t_graph *where, int is_reverse)
{
	t_list	*path;
	t_list	*where_node;
	int		len;

	if (g_error != 0 || !where)
		return ;
	where_node = where->neighs;
	while (where_node != NULL)
	{
		path = NULL;
		build_path(&path, (t_graph *)where_node->content);
		if (is_reverse)
			path = ft_lst_reverse(path);
		len = ft_lstlen(path);
		if (path != NULL &&
			ft_lstfind(g_all_paths, path, identic_paths) == NULL)
		{
			g_total_path_len++;
			ft_lstadd(&g_all_paths, ft_lstnew_link(path, len));
		}
		else
			ft_lstdel(&path, NULL);
		where_node = where_node->next;
	}
}
