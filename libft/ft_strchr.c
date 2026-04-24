/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:31 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/17 22:42:32 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The strchr() function takes two arguments:
	str and ch. It searches for the character
	ch in the string pointed to by str*/

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((char)ch == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

/* int main()
{
	char *string = ft_strchr("TRALALERO TRALALA", 'L');
	printf("%s", string);
} */