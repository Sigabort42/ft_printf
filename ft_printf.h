/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:33:04 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/16 10:01:37 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

typedef union	u_var_nb
{
	char		c;
	short		sh;
	int			i;
	double		d;
	float		f;
	char		str[8];
	long		l;
	void		*ptr;
}				t_uvar_nb;

enum
{
	TYPE_CHAR,
	TYPE_WCHAR,
	TYPE_SHORT,
	TYPE_SHORT_MAJ,
	TYPE_INT,
	TYPE_OCTAL,
	TYPE_OCTAL_MAJ,
	TYPE_UNSIGNED,
	TYPE_UNSIGNED_MAJ,
	TYPE_HEXA,
	TYPE_HEXA_MAJ,
	TYPE_ADDRESS,
	TYPE_STRING,
	TYPE_WSTRING,
	TYPE_LONG,
	TYPE_DOUBLE,
	TYPE_FLOAT,
};

typedef struct	s_var
{
	char		*res;
	char		buf[2000];
	char		flags_stock[100];
	char		flags_conv[15];// = "cCdDioOuUxXpsS";
	int			ret;
	int			i_buf;
	int			i_stock;
	t_uvar_nb	nb;
	int			type;
}				t_var;

int		ft_is_number(int nb);
char	*ft_itoa_base(int value, int base);
void	ft_type(t_var *var, char c);
int		ft_stock_flags(char *str, t_var *var);
int		ft_printf(const char *format, ...);

#endif
