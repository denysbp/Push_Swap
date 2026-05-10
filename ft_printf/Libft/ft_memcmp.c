/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:57:11 by pecoelho          #+#    #+#             */
/*   Updated: 2026/03/27 09:57:12 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p;
	const unsigned char	*s;
	size_t				i;

	p = (const unsigned char *)s1;
	s = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p[i] != s[i])
			return (p[i] - s[i]);
		i++;
	}
	return (0);
}
