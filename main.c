/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:22:52 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/20 20:15:08 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
//	printf("\n%d\n", ft_printf("%ll #0s\n", "salut"));
//	printf("\n%d\n", ft_printf("%ll #0s\n", "toi"));
	printf("\n%d\n", ft_printf("%1.-563s\n", "2147483647"));
	printf("\n%d\n", printf("%1.-563s\n", "2147483647"));
	return (0);
}
