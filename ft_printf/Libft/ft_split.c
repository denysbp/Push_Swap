/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:14:22 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/20 09:52:58 by pecoelho         ###   ########.fr       */
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
// int	main(int ac, char **av)
// {
// 	if (ac != 3)
// 		return (1);
// 	char	sep = av[2][0];
// 	char	**p1 = ft_split(av[1], sep);
// 	int		i = 0;
// 	while (p1[i])
// 	{
// 		printf("%s\n", p1[i]);
// 		i++;
// 	}
// 	free_content(p1);
// 	return (0);
// }