/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficiency.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:31:58 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/17 20:32:00 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		do_paths_crossed(t_list *p1, t_list *p2)
{
	t_list	*present_node;
	int		flag;

	flag = 0;
	present_node = p2;
	while (p1 && present_node && !flag)
	{
		p2 = present_node;
		while (p2 && !flag && p1->content != p2->content)
			p2 = p2->next;
		flag = p2 != NULL;
		p1 = p1->next;
	}
	return (flag);
}

static void		find_all_crossed_paths(t_list *l_current_path)
{
	t_list		*current;
	int			counter;

	counter = l_current_path->content_size;
	current = (t_list *)l_current_path->content;
	l_current_path = l_current_path->next;
	while (l_current_path != NULL)
	{
		if (do_paths_crossed(current, (t_list *)l_current_path->content))
			ft_lstadd(&g_table_crossed[counter],
				ft_lstnew_link((t_list *)l_current_path->content,
					l_current_path->content_size));
		l_current_path = l_current_path->next;
	}
}

static int		cmp_path(t_list *l_p1, t_list *l_p2)
{
	if (!l_p1 || !l_p2)
		return (-1);
	return (l_p1->content_size <= l_p2->content_size);
}

static void		assign_number_len_tables(t_list *l_path)
{
	static int counter;

	g_table_lens[counter] = l_path->content_size;
	g_table_visit[counter] = 1;
	l_path->content_size = counter;
	counter++;
}

void			main_efficiency(void)
{
	if (g_error > 0)
		return ;
	g_min_effic = INT_MAX;
	g_all_paths = ft_lstsort(g_all_paths, cmp_path);
	g_table_crossed = (t_list **)ft_memalloc(sizeof(t_list *) *
		g_total_path_len);
	g_table_lens = (int *)malloc(sizeof(int) * g_total_path_len);
	g_table_visit = (char *)malloc(sizeof(char) * g_total_path_len);
	ft_lstiter(g_all_paths, assign_number_len_tables);
	ft_lstiter(g_all_paths, find_all_crossed_paths);
	main_rec();
}
