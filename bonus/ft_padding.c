/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:35:41 by asajed            #+#    #+#             */
/*   Updated: 2024/11/28 23:00:21 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handlex(va_list lst, int len, const char *str, int *i)
{
	va_list	sec;
	int		printed;
	int		count;

	printed = 0;
	va_copy(sec, lst);
	count = ft_strx(va_arg(sec, unsigned int));
	while (len > count)
	{
		printed += ft_putchar('0');
		count++;
	}
	va_end(sec);
	return (printed + check_argprint(str[(*i)], lst, str, i));
}

int	ft_handle_unsign(va_list lst, int len)
{
	unsigned int	num;
	int				count;
	int				printed;

	printed = 0;
	num = va_arg(lst, unsigned int);
	count = ft_lenu(num);
	while (len > count)
	{
		printed += ft_putchar('0');
		count++;
	}
	return ((printed + ft_unsign(num)));
}

int	ft_negative(int *count, int *sign, char c)
{
	if (c == '0')
		(*count)++;
	*sign = -1;
	return (ft_putchar('-'));
}

int	ft_handlenum(va_list lst, int len, char c, char ch)
{
	int	num;
	int	count;
	int	sign;
	int	printed;

	sign = 1;
	printed = 0;
	if (ch == 'u')
		return (ft_handle_unsign(lst, len));
	num = va_arg(lst, int);
	count = ft_len(num);
	if (num < 0)
		printed += ft_negative(&count, &sign, c);
	while (len > count)
	{
		printed += ft_putchar('0');
		count++;
	}
	if (num == -2147483648)
		return ((printed + ft_unsign(num * sign)));
	return (printed + ft_putnbr((num * sign)));
}

int	ft_padding(const char *str, int *i, va_list lst, char c)
{
	int	len;
	int	pr;

	len = 0;
	pr = 0;
	while ((str[(*i)] == '.' || str[(*i)] == '0') && str[(*i)])
	{
		if (c == '0' && str[*i] == '-')
			return (ft_addnum(str, i, lst));
		if (c == '0' && str[*i] == '.')
			c = '.';
		(*i)++;
	}
	len = ft_atoi(str, i);
	if (str[(*i)] == 'd' || str[(*i)] == 'i' || str[(*i)] == 'u')
	{
		pr = ft_handlenum(lst, len, c, str[(*i)]);
		return (pr);
	}
	if (str[(*i)] == 's' && c == '.')
		return (ft_handlestr(lst, len));
	if (str[(*i)] == 'x' || str[(*i)] == 'X')
		return (ft_handlex(lst, len, str, i));
	return (check_argprint(str[(*i)], lst, str, i));
}
