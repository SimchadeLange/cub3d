/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:34:09 by side-lan          #+#    #+#             */
/*   Updated: 2025/06/02 20:45:26 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				counter;
	unsigned char	_char;

	_char = (unsigned char)c;
	counter = ft_strlen(str);
	if (_char == '\0')
		return ((char *)str + counter);
	while (counter >= 0)
	{
		counter--;
		if (str[counter] == _char)
			return ((char *)str + counter);
	}
	return (NULL);
}
