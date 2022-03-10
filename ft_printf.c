/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:48:56 by fech-cha          #+#    #+#             */
/*   Updated: 2021/12/24 22:48:58 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_printf(const char *str , ...)
{
    va_list format;
    int count;

    count = 0;
    va_start(format, str);
    while (*str != '\0')
    {
        if (*str == '%')
        {
            str++;
            if (*str == '%')
                count += ft_putchar('%');
            else if (*str == 'c')
                count += ft_putchar(va_arg(format,int));
            else if (*str == 'd' || *str == 'i')
                count += ft_putnbr(va_arg(format,int));
            else if (*str == 's')
                count += ft_putstr(va_arg(format, char *));
            else if (*str == 'u')
                count += ft_print_unsigned(va_arg(format, unsigned int));
            else if (*str == 'x')
                count += ft_print_lower_hexa(va_arg(format, long unsigned int));
            else if (*str == 'X')
                count += ft_print_upper_hexa(va_arg(format, unsigned int));
            else if (*str == 'p')
                count += ft_print_addrs(va_arg(format, long unsigned int));
            else 
                count += ft_putchar(*str);
        }
        else
            count += ft_putchar(*str);
        str++;
    }
    va_end(format);
    return (count);
}