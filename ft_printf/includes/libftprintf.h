/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:53:53 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/24 19:55:37 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//delete
# include <stdio.h>

int		ft_strchr_or(const char *s, int c);
void	func_init(void);
void	clean_flags(void);
int		ft_atoi_simple(const char *str);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);

int		check_mask(const char *format);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base_s(long long n, int base, int *len, int type);
char	*ft_itoa_base_u(unsigned long long n, int base, int *len, int type);
int		format(char	*str_org, int len, char *precision);
char	*ft_itoa_floatting(long double n, int *len, char *precision);

int		ft_c(va_list args);
int		ft_s(va_list args);
int		ft_p(va_list args);
int		ft_d_i(va_list args);
int		ft_o_u_x_X(va_list args);
int		ft_f(va_list args);
int		ft_q(va_list args);
int		error_alarm(char c);
/*
typedef union
{
	double			value;
	struct
	{
		uint32_t	lsw;
		uint32_t	msw;
	}				parts;
	uint64_t		word;
}					ieee_double_shape_type;
*/

int		g_opts;
int		g_minlen;
int		g_dot;
char	g_is_dot;
char	g_flag;
char	g_type;

int		g_total_len;
int		g_fd;

char	g_alpha[2][17];
int		(*g_funcs[27])(va_list);

#endif
