/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:01:40 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/03 22:20:26 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		*ft_rewrite(char *c, char c_new, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(size + 2);
	if (!str)
		return (NULL);
	while (c && *c && i < size)
	{
		str[i] = c[i];
		i++;
	}
	str[i++] = c_new;
	str[i++] = '\0';
	if (c)
		free(c);
	return (str);
}

static void		ft_init(t_btree *tab[], int size)
{
	int		i;

	i = 0;
	while (i <= size)
		tab[i++] = NULL;
}

static char		*ft_readln(char **line, int fd)
{
	char	*str;
	char	c;
	int		len;

	len = 0;
	str = NULL;
	while (read(fd, &c, 1) && c != '\n')
		str = ft_rewrite(str, c, len++);
	*line = str;
	return (str);
}

static	void	ft_tabdel(t_btree *tab[], int size)
{
	int		i;

	i = 0;
	while (i <= size)
		ft_free_tr(tab[i++]);
}

int				main(void)
{
	t_btree *tab[256];
	char	*key;
	char	*value;

	ft_init(tab, 255);
	key = NULL;
	value = NULL;
	while (ft_readln(&key, 0))
	{
		ft_readln(&value, 0);
		ft_addel(&tab[(int)(key[0])], ft_newdata(key, value), &ft_datacmp);
	}
	g_head = NULL;
	g_tail = NULL;
	while (ft_readln(&key, 0))
		ft_lstpush(ft_search(tab[(int)(key[0])], ft_newdata(key, NULL),
					&ft_datacmp), key);
	while (g_head)
	{
		ft_printres(g_head->data, g_head->key);
		g_head = ft_lstnext(g_head);
	}
	ft_tabdel(tab, 255);
	return (0);
}
