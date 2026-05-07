/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:07:19 by deferrei          #+#    #+#             */
/*   Updated: 2026/05/07 17:01:21 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	validate_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_numbers(argv[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}
