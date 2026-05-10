/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecoelho <pecoelho@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:43:45 by pecoelho          #+#    #+#             */
/*   Updated: 2026/04/20 20:43:53 by pecoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "Libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_printf_chr(va_list args, char c);
int	ft_printf_num(va_list args, char c);
int	ft_helpme(char const *s);

#endif