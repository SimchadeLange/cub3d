/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_etc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-roo <ede-roo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:05:18 by ede-roo           #+#    #+#             */
/*   Updated: 2025/09/29 21:07:02 by ede-roo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_signed(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ft_buffer_filling('-');
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_putnbr_signed(nb / 10);
	count += ft_putchar_p(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	c = n % 10 + 48;
	count++;
	ft_buffer_filling(c);
	return (count);
}

int	ft_puthexa_long(unsigned long n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexa_long(n / 16, base);
	ft_putchar_p(base[n % 16]);
	return (++count);
}

int	ft_puthexa_int(unsigned int n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexa_int(n / 16, base);
	ft_putchar_p(base[n % 16]);
	return (++count);
}
