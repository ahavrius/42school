/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linlist_push_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:58:00 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/13 18:58:01 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	linlist_push_tail(t_linlist **alst, t_linlist *new)
{
	if (!alst || !new)
		return ;
	new->prev = *alst;
	new->next = NULL;
	(*alst)->next = new;
	*alst = new;
}
