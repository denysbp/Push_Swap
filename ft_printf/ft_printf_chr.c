/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 11:11:59 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/20 20:39:03 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_helpme(char const *s)
{
	int	i;

	ft_putchar_fd(*s, 1);
	i = 1;
	return (i);
}

int	ft_printf_chr(va_list args, char c)
{
	char	*p1;

	if (c == 's')
	{
		p1 = va_arg(args, char *);
		if (!p1)
			p1 = "(null)";
		ft_putstr_fd(p1, 1);
		return (ft_strlen(p1));
	}
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
	return (1);
}
