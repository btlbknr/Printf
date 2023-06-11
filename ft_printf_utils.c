/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbakaner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:33:54 by fbakaner          #+#    #+#             */
/*   Updated: 2023/01/28 17:34:08 by fbakaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_print_number(int x)
{
	long long	n;
	int			len;

	n = x;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = n * -1;
	}
	if (n < 10)
		len += ft_print_char(n + 48);
	else
	{
		len += ft_print_number(n / 10);
		len += ft_print_number(n % 10);
	}
	return (len);
}

int	ft_print_base(const char *base, unsigned int number)
{
	unsigned int	base_len;
	int				len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	len = 0;
	if (number < base_len)
		len += ft_print_char(base[number % base_len]);
	else
	{
		len += ft_print_base(base, number / base_len);
		len += ft_print_char(base[number % base_len]);
	}
	return (len);
}

int	ft_print_address(unsigned long long address, int instance)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (address == 0)
	{
		len += ft_print_str("0x0");
		return (len);
	}
	if (instance == 0)
		len += ft_print_str("0x");
	if (address < 16)
		len += ft_print_char(hex[address % 16]);
	else
	{
		len += ft_print_address(address / 16, instance + 1);
		len += ft_print_char(hex[address % 16]);
	}
	return (len);
}
