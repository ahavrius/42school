/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:15:58 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/26 15:20:00 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"
#include <stdio.h>

int	 main(int ac, char **av)
{
	char *c;

	printf("ac  %d \n", ac);
	get_next_line(0, &c);
	printf("line %s\n", c);
	return (0);
}
