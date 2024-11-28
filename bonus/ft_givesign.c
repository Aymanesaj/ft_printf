/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_givesign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:38:09 by asajed            #+#    #+#             */
/*   Updated: 2024/11/28 01:22:39 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_givesign(const char *str, int *i, va_list lst, char c)
{
	int	n;

	while ((str[(*i)] == ' ' || str[(*i)] == '+'))
	{
		if (str[(*i)] == '+' && c == ' ')
			c = '+';
		(*i)++;
	}
	if (str[(*i)] == 'd' || str[(*i)] == 'i')
	{
		n = va_arg(lst, int);
		if (n < 0)
			return (ft_putnbr(n));
		else
			return (ft_putchar(c) + ft_putnbr(n));
	}
	return (check_argprint(str[(*i)], lst, str, i));
}
