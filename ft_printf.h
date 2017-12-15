/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:33:04 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/15 18:38:22 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>

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
	TYPE_SHORT,
	TYPE_INT,
	TYPE_DOUBLE,
	TYPE_FLOAT,
	TYPE_STRING,
	TYPE_LONG,
	TYPE_ADDRESS	
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


#endif
