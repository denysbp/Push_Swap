/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:02 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 16:16:54 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t Bytes)
{
	const unsigned char	*ps;
	unsigned char		*pd;

	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	if (pd == ps || Bytes == 0)
		return (dest);
	if (pd < ps)
	{
		while (Bytes--)
		{
			*pd++ = *ps++;
		}
	}
	else
	{
		pd += Bytes;
		ps += Bytes;
		while (Bytes--)
		{
			*--pd = *--ps;
		}
	}
	return (dest);
}

/* int main()
{
	char idk[] = "denysr";
	char Idk[] = "bonfim";

	ft_memmove(idk, Idk, 6);
	printf("%s", idk);
} */