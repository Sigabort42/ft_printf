/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:11:51 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/15 16:20:12 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	t_uvar_nb	nb;

	nb.c = 'r';
	nb.sh = 12;
	printf("%c, %d\n", nb.c, nb.sh);
	nb.c = 'r';
	printf("%c, %d\n", nb.c, nb.sh);
	return (0);
}
