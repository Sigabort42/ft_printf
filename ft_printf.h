/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:33:04 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/28 12:26:42 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
#include <stdio.h>

typedef union		u_var_nb
{
	char			c;
	unsigned char	u_c;
	short			sh;
	unsigned short	u_sh;
	int				i;
	intmax_t	i_max;
	uintmax_t	ui_max;
	size_t		s_i;
	ssize_t		s_ui;
	unsigned int	u_i;
	char			str[8];
	long			l;
	unsigned long	u_l;
	long long	ll_i;
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
	TYPE_UNSIGNED,
	TYPE_UNSIGNED_MAJ,
	TYPE_OCTAL,
	TYPE_OCTAL_MAJ,
	TYPE_HEXA,
	TYPE_HEXA_MAJ,
	TYPE_ADDRESS,
	TYPE_STRING,
	TYPE_WSTRING,
	TYPE_MODULO,
	TYPE_LONG,
	TYPE_LONG_LONG,
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
	int		i_plus;
	int		i_moins;
}				t_var;

typedef struct	s_flags
{
	char		c;
	int			largeur;
	int			precision;
	char		m;
}				t_flags;

void		ft_print_bit(int c);
int		ft_printf(const char *format, ...);
int		ft_is_number(long long nb);
int		ft_is_number_u_long_long(unsigned long long nb);
char	*ft_itoa_base(int value, int base);
char	*ft_itoa_base_maj(int value, int base);
char	*ft_ltoa_base(long value, int base);
char	*ft_ltoa_base_maj(long value, int base);
char	*ft_lltoa_base(unsigned long long value, int base);
char	*ft_lltoa_base_maj(unsigned long long value, int base);
char	*ft_ui_maxtoa_base(uintmax_t value, int base);
char	*ft_ui_maxtoa_base_maj(uintmax_t value, int base);
void	ft_type(t_var *var, char c);
int		ft_stock_flags(char *str, t_var *var);
void	ft_stock_ap(va_list ap, t_var *var);
char	*ft_ltoa(long n);
char	*ft_stoa(ssize_t n);
char	*ft_lltoa(unsigned long long n);
char	*ft_lldtoa(long long n);
char	*ft_i_maxtoa(intmax_t n);
char	*ft_ui_maxtoa(uintmax_t n);
void	ft_print_buffer(t_var *var);
int		ft_flags(char *flags, t_flags *s_flags);
int		ft_print_flags_buffer(t_var *var, t_flags *s_flags);
void	ft_flags_stock(t_var *var, t_flags *s_flags, char *str_hexa);

#endif
