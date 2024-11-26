/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:32:24 by asajed            #+#    #+#             */
/*   Updated: 2024/11/25 23:08:53 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	char			c;
	unsigned long	nb;
	int				result;

	nb = nbr;
	result = 0;
	if (nb >= 16)
		result += ft_putnbr_base(nb / 16, base);
	c = base[nb % 16];
	result += write(1, &c, 1);
	return (result);
}
