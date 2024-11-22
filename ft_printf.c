/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 23:54:23 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-11-08 23:54:23 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_format(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (s == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
		count += ft_put_address(va_arg(ap, void *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr_base(va_arg(ap, int), 10, 'L');
	else if (s == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned int), 10, 'L');
	else if (s == 'x' || s == 'X')
	{
		if (s == 'x')
			count += ft_putnbr_base(va_arg(ap, unsigned int), 16, 'L');
		else
			count += ft_putnbr_base(va_arg(ap, unsigned int), 16, 'U');
	}
	else if (s == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(s);
	return (count);
}

static	int	ft_check(int ret, va_list ap)
{
	if (ret == -1)
	{
		va_end(ap);
		return (-1);
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int	count;
	int		ret;
	va_list	ap;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			ret = print_format(*(++str), ap);
		else
			ret = write(1, str, 1);
		if (ret == -1)
			return (ft_check(ret, ap));
		count += ret;
		str++;
	}
	va_end(ap);
	return (count);
}
