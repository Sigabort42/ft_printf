/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:47:50 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 15:59:26 by elbenkri         ###   ########.fr       */
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
	char	c;
	int		i;

	i = 0;
	c = 0;
	if (flags[0] == 0)
		return (0);
	var->res = var->res;
	printf("flags :%s\n", flags);
	while (flags[i] && (!(flags[i] >= '1' && flags[i] <= '9')))
	{
		if (flags[i] == '0')
			c = c | (1 << 0);
		if (flags[i] == '+')
			c = c | (1 << 1);
		if (flags[i] == '-')
			c = c | (1 << 2);
		if (flags[i] == ' ')
			c = c | (1 << 3);
		if (flags[i] == '#')
			c = c | (1 << 4);
		i++;
	}
	printf("flags :%d\n", ft_atoi(&flags[i]));
//	ft_print_bit(c);
	return (1);
}
