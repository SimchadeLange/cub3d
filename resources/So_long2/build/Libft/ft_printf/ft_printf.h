/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:05:20 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/23 21:05:22 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

int	ft_printf(const char *fmt, ...);
int	make_str(long n);
int	make_unstr(unsigned long n);
int	putstr(char *str);
int	count_digits(long n);
int	print_hex(unsigned int num, int capital);
int	check_point(uintptr_t pointer);

#endif
