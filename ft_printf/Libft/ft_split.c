/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deferrei <deferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:14:22 by pecoelho          #+#    #+#             */
/*   Updated: 2026/05/10 17:25:11 by deferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cwords(char const *s, char c)
{
	size_t	words;
	size_t	i;

	if (!s)
		return (0);
	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	*free_content(char **p)
{
	char	**res;

	res = p;
	while (*res)
		free(*res++);
	free(p);
	return (NULL);
}

static char	**split_helper(char **res, char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	wlen;

	i = 0;
	p = res;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			wlen = ft_wordlen(s, c);
			p[i] = ft_substr(s, 0, wlen);
			if (!p[i])
			{
				free_content(p);
				return (NULL);
			}
			i++;
			s += wlen;
		}
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = ft_calloc((ft_cwords(s, c) + 1), sizeof(char *));
	if (!p)
		return (NULL);
	return (split_helper(p, s, c));
}

// #include <stdio.h>
// int	main()
// {
// 	char	**p1 = ft_split("               ", ' ');
// 	int		i = 0;
// 	printf("tamanho: %ld", ft_strlen(p1[0]));
// 	free_content(p1);
// 	return (0);
// }