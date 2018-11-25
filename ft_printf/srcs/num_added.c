/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_added.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:46:34 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/17 12:46:37 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_itoa_base(unsigned long long n, int base, char *res, int type)
{
	int 	len;

	len = 0;
	g_dot--;
	if (n >= (unsigned long long)base || (g_is_dot && len < g_dot))
		len += ft_itoa_base(n / base, base, res, type);
	res[len++] = g_alpha[type][n % base];
	res[len] = '\0';
	return (len);
}

char		*ft_itoa_base_u(unsigned long long n, int base, int *len, int type)
{
	char	*res;

	res = (char *)malloc(sizeof(unsigned long long) * 8 + 1);
	if (n == 0 && g_is_dot && g_dot <= 0)
	{
		res[0] = '\0';
		*len = 0;
		return (res);
	}	
	*len = ft_itoa_base(n, base, res, type);
	g_dot = 0;
	return (res);
}

char		*ft_itoa_base_s(long long n, int base, int *len, int type)
{
	char 				*res;
	unsigned long long 	nb;

	res = (char *)malloc(sizeof(long long) * 8 + 2);
	*len = 0;
	if (n == 0 && g_is_dot && g_dot <= 0)
	{
		res[0] = '\0' + (g_opts >> ('+' - ' ') & 1) * '+';
		res[1] = '\0';
		(*len) += (g_opts >> ('+' - ' ') & 1);
		return (res);
	}
	if (n < 0)
	{
		res[(*len)++] = '-';
		nb = -n;
	}
	else
	{
		nb = n;
		res[(*len)++] = '+';
	}
	(*len) += ft_itoa_base(nb, base, res + *len, type);
	g_dot = 0;
	return (res);
}




static long double 	rounding(long double n) //always positive
{
    int 				index;
    long double 		fract;
    long double 		res;
    long double 		nb;

    res = n;
    index = g_dot;
    fract = 1.0;
    nb = n - (unsigned long long)n;
    while (index-- > 0)
    {
        fract /= 10.0;
        nb *= 10.0;
        nb -= (unsigned long long)nb;
    }
    
    if ((int)(nb * 10) > 4)
        res += fract;

    return (res);
}


char		*ft_itoa_floatting(long double n, int *len, char *precision)  //check and correct
{
	char	*res;
	int 	index;
	int 	dot;

	res = (char *)malloc(sizeof(unsigned long long) * 8 + 2);
	*len = 0;
	if (n < 0)
	{
		res[(*len)++] = '-';
		n = -n;
	}
	else
		res[(*len)++] = '+';
	n = rounding(n);
	dot =g_dot;
	(*len) += ft_itoa_base((unsigned long long)n, 10, res + *len, 1);
	g_dot = dot;
	index = 0;
	n = n - (unsigned long long)n;
	while (index < g_dot)
	{
		n *= 10.0;
		precision[index++] = (int)n + '0';
		n -= (int)n;
	}
	precision[index] = '\0';
	return (res);
}

