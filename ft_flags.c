/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:47:50 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 16:11:18 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_print_bit(int c)
{
	int		i;

	i = 8;
	while (i >= 0)
	{
		ft_putchar((!!(c & (1 << i))) + 48);
		i--;
	}
}

int		ft_flags(t_var *var, char *flags)
{
	t_flags	s_flags;
//	char	c;
	int		i;

	i = 0;
	s_flags.c = 0;
	if (flags[0] == 0)
		return (0);
	var->res = var->res;
	printf("flags :%s\n", flags);
	while (flags[i] && (!(flags[i] >= '1' && flags[i] <= '9')))
	{
		if (flags[i] == '0')
			s_flags.c = s_flags.c | (1 << 0);
		if (flags[i] == '+')
			s_flags.c = s_flags.c | (1 << 1);
		if (flags[i] == '-')
			s_flags.c = s_flags.c | (1 << 2);
		if (flags[i] == ' ')
			s_flags.c = s_flags.c | (1 << 3);
		if (flags[i] == '#')
			s_flags.c = s_flags.c | (1 << 4);
		i++;
	}
	s_flags.largeur = ft_atoi(&flags[i]);
	i += ft_is_number(ft_atoi(&flags[i]));
	s_flags.precision = (flags[i] == '.') ? ft_atoi(&flags[i + 1]) : 0;
	printf("flags 1:%d\n", s_flags.largeur);
	printf("flags 2:%d\n", s_flags.precision);
//	ft_print_bit(c);
	return (1);
}
