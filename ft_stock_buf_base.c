#include "ft_printf.h"

static int			ft_stock_buf_base2(t_var *var, t_flags *s_flags, int res_strcmp)
{
	int				i;

	i = 0;
	if ((s_flags->c & (1 << 4)) && (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ)
		&& res_strcmp && !s_flags->precision)
    {
		i = 1;
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0", i);
		var->i_buf_tmp += i;
    }

	return (i);
}

int					ft_stock_buf_base(t_var *var, t_flags *s_flags, int res_strcmp, int len_str_hexa)
{
	int				i;

	i = 0;
	if (!res_strcmp && len_str_hexa == 1 && s_flags->m == 0 && s_flags->c >= 2 &&
		s_flags->c <= 16 && (!var->i_buf || (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ)))
	{
		if (var->i_plus)
			var->buf[var->i_buf++] = '+';
		if (((!ft_strchr(var->flags_stock, '.') && !s_flags->precision) || (ft_strchr(var->flags_stock, '.') && s_flags->precision)) || (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ))
		  var->buf[var->i_buf++] = '0';
	}
	else if (((s_flags->c & (1 << 4)) && (var->type >= TYPE_HEXA && var->type <= TYPE_HEXA_MAJ)
		&& res_strcmp) || var->type == TYPE_ADDRESS)
	{
		i = 2;
		if ((var->type == TYPE_HEXA && len_str_hexa) || var->type == TYPE_ADDRESS)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0x", i);
			var->i_buf_tmp += i;
		}
		else if (var->type == TYPE_HEXA_MAJ && len_str_hexa)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0X", i);
			var->i_buf_tmp += i;
		}
	}
	else
		i = ft_stock_buf_base2(var, s_flags, res_strcmp);
	return (i);
}
