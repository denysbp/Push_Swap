/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:05 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/17 22:35:01 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memset() function takes three arguments:
dest, ch and count. The character represented by ch
is first converted to unsigned char and then copies
it into the first count characters of the object pointed to by dest.*/

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned char	*ps;
	size_t			i;

	ps = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		ps[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}

/* int main()
{
	char array[] = "denys";

	ft_memset(array, '0', 6);
	printf("%s", array);
} */