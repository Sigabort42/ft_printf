/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:11:51 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/21 14:44:04 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	t_uvar_nb	nb;

	nb.i = -12;
	ft_bzero(nb.str, 8);
	printf("%d\n", nb.sh);
	return (0);
}
