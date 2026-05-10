/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:58:22 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/01 13:12:25 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*seen;

	seen = NULL;
	while (*s)
	{
		if (*s == (char)c)
			seen = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	else
		return (seen);
}
