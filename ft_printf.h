/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbakaner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:34:18 by fbakaner          #+#    #+#             */
/*   Updated: 2023/01/28 17:34:27 by fbakaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_address(unsigned long long address, int instance);
int	ft_print_number(int x);
int	ft_print_base(const char *base, unsigned int number);
int	ft_format(char c, va_list args);
int	ft_printf(const char *str, ...);

#endif
