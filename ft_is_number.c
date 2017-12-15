/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:45:10 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/13 16:53:39 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_number(int nb)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}