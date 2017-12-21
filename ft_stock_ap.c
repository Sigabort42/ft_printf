/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_ap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:16:39 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 14:41:03 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"


static void	ft_stock_ap2(va_list ap, t_var *var)
{
	if (var->type == TYPE_ADDRESS)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_STRING)
		var->res = va_arg(ap, char *);
	else if (var->type == TYPE_WSTRING)
		var->res = va_arg(ap, char *);
	else if (var->type == TYPE_MODULO)
		var->nb.c = '%';
	else if (var->type == TYPE_LONG)
		var->nb.l = va_arg(ap, long);
	else if (var->type == TYPE_LONG_LONG)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_DOUBLE)
		var->nb.d = va_arg(ap, double);
	else if (var->type == TYPE_FLOAT)
		var->nb.f = va_arg(ap, double);
}

void	ft_stock_ap(va_list ap, t_var *var)
{
	if (var->type == TYPE_CHAR)
		var->nb.c = va_arg(ap, int);
	else if (var->type == TYPE_WCHAR)
		var->nb.c = va_arg(ap, int);
	else if (var->type == TYPE_SHORT)
		var->nb.i = va_arg(ap, int);
	else if (var->type == TYPE_SHORT_MAJ)
		var->nb.i = va_arg(ap, int);
	else if (var->type == TYPE_INT)
		var->nb.i = va_arg(ap, int);
	else if (var->type == TYPE_OCTAL)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_OCTAL_MAJ)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_UNSIGNED)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_UNSIGNED_MAJ)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_UNSIGNED_MAJ)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_HEXA)
		var->nb.ll = va_arg(ap, long long);
	else if (var->type == TYPE_HEXA_MAJ)
		var->nb.ll = va_arg(ap, long long);
	else
		ft_stock_ap2(ap, var);
}
