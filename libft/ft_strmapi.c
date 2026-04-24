/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:58 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 20:09:35 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*copia;
	unsigned int	i;

	if (!s)
	{
		return (NULL);
	}
	copia = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copia)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		copia[i] = f(i, s[i]);
		i++;
	}
	copia[i] = '\0';
	return (copia);
}

/*char test_func(unsigned int i, char c)
{
    return c + i;
}
int main()
{
	char *str1 = "aaaaa";
    char *res = ft_strmapi(str1, test_func);
	printf("%s", res);
}*/