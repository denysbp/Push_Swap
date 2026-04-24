/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:13:35 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 12:20:31 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	int				i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char *)str;
	while (n != 0)
	{
		st[i] = '\0';
		n--;
		i++;
	}
}

/*int main()
{
	char str[10];

	ft_bzero(str, 10);
	str[0] = 'd';
	str[1] = 'e';
	str[4] = 'n';
	printf("%s",str);
}*/