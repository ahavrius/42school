/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:12:30 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/17 13:12:32 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_d_i(va_list args)
{
	long long int 	n;
	char			*str;
	int				len;

	len = 0;
	if (g_flag == 'h')
		n = (short int)va_arg(args, int);
	else if (g_flag == 'l')
		n = va_arg(args, long int);
	else if (g_flag == 'l' / 2)
		n = va_arg(args, long long int);
	else if (g_flag == 'h' / 2)
		n = (signed char)va_arg(args, int);
	else
		n = va_arg(args, int);
	str = ft_itoa_base_s(n, 10, &len, 0);
	return (format(str, len, NULL));
}

int 	ft_o_u_x_X(va_list args)
{
	unsigned long long 	n;
	char			*str;
	int				len;

	len = 0;
	str = NULL;
	if (g_flag == 'h')
		n = (unsigned short int)va_arg(args, unsigned int);
	else if (g_flag == 'l')
		n = va_arg(args, unsigned long int);
	else if (g_flag == 'l' / 2)
		n = va_arg(args, unsigned long long int);
	else if (g_flag == 'h' / 2)
		n = (unsigned char)va_arg(args, unsigned int);
	else
		n = va_arg(args, unsigned int);
	if (g_type == 'X')
		str = ft_itoa_base_u(n, 16, &len, 1);
	else if (g_type == 'x')
		str = ft_itoa_base_u(n, 16, &len, 0);
	else if (g_type == 'o')
		str = ft_itoa_base_u(n, 8, &len, 0);
	else if (g_type == 'u')
		str = ft_itoa_base_u(n, 10, &len, 0);
	return (format(str, len, NULL));
}
/*
	else
		str = ft_itoa_base_u(n, 2, &len, 0);
*/
int 	ft_f(va_list args)
{
	long double	n;
	char 		*dec;
	char 		*dot;
	int 		len;

	g_dot = (!g_is_dot) ? 6 : g_dot;
	dot = (char *)malloc(g_dot + 2); 
	len = 0;
	if (g_flag == 'L' )
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	dec = ft_itoa_floatting(n, &len, dot + 1);
	if ((g_opts >> ('#' - ' ') & 1) || g_dot != 0)
	{
		dot[0] = '.';
		g_dot++;
	}
	else if (g_dot == 0)
		dot[0] = '\0';
	return (format(dec, len, dot));
}