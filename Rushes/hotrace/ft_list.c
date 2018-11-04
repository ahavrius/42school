/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:10:16 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/03 22:11:07 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_lstnext(t_list *head)
{
	t_list	*old;

	if (!head)
		return (NULL);
	old = head->next;
	head->data = NULL;
	if (head->key)
		free(head->key);
	head->key = NULL;
	free(head);
	head = NULL;
	return (old);
}

t_list	*ft_lstnew(t_data *data, char *key)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->key = key;
	new->next = NULL;
	return (new);
}

void	ft_lstpush(t_data *data, char *key)
{
	t_list	*new;

	new = ft_lstnew(data, key);
	if (!new)
		return ;
	if (g_tail)
		g_tail->next = new;
	g_tail = new;
	if (!g_head)
		g_head = new;
}
