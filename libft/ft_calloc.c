/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:13:40 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 12:36:42 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*pbr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
	{
		return (NULL);
	}
	total = nmemb * size;
	pbr = malloc(total);
	if (!pbr)
	{
		return (NULL);
	}
	ft_memset(pbr, 0, total);
	return (pbr);
}

/*int main()
{
	int numItems = 15;
	int *myArray = calloc(numItems, sizeof(int));

	for(int i = 0; i < numItems; i++) {
		myArray[i] = i + 1;
	}

	for(int i = 0; i < numItems; i++) {
		printf("%d ", myArray[i]);
	}

	free(myArray);
	myArray = NULL;

	return 0;
}*/