/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:15:38 by asajed            #+#    #+#             */
/*   Updated: 2024/11/24 22:05:42 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_base(unsigned long nbr, char *base)
{
	char			c;
	int				result;

	result = 0;
	if (nbr >= 16)
		result += ft_base(nbr / 16, base);
	c = base[nbr % 16];
	result += write(1, &c, 1);
	return (result);
}

int	ft_address(void *str)
{
	unsigned long	address;

	if (!str)
		return (write(1, "(nil)", 5));
	address = (unsigned long)str;
	write(1, "0x", 2);
	return (ft_base(address, "0123456789abcdef") + 2);
}
