/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:44:18 by asajed            #+#    #+#             */
/*   Updated: 2024/11/26 21:07:13 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_unsign(unsigned int n);
int	ft_address(unsigned long address, char *base);
int bonus_flags(const char *str, va_list lst, int *i);
int	check_argprint(char c, va_list lst);
int ft_addnum(const char *str, int *i, va_list lst, char c);
int	ft_isdigit(int c);
#endif
