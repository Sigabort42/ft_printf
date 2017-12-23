/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:33:04 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/22 16:40:26 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

typedef union		u_var_nb
{
	char			c;
	short			sh;
	unsigned int	u_i;
	int				i;
	double			d;
	float			f;
	char			str[8];
	long			l;
	unsigned long long		ll;
	void			*ptr;
}					t_uvar_nb;

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
	TYPE_MODULO,
	TYPE_LONG,
	TYPE_LONG_LONG,
	TYPE_DOUBLE,
	TYPE_FLOAT,
};

typedef struct	s_var
{
	char		*res;
	char		buf[2000];
	char		buf_tmp[1000];
	char		flags_stock[100];
	char		flags_conv[15];
	int			ret;
	int			i_buf;
	int			i_buf_tmp;;
	int			i_stock;
	t_uvar_nb	nb;
	int			type;
}				t_var;

typedef struct	s_flags
{
	char		c;
	int			largeur;
	int			precision;
	char		m;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_is_number(long long nb);
char	*ft_itoa_base(int value, int base);
char	*ft_ltoa_base(long value, int base);
char	*ft_lltoa_base(unsigned long long value, int base);
void	ft_type(t_var *var, char c);
int		ft_stock_flags(char *str, t_var *var);
void	ft_stock_ap(va_list ap, t_var *var);
char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_lltoa(unsigned long long n);
void	ft_print_buffer(t_var *var);
int		ft_flags(char *flags, t_flags *s_flags);
int		ft_print_flags_buffer(t_var *var, t_flags *s_flags);

#endif
