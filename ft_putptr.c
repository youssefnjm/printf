/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-18 16:11:07 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-11-18 16:11:07 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_puthex(unsigned long long n)
{
	long	count;
	char	*symbole;

	symbole = "0123456789abcdef";
	if (n < 16)
	{
		count = write(1, &symbole[n], 1);
		if (count == -1)
			return (-1);
		return (1);
	}
	else
	{
		count = ft_puthex(n / 16);
		if (count == -1)
			return (-1);
		return (count + ft_puthex(n % 16));
	}
}

int	ft_put_address(void *ptr)
{
	unsigned long long	adress;
	int					count;
	int					hex_count;

	adress = (unsigned long long)ptr;
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	hex_count = ft_puthex(adress);
	if (hex_count == -1)
		return (-1);
	return (hex_count + count);
}
