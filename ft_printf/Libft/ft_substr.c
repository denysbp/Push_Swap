/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:58:32 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/14 14:42:59 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	rlen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= (size_t)start)
		return (ft_strdup(""));
	rlen = (slen - start);
	if (rlen > len)
		rlen = len;
	sub = malloc(rlen + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, rlen);
	sub[rlen] = '\0';
	return (sub);
}
