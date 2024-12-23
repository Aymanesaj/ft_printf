/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:57:30 by asajed            #+#    #+#             */
/*   Updated: 2024/11/26 21:12:23 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_argprint1(char c, va_list lst, int *result)
{
	if (c == 'c')
		return ((*result += ft_putchar((char)va_arg(lst, int))));
	if (c == 'd' || c == 'i')
		return ((*result += ft_putnbr(va_arg(lst, int))));
	if (c == 'u')
		return ((*result += ft_unsign(va_arg(lst, size_t))));
	if (c == 's')
		return ((*result += ft_putstr(va_arg(lst, char *))));
	if (c == '%')
		return ((*result += ft_putchar('%')));
	if (c == 'p')
		return ((*result += ft_address(va_arg(lst, unsigned long))));
	if (c == 'x')
		return ((*result += ft_putnbr_base(va_arg(lst, unsigned int)
					, "0123456789abcdef")));
	if (c == 'X')
		return ((*result += ft_putnbr_base(va_arg(lst, unsigned int)
					, "0123456789ABCDEF")));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		result;
	int		i;

	result = 0;
	i = 0;
	va_start(lst, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if ((str[i] == '\0') || (check_argprint1(str[i], lst, &result)) < 0)
				return (-1);
		}
		else
			result += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (result);
}
