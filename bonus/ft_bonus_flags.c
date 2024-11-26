/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:08:54 by asajed            #+#    #+#             */
/*   Updated: 2024/11/26 22:57:53 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n)
{
	int	j;

	j = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	ft_padding(const char *str, int *i, va_list lst)
{
	int	len;
	int	num;
	int	count;
    int pr;

	len = 0;
    pr = 0;
	while (str[(*i)] == '.' && str[(*i)])
		(*i)++;
	while (ft_isdigit(str[(*i)]))
	{
		len = len * 10 + (str[(*i)] - '0');
		(*i)++;
	}
	num = va_arg(lst, int);
	count = ft_len(num);
    if (num < 0)
    {
        num = -num;
        pr += ft_putchar('-');
    }
    while (len > count)
	{
		ft_putchar('0');
		count++;
        pr++;
	}
    pr += ft_putnbr(num);
	return (pr);
}


int ft_givesign(const char *str, int *i, va_list lst, char c)
{
    int n;
    
    if (!(str[(*i)]))
        return (-1);
    while ((str[(*i)] == ' ' || str[(*i)] == '+'))
    {
        if (str[(*i)] == '+' && c == ' ')
            c = '+';
        (*i)++;
    }
    while (str[(*i)] != 'd' && str[(*i)])
        (*i)++;
    if (str[(*i)] == 'd' || str[(*i)] == 'i')
    {
        n = va_arg(lst, int);
        if (n < 0)
            return (ft_putnbr(n));
        else
            return (ft_putchar(c) + ft_putnbr(n));
    }
    return (check_argprint(str[(*i)++], lst));
}

int ft_hash(const char *str, int *i, va_list lst)
{
    while (str[(*i)] == '#')
        (*i)++;
    if (str[(*i)] == 'x')
        return ((ft_address(va_arg(lst, unsigned long), "0123456789abcdef")));
    else if (str[(*i)] == 'X')
        return ((ft_address(va_arg(lst, unsigned long), "0123456789ABCDEF")));
    return (check_argprint(str[(*i)], lst));
}

int bonus_flags(const char *str, va_list lst, int *i)
{
    if (str[(*i)] == '-')
        return (ft_addnum(str, i, lst, ' '));
    else if (str[(*i)] == '+')
        return (ft_givesign(str, i, lst, '+'));
    else if (str[(*i)] == ' ')
        return (ft_givesign(str, i, lst, ' '));
    else if (str[(*i)] == '#')
        return (ft_hash(str, i, lst));
    else if (str[(*i)] == '.' || str[(*i)] == '0')
        return (ft_padding(str, i, lst));
    return (-1);
}
