/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_impportant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:54:25 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/08 18:54:38 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int                ft_verif_wildcard(t_flags *s_flags, char *flags, int *i, va_list ap)
{
	if (flags[*i] == '*' && flags[*i - 1] == '.')
	{
		s_flags->precision = va_arg(ap, int);
		if (s_flags->precision <= 0)
			s_flags->precision = 0;
		*i = *i + 1;
		return (1);
	}
	else if (flags[*i] == '*')
	{
		s_flags->largeur = va_arg(ap, int);
		if (s_flags->largeur < 0)
		{
			s_flags->largeur *= -1;
			s_flags->c = s_flags->c | (1 << 2);
		}
		*i = *i + 1;
		return (1);
	}
	return (0);
}
