/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:48:56 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/22 21:52:23 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inlcude/fdf_bonus.h"

int	ft_testing(char arge, va_list format)
{
	int	count;

	count = 0;
	if (arge == '%')
		count += ft_putchar('%');
	else if (arge == 'c')
		count += ft_putchar(va_arg(format, int));
	else if (arge == 'd' || arge == 'i')
		count += ft_putnbr(va_arg(format, int));
	else if (arge == 's')
		count += ft_putstr(va_arg(format, char *));
	else if (arge == 'u')
		count += ft_print_unsigned(va_arg(format, unsigned int));
	else if (arge == 'x')
		count += ft_print_lower_hexa(va_arg(format, unsigned int));
	else if (arge == 'X')
		count += ft_print_upper_hexa(va_arg(format, unsigned int));
	else if (arge == 'p')
	{
		count += ft_putstr("0x");
		count += ft_print_addrs(va_arg(format, long unsigned int));
	}
	else
		count += ft_putchar(arge);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	format;
	int		count;

	count = 0;
	va_start(format, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_testing(*str, format);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(format);
	return (count);
}
