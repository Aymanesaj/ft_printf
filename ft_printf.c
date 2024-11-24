/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:57:30 by asajed            #+#    #+#             */
/*   Updated: 2024/11/24 01:13:23 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int check_argprint(char c, va_list lst)
{
    if (c == 'c')
        return (ft_putchar((char)va_arg(lst, int)));
    if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(lst, int)));
    if (c == 'u')
        return (ft_numsizet(va_arg(lst, size_t)));
    if (c == 's')
        return (ft_putstr(va_arg(lst, char *)));
    if (c == '%')
        return (ft_putchar('%'));
    if (c == 'x')
        return (ft_putnbr_base(va_arg(lst, unsigned int), "0123456789abcdef"));
    if (c == 'X')
        return (ft_putnbr_base(va_arg(lst, unsigned int), "0123456789ABCDEF"));
    return (0);
}

int ft_printf(const char *str, ...)
{
    va_list lst;
    int     result;
    int     j;
    int     i;

    result = 0;
    i = 0;
    j = 0;
    va_start(lst, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == '\0')
                return (-1);
            j = check_argprint(str[i], lst);
            if ((j <= 0))
                return (-1);
            else
                result = result + j;
        }
        else
            result += ft_putchar(str[i]);
        i++;
    }
    va_end(lst);
    return (result);
}