/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 18:19:15 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/20 20:36:36 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uputnbr_base(unsigned int nb, char *base)
{
	unsigned int	u;
	int				i;
	unsigned int	base_len;

	u = nb;
	i = 1;
	base_len = ft_strlen(base);
	while (nb >= base_len)
	{
		nb /= base_len;
		i++;
	}
	nb = u;
	if (nb >= base_len)
		ft_uputnbr_base(nb / base_len, base);
	ft_putchar_fd(base[nb % base_len], 1);
	return (i);
}

static int	ft_pointer_putnbr(unsigned long nb, char *base)
{
	unsigned long	m;
	int				i;

	m = nb;
	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	nb = m;
	if (nb >= 16)
		ft_pointer_putnbr(nb / 16, base);
	ft_putchar_fd(base[nb % 16], 1);
	return (i);
}

static int	ft_putnbr_base(int nb, char *base)
{
	long	n;
	long	p;
	int		i;

	n = nb;
	i = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		i++;
	}
	p = n;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	n = p;
	if (n >= 10)
		ft_putnbr_base(n / 10, base);
	ft_putchar_fd(base[n % 10], 1);
	return (i);
}

static int	ft_pointer_handler(va_list args)
{
	unsigned long	p1;
	int				i;

	i = 0;
	p1 = va_arg(args, unsigned long);
	if (!p1)
	{
		ft_putstr_fd("(nil)", 1);
		i += 5;
	}
	else
	{
		i += 2;
		ft_putstr_fd("0x", 1);
		i += ft_pointer_putnbr(p1, "0123456789abcdef");
	}
	return (i);
}

int	ft_printf_num(va_list args, char c)
{
	int		i;

	i = 0;
	if (c == 'p')
		i += ft_pointer_handler(args);
	if (c == 'x')
		i += ft_uputnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		i += ft_uputnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == 'i' || c == 'd')
		i += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		i += ft_uputnbr_base(va_arg(args, unsigned int), "0123456789");
	return (i);
}
