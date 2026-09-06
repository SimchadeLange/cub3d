/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:43:05 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/02 20:43:59 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			counter;
	unsigned char	char_s1;
	unsigned char	char_s2;

	if (n == 0)
		return (0);
	counter = 0;
	while (counter < n)
	{
		char_s1 = (unsigned char)s1[counter];
		char_s2 = (unsigned char)s2[counter];
		if (char_s1 != char_s2)
			return (char_s1 - char_s2);
		if (char_s1 == '\0')
			return (0);
		counter++;
	}
	return (0);
}
