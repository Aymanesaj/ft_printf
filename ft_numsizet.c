/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsizet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:15:09 by asajed            #+#    #+#             */
/*   Updated: 2024/11/24 02:15:11 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_numsizet(size_t n)
{
	char	c;
	int		result;

	result = 0;
	if ((n / 10) > 0)
		result += ft_putnbr((n / 10));
	c = (n % 10) + '0';
	result += write(1, &c, 1);
	return (result);
}
