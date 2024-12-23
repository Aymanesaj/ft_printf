/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asajed <asajed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:44:18 by asajed            #+#    #+#             */
/*   Updated: 2024/11/25 22:15:47 by asajed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(const char *s);
int	ft_putnbr(int n);
int	ft_printf(const char *str, ...);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_unsign(unsigned int n);
int	ft_address(unsigned long str);
int bonus_flags(const char *str, va_list lst, int *i);
int	check_argprint1(char c, va_list lst, int *result);
int	check_argprint(char c, va_list lst);

#endif
