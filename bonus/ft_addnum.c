/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:07:22 by asajed            #+#    #+#             */
/*   Updated: 2024/11/28 00:30:22 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_addnum(const char *str, int *i, va_list lst)
{
	long	len;
	int		count;

	len = 0;
	while ((str[(*i)] == '-' || str[(*i)] == '0') && str[(*i)])
		(*i)++;
	len = (ft_atoi(str, i));
	if (len > 2147483647)
		return (-1);
	count = check_argprint(str[(*i)], lst, str, i);
	if (count < len)
	{
		while (count < len)
			count += ft_putchar(' ');
		return (len);
	}
	return (count);
}
