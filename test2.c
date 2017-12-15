/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:11:51 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/15 18:08:11 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	t_uvar_nb	nb;

	nb.c = 'r';
	ft_bzero(nb.str, 8);
	nb.sh = 12;
	printf("%c, %d\n", nb.c, nb.sh);
	printf("sizeof :%lu\n", sizeof(long long));
	nb.c = 'a';
	nb.str[0] = 'b';
	nb.str[1] = 'a';
	ft_bzero(nb.str, 8);
	printf("%c, %d\n", nb.sh);
	return (0);
}
