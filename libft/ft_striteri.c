/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:15:38 by deferrei          #+#    #+#             */
/*   Updated: 2026/04/14 20:10:10 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void test_func2(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
    (void)i;
}
int main()
{
	char str2[] = "aaaaa";
    ft_striteri(str2, test_func2);
	printf("%s", str2);
}*/