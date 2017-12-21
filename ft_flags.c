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

static void	ft_verif_modificateur(char *mod, t_flags *s_flags)
{
	s_flags->m = 0;
	if (!ft_strcmp(mod, "hh"))
		s_flags->m = s_flags->m | (1 << 0);
	if (!ft_strcmp(mod, "h"))
		s_flags->c = s_flags->c | (1 << 1);
	if (!ft_strcmp(mod, "l"))
		s_flags->m = s_flags->m | (1 << 2);
	if (!ft_strcmp(mod, "ll"))
		s_flags->m = s_flags->m | (1 << 3);
	if (!ft_strcmp(mod, "j"))
		s_flags->m = s_flags->m | (1 << 4);
	if (!ft_strcmp(mod, "z"))
		s_flags->m = s_flags->m | (1 << 5);
}

int		ft_flags(char *flags)
{
	t_flags		s_flags;
	int		i;

	i = 0;
	s_flags.c = 0;
	if (flags[0] == 0)
		return (0);
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
	i += ft_is_number(ft_atoi(&flags[i + 1]));
	ft_verif_modificateur(&flags[i + 1], &s_flags);
	return (1);
}
