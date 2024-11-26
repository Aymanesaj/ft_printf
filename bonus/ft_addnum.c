/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:07:22 by asajed            #+#    #+#             */
/*   Updated: 2024/11/26 21:19:12 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_addnum(const char *str, int *i, va_list lst, char c)
{
    long len;
    int count;

    len = 0;
    while (str[(*i)] == '-' && str[(*i)])
        (*i)++;
    while (ft_isdigit(str[*i]))
    {
        len = len * 10 + (str[(*i)] - '0');
        (*i)++;
    }
    if (len > 2147483647)
        return (-1);
    count = check_argprint(str[(*i)], lst);
    if (count < len)
    {
        while (count < len)
            count += ft_putchar(c);
        return (len);
    }
    return (count);
}
