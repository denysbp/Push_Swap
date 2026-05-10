/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:51:38 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/08 10:51:39 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*p1;
	size_t		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	p1 = malloc(len + 1);
	if (!p1)
		return (NULL);
	ft_memcpy(p1, str, len);
	p1[len] = '\0';
	return (p1);
}
