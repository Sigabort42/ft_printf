/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:56:05 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/15 15:56:26 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_itoa_base(int value, int base);

int	main()
{
//	char	*ok = "salut";
	printf("salut|%x\n", 107);
	printf("salut|%hhd\n", 107);
//	printf("0x10%s\n", ft_itoa_base(174849, 16));
/*	printf("4567 |%-10]5d| plip\n", 12);
    printf("4567 |%10]5d| plip\n", 12);
    printf("|%10.5d|\n", -12);
    printf("|%10d|\n", -12);
    printf("|%010d|\n", -12); 
    printf("|%-10.5d|\n", -12);
    printf("|%-010.5d|\n", -12);
*/	return (0);
}
