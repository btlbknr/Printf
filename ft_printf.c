/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbakaner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:33:29 by fbakaner          #+#    #+#             */
/*   Updated: 2023/01/28 17:33:43 by fbakaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_print_char(va_arg(args, int));
	else if (c == 's')
		length += ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		length += ft_print_number(va_arg(args, int));
	else if (c == 'u')
		length += ft_print_base("0123456789", va_arg(args, unsigned int));
	else if (c == 'x')
		length += ft_print_base("0123456789abcdef", va_arg(args, unsigned int));
	else if (c == 'X')
		length += ft_print_base("0123456789ABCDEF", va_arg(args, unsigned int));
	else if (c == 'p')
		length += ft_print_address(va_arg(args, unsigned long long), 0);
	if (c == '%')
		length += write(1, "%", 1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		a;
	va_list	args;

	len = 0;
	a = 0;
	va_start(args, str);
	while (str[a])
	{
		if (str[a] != '%')
			len += write(1, &str[a], 1);
		if (str[a] == '%')
		{
			len += ft_formats(str[a + 1], args);
			a++;
		}
		a++;
	}
	va_end(args);
	return (len);
}
