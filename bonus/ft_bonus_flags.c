/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:08:54 by asajed            #+#    #+#             */
/*   Updated: 2024/11/28 21:07:01 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hash(const char *str, int *i, va_list lst)
{
	unsigned int	l;

	l = va_arg(lst, unsigned long long);
	while (str[(*i)] == '#')
		(*i)++;
	if (!l)
		return (ft_putchar('0'));
	if (str[(*i)] == 'x')
		return ((write(1, "0x", 2) + ft_putnbr_base(l, "0123456789abcdef")));
	else if (str[(*i)] == 'X')
		return ((write(1, "0X", 2) + ft_putnbr_base(l, "0123456789ABCDEF")));
	return (check_argprint(str[(*i)], lst, str, i));
}

int	bonus_flags(const char *str, va_list lst, int *i)
{
	if (str[(*i)] == '-')
		return (ft_addnum(str, i, lst));
	else if (str[(*i)] == '+' || str[(*i)] == ' ')
		return (ft_givesign(str, i, lst, str[(*i)]));
	else if (str[(*i)] == '#')
		return (ft_hash(str, i, lst));
	else if (str[(*i)] == '.' || str[(*i)] == '0')
		return (ft_padding(str, i, lst, str[*i]));
	else if (ft_isdigit(str[(*i)]))
		return (ft_spaces(str, i, lst));
	return (-1);
}
