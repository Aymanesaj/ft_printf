/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:08:54 by asajed            #+#    #+#             */
/*   Updated: 2024/11/25 22:20:37 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
void    ft_add(int len, char c)
{
    while (len > 0)
    {
        ft_putchar(c);
        len--;
    }
}
int ft_num(const char *str, int *i)
{
    int len;

    len = 0;
    while (ft_isdigit(str[*i]))
    {
        len = len * 10 + (str[*i] - '0');
        (*i)++;
    }
    return (len);
}

int ft_addnum(const char *str, int *i, va_list lst, char c)
{
    int len;
    int count;

    len = 0;
    while (ft_isdigit(str[*i]))
    {
        len = len * 10 + (str[*i] - '0');
        (*i)++;
    }
    count = check_argprint(str[(*i)], lst);
    if (count < len)
    {
        while (count < len)
            count += ft_putchar(c);
        return (len);
    printf("\n[[[[len : %d]]]]\n",len);
    }
    return (count);
}


int bonus_flags(const char *str, va_list lst, int *i)
{
    int len;

    len = 0;
    if (str[(*i)] == '-')
    {
        (*i)++;
        len = ft_addnum(str, i, lst, ' ');
    }
    return (len);
}
