/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:00:31 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/05 08:21:09 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nb;

	nb = n;
	len = ft_malloc_size(n);
	if (len == 0)
		return (ft_strdup(""));
	if (nb == 0)
		return (ft_strdup("0"));
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
