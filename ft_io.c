/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 22:34:57 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-11-17 22:34:57 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	unsigned long long	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static	char	*ft_symbole_case(char letter_case)
{
	if (letter_case == 'U')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

int	ft_putnbr_base(long n, int base, char letter_case)
{
	long	count;
	char	*symbole;

	symbole = ft_symbole_case(letter_case);
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		return (ft_putnbr_base(-n, base, letter_case) + 1);
	}
	else if (n < base)
	{
		return (write(1, &symbole[n], 1));
	}
	else
	{
		count = ft_putnbr_base(n / base, base, letter_case);
		if (count == -1)
			return (-1);
		return (count + ft_putnbr_base(n % base, base, letter_case));
	}
}

int	ft_put_uns_int(unsigned int n)
{
	size_t	count;

	if (n < 10)
		return (ft_putchar(n + 48));
	else
	{
		count = ft_put_uns_int(n / 10);
		return (count + ft_put_uns_int(n % 10));
	}
}
